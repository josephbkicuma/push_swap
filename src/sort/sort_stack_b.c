/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 08:41:04 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/11 10:50:44 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_until_three(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;
	t_stack	*target_node;
	size_t	stack_size;
	int		i;

	stack_size = ft_list_size(stack_a);
	while (stack_size > 3)
	{
        set_target(stack_a, stack_b);
		cheapest = get_cheapest(stack_a, stack_b);
		target_node = get_target_adress(cheapest->target, stack_b);
		if (target_node->above_mid && cheapest->above_mid)
		{
			if (target_node->un_cost <= cheapest->un_cost)
			{
				i = target_node->un_cost;
				while (i--)
					rr(stack_a, stack_b);
				i = cheapest->un_cost - target_node->un_cost;
				while (i--)
					ra(stack_a);
			}
			else
			{
				i = cheapest->un_cost;
				while (i--)
					rr(stack_a, stack_b);
				i = target_node->un_cost - cheapest->un_cost;
				while (i--)
					rb(stack_b);
			}
		}
		else if (!target_node->above_mid && !cheapest->above_mid)
		{
			if (target_node->un_cost <= cheapest->un_cost)
			{
				i = target_node->un_cost;
				while (i--)
					rrr(stack_a, stack_b);
				i = cheapest->un_cost - target_node->un_cost;
				while (i--)
					rra(stack_a);
			}
			else
			{
				i = cheapest->un_cost;
				while (i--)
					rrr(stack_a, stack_b);
				i = target_node->un_cost - cheapest->un_cost;
				while (i--)
					rrb(stack_b);
			}
		}
		else if (!target_node->above_mid && cheapest->above_mid)
		{
			i = target_node->un_cost;
			while (i--)
			    rrb(stack_b);
			i = cheapest->un_cost;
			while (i--)
				ra(stack_a);
		}
		else if (target_node->above_mid && !cheapest->above_mid)
		{
			i = target_node->un_cost;
			while (i--)
			    rb(stack_b);
			i = cheapest->un_cost;
			while (i--)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		stack_size = ft_list_size(stack_a);
	}
}
