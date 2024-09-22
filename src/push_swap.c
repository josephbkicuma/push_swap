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

static void	full_sort(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_until_three(stack_a, stack_b);
	sort_three(stack_a);
	push_stack_a_order(stack_a, stack_b);
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*aux;
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
	aux = a;
	if (aux == NULL)
		print_error(&a, &b, NULL);
	verify_duplicated_numbers(a);
	verify_stack_order(a, b);
	full_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
}
