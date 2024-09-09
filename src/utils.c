/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:02:58 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/09 20:11:10 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	verify_stack_order(t_stack *stack)
{
    t_stack *aux;

    aux = stack;
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

void    verify_duplicated_numbers(t_stack *stack)
{
    t_stack *aux;
    t_stack *compare;

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
