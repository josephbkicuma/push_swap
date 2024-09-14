/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:27:40 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/14 14:25:10 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	printf("%s\n\n", get_next_line(0));
	printf("STACK_A\n");
	for (t_stack *node = a; node; node = node->next)
		printf("VALUE: %d\n", node->value);
	free_stack(&b);
    free_stack(&a);
}
