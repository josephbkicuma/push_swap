/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:30:28 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/13 13:37:05 by jquicuma         ###   ########.fr       */
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

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	aux = *stack_a;
	if (aux->next)
	{
		while (aux->next && aux->value < aux->next->value)
			aux = aux->next;
		if (aux->next == NULL)
			return ;
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	push_stack_a_order(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;

	aux = *stack_a;
	if (aux->next)
	{
		while (aux->next && aux->value < aux->next->value)
			aux = aux->next;
		if (aux->next == NULL)
			return ;
	}
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if ((*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
	sort_three(stack_a);
	push_stack_a_order(stack_a, stack_b);
}
