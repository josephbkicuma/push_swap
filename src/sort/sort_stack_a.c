/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:59:47 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/11 20:36:28 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stack	*smaller_value_stack(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*smaller;

	aux = *stack;
	smaller = *stack;
	while (aux->next)
	{
		if (aux->value > aux->next->value)
			smaller = aux->next;
		aux = aux->next;
	}
	return (smaller);
}

t_stack	*found_bigger_closest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_b_top;
	t_stack	*aux_a;
	bool	bigger;
	t_stack	*target;
	int		bigest_range;

	bigger = true;
	bigest_range = INT_MAX;
	set_target(stack_a, stack_b);
	stack_b_top = *stack_b;
	aux_a = *stack_a;
	while (aux_a)
	{
		if (aux_a->value > stack_b_top->value && (aux_a->value
				- stack_b_top->value) < bigest_range)
		{
			bigest_range = aux_a->value - stack_b_top->value;
			target = aux_a;
			bigger = false;
		}
		aux_a = aux_a->next;
	}
	if (bigger)
		return (smaller_value_stack(stack_a));
	return (target);
}

void    put_on_top(t_stack **stack_a, t_stack *value)
{
    int stack_size;
    int i;

    stack_size = ft_list_size(stack_a);
    if (value->above_mid)
    {
        i = value->index;
        while (i--)
            ra(stack_a);   
    }
    else
    {
        i = stack_size - value->index;
        while (i--)
            rra(stack_a);
    }
}

void	rotate_until_ordenate(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*value;

	aux = *stack;
	value = aux;
	while (aux->next)
	{
		if (aux->value > aux->next->value)
			value = aux->next;
		aux = aux->next;
	}
	set_target(stack, stack);
	put_on_top(stack, value);
}

void    push_stack_a_order(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *aux_b;
    t_stack *aux_a;
    
    aux_b = *stack_b;
    while (aux_b)
    {
        set_target(stack_a, stack_b);
        aux_a = found_bigger_closest(stack_a, stack_b);
        put_on_top(stack_a, aux_a);
        aux_b = aux_b->next;
        pa(stack_a, stack_b);
    }
	rotate_until_ordenate(stack_a);
}
