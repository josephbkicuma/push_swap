/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:31:26 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/08 11:48:01 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	***split_args(char **av, int ac)
{
	size_t	i;
	char	***argsv;

	argsv = malloc(sizeof(char **) * (ac + 1));
	if (!argsv)
		return (NULL);
	i = 0;
	while (av[i])
	{
		argsv[i] = ft_split(av[i], ' ');
		i++;
	}
	argsv[i] = NULL;
	return (argsv);
}

t_stack	*lst_add_end(t_stack **stack, int value)
{
	t_stack	*aux;
	t_stack	*new_node;

	aux = *stack;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->value = value;
    if (!(*stack))
    {
        (*stack) = new_node;
        return (new_node);
    }
	while ((*stack)->next)
		(*stack) = (*stack)->next;
	(*stack)->next = new_node;
    (*stack) = aux;
	return (new_node);
}

static bool	is_all_int(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	init_stack(t_stack **stack_a, char ***args)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!is_all_int(args[i][j]))
				return (0);
			num = ft_atol(args[i][j]);
			if (num >= INT_MAX || num <= INT_MIN)
				return (0);
			if (!lst_add_end(stack_a, num))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
