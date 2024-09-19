/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:27:53 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/14 13:35:24 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	***args;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac < 2)
		print_error(&a, &b, NULL);
	if (!av[1][0])
		print_error(NULL, NULL, NULL);
	args = split_args(&av[1], ac);
	init_stack(&a, args);
	verify_duplicated_numbers(a);
	verify_stack_order(a, b);
	pb(&a, &b);
	pb(&a, &b);
	sort_until_three(&a, &b);
	sort_three(&a);
	push_stack_a_order(&a, &b);
	free_stack(&a);
	free_stack(&b);
}
