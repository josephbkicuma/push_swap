/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:20:11 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/08 18:10:46 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *temp;

    last = *stack;
    temp = *stack;
    *stack = (*stack)->next;
    while (last->next)
        last = last->next;
    temp->next = NULL;
    last->next = temp;
}

void    ra(t_stack **stack_a)
{
    if (!*stack_a || !(*stack_a)->next)
		return ;
    rotate(stack_a);
    ft_putstr_fd("ra\n", 1);
}

void    rb(t_stack **stack_b)
{
    if (!*stack_b || !(*stack_b)->next)
		return ;
    rotate(stack_b);
    ft_putstr_fd("rb\n", 1);
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
    if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr_fd("rr\n", 1);
}
