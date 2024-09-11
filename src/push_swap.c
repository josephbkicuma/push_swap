/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:27:53 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/11 19:09:10 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	***split_args(char **av, int ac);

int	main(int ac, char *av1[])
{
	t_stack	*a;
	t_stack	*b;
	char	***args;

	a = NULL;
	b = NULL;
	char	*av[] = {"5 2 7 1 6 3 9 4 8", NULL};
	ac = 10;
	(void)av1;
	if (ac < 2)
		print_error(&a, &b, NULL);
	args = split_args(&av[0], ac);
	init_stack(&a, args);
	verify_stack_order(a);
	verify_duplicated_numbers(a);
	pb(&a, &b);
	pb(&a, &b);
	sort_until_three(&a, &b);
	sort_three(&a);
	push_stack_a_order(&a, &b);
	printf("Stack A\n\n");
	for (t_stack *node = a; node; node = node->next)
		printf("%ld - valuer: %d || target: %ld || Above MID: %d || COST: %d || UNI: %d\n", node->index,
			node->value, node->target, node->above_mid, node->cost, node->un_cost);
	printf("\n\nSTACK B\n\n");
	for (t_stack *node = b; node; node = node->next)
		printf("%ld - %d | ABOVE MID: %d || Cost: %d || UN: %d\n", node->index, node->value, node->above_mid, node->cost, node->un_cost);
	free_stack(&a);
	free_stack(&b);
}
