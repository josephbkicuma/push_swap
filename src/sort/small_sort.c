/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:30:28 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/09 21:40:17 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*a;

	a = *stack_a;
	if (a->value > a->next->value && a->next->value < a->next->next->value
		&& a->value > a->next->next->value)
		ra(stack_a);
	else if (a->value > a->next->value && a->next->value > a->next->next->value)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (a->value > a->next->value && a->next->value < a->next->next->value
		&& a->value < a->next->next->value)
		sa(stack_a);
	else if (a->value < a->next->value && a->next->value > a->next->next->value
		&& a->value > a->next->next->value)
		rra(stack_a);
	else if (a->value < a->next->value && a->next->value > a->next->next->value
		&& a->value < a->next->next->value)
	{
		sa(stack_a);
		ra(stack_a);
	}
}
