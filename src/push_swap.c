/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:27:53 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/10 12:43:36 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	***split_args(char **av, int ac);

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	***args;

	a = NULL;
	b = NULL;
	if (ac < 2)
		print_error(&a, &b, NULL);
	args = split_args(&av[1], ac);
	init_stack(&a, args);
    verify_stack_order(a);
	verify_duplicated_numbers(a);
	//sort_three(&a);
	pb(&a, &b);
	pb(&a, &b);
	set_target(&a, &b);
	printf("Stack A\n\n");
	for (t_stack *node = a; node; node = node->next)
		printf("valuer: %d || target: %ld || Above MID: %d\n", node->value, node->target, node->above_mid);
	printf("\n\nSTACK B\n\n");
	for (t_stack *node = b; node; node = node->next)
		printf("%d\n", node->value);
	free_stack(&a);
	free_stack(&b);
}
