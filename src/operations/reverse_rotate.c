/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:22:46 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/08 18:10:58 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *second_last;

    last = (*stack);
    second_last = (*stack);
    while (last->next)
        last = last->next;
    while (second_last->next->next)
        second_last = second_last->next;
    last->next = *stack;
    second_last->next = NULL;
    *stack = last;
}

void    rra(t_stack **stack_a)
{
    if (!*stack_a || !(*stack_a)->next)
		return ;
    reverse_rotate(stack_a);
    ft_putstr_fd("rra\n", 1);
}

void    rrb(t_stack **stack_b)
{
    if (!*stack_b || !(*stack_b)->next)
		return ;
    reverse_rotate(stack_b);
    ft_putstr_fd("rrb\n", 1);
}

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    if (!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
		return ;
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_putstr_fd("rrr\n", 1);
}
