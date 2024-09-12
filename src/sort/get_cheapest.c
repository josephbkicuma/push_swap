/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:22:40 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/12 13:24:18 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*get_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*cheapest;

	cheapest = *stack_a;
	aux = *stack_a;
	calculate_coast(stack_a, stack_b);
	while (aux)
	{
		if (cheapest->cost > aux->cost)
			cheapest = aux;
		aux = aux->next;
	}
	return (cheapest);
}
