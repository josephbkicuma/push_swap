/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:02:58 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/12 13:13:29 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	verify_stack_order(t_stack *stack)
{
	t_stack	*aux;

	aux = stack;
	if (ft_list_size(&aux) == 2)
	{
		if (aux->value > aux->next->value)
		{
			sa(&aux);
			free_stack(&aux);
			exit(EXIT_SUCCESS);
		}
	}
	else if (ft_list_size(&aux) == 3)
		sort_three(&aux);
	while (stack->next)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return ;
	}
	free_stack(&aux);
	exit(EXIT_SUCCESS);
}

void	verify_duplicated_numbers(t_stack *stack)
{
	t_stack	*aux;
	t_stack	*compare;

	aux = stack;
	while (stack)
	{
		compare = aux;
		while (compare)
		{
			if (compare != stack && compare->value == stack->value)
				print_error(&aux, NULL, NULL);
			compare = compare->next;
		}
		stack = stack->next;
	}
}

size_t	ft_list_size(t_stack **stack)
{
	size_t	i;
	t_stack	*tmp;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	set_above_midle(t_stack **stack_a)
{
	t_stack	*aux;
	size_t	stack_size;
	size_t	stack_index;

	aux = *stack_a;
	stack_size = ft_list_size(stack_a);
	stack_index = 1;
	while (aux)
	{
		if (stack_index <= (stack_size / 2))
			aux->above_mid = true;
		else
			aux->above_mid = false;
		aux = aux->next;
		stack_index++;
	}
}

void	set_stack_index(t_stack **stack_a, t_stack **stack_b)
{
	size_t	index;
	t_stack	*aux;

	aux = *stack_a;
	index = 0;
	while (aux)
	{
		aux->index = index;
		index++;
		aux = aux->next;
	}
	aux = *stack_b;
	index = 0;
	while (aux)
	{
		aux->index = index;
		index++;
		aux = aux->next;
	}
}
