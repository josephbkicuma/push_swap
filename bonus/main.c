/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:27:40 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/14 15:06:08 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	***args;
	t_stack	*aux;

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
		print_error(&a, &b, args);
	verify_duplicated_numbers(a);
	execute_order_on_stack(&a, &b);
	verify_stack_order(a, b);
	ft_putstr_fd("KO\n", 2);
	free_stack(&b);
	free_stack(&a);
	exit(EXIT_FAILURE);
}

static void	ordenate(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (ft_strcmp(str, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(stack_a, stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stack_a, stack_b);
}

void	execute_order_on_stack(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		ordenate(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
}
