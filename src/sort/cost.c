/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:02:13 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/10 17:07:52 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stack	*get_target_adress(size_t index_target, t_stack **stack_b)
{
	t_stack	*aux;

	aux = *stack_b;
	while (aux)
	{
		if (index_target == aux->index)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}

static int	set_cost_below(t_stack **stack, int stack_size)
{
	t_stack	*aux;
	int		cost;

	aux = *stack;
	cost = (stack_size - aux->index);
	return (cost);
}

void	calculate_coast(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*target_node;
	int		stack_a_size;
	int		stack_b_size;

	aux = *stack_a;
	stack_a_size = ft_list_size(stack_a);
	stack_b_size = ft_list_size(stack_b);
	while (aux)
	{
		target_node = get_target_adress(aux->target, stack_b);
		if (target_node->above_mid && aux->above_mid)
		{
			if (target_node->index >= aux->index)
				aux->cost = target_node->index;
			else
				aux->cost = aux->index;
		}
		else if (!target_node->above_mid && !aux->above_mid)
		{
			if (set_cost_below(&target_node,
					stack_b_size) > set_cost_below(&aux, stack_a_size))
				aux->cost = set_cost_below(&target_node, stack_b_size);
			else
				aux->cost = set_cost_below(&aux, stack_a_size);
		}
		else if (!target_node->above_mid && aux->above_mid)
			aux->cost = aux->index + set_cost_below(&target_node, stack_b_size);
        else if (target_node->above_mid && !aux->above_mid)
            aux->cost = target_node->index + set_cost_below(&aux, stack_a_size);
		aux = aux->next;
	}
}
