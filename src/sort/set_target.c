/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 01:52:06 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/11 17:42:43 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static bool	is_biggest_num(int num, t_stack *stack)
{
	while (stack)
	{
		if (num < stack->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static size_t	found_bigger_index(t_stack **stack_a)
{
	t_stack	*aux;
	t_stack	*temp;
	size_t	bigger_index;

	aux = *stack_a;
	bigger_index = 0;
	while (aux)
	{
		temp = *stack_a;
		if (is_biggest_num(aux->value, temp))
			return (bigger_index);
		aux = aux->next;
        bigger_index++;
	}
	return (-1);
}

static size_t	found_index(int value, t_stack **stack_b)
{
	t_stack	*aux;
	int		num_target_atual;
	int		i;
	size_t	target_index;
	bool	is_smallest;

	aux = *stack_b;
	num_target_atual = INT_MAX;
	i = 0;
	target_index = 0;
	is_smallest = true;
	while (aux)
	{
		if (value > aux->value && (value - aux->value) < num_target_atual)
		{
			target_index = (size_t)i;
			num_target_atual = value - aux->value;
			is_smallest = false;
		}
		aux = aux->next;
		i++;
	}
	if (is_smallest)
		target_index = found_bigger_index(stack_b);
	return (target_index);
}

void	set_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;

	set_stack_index(stack_a, stack_b); //certo
	set_above_midle(stack_a);
	set_above_midle(stack_b);
	temp_a = *stack_a;
	while (temp_a)
	{
		temp_a->target = found_index(temp_a->value, stack_b);
		temp_a = temp_a->next;
	}
}
