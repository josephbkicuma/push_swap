/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:20:11 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/08 17:17:19 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *temp;

    if (!*stack || !(*stack)->next)
        return ;
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
    rotate(stack_a);
    ft_putstr_fd("ra\n", 1);
}

void    rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_putstr_fd("rb\n", 1);
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr_fd("rr\n", 1);
}
