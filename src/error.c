/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:05:38 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/08 18:18:32 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(t_stack **stack_a, t_stack **stack_b, char ***args)
{
	if (args)
		free_matrix(args);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
