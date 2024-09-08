/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:25:57 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/08 18:17:20 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack **icoming, t_stack **receipt)
{
	t_stack	*aux;

	aux = *icoming;
	*icoming = (*icoming)->next;
	aux->next = *receipt;
	*receipt = aux;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
		return ;
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
