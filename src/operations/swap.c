/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:49:07 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/08 18:08:29 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = (*stack)->next;
	first->next = first->next->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}
void	sb(t_stack **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return ;
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
