/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:52:48 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/14 13:44:26 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_matrix(char ***matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free_arr(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_exit_sucess(t_stack **stack)
{
	free_stack(stack);
	exit(EXIT_SUCCESS);
}
