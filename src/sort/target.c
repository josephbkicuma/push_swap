/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:31:25 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/12 14:13:17 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*size_t	big_num_index(t_stack *a, t_stack **stack_b)
{
	t_stack	*tmp;
	size_t	i;
	size_t	j;
	int		big;

	tmp = *stack_b;
	big = tmp->value;
	i = 0;
	j = 0;
	while (tmp)
	{
		if (big < tmp->value)
		{
			if (i <= (ft_list_size(stack_b) / 2))
			{
				j = i;
				a->above_mid = true;
			}
			else
			{
				j = ft_list_size(stack_b) - i;
				a->above_mid = false;
			}
			big = tmp->value;
		}
		i++;
		tmp = tmp->next;
	}
	return (j);
}*/
static void	update_index_and_mid(t_stack *a, size_t i, size_t *j,
		size_t list_size)
{
	if (i <= (list_size / 2))
	{
		*j = i;
		a->above_mid = true;
	}
	else
	{
		*j = list_size - i;
		a->above_mid = false;
	}
}

size_t	big_num_index(t_stack *a, t_stack **stack_b)
{
	t_stack	*tmp;
	size_t	i;
	size_t	j;
	int		big;
	size_t	list_size;

	tmp = *stack_b;
	big = tmp->value;
	i = 0;
	j = 0;
	list_size = ft_list_size(stack_b);
	while (tmp)
	{
		if (big < tmp->value)
		{
			update_index_and_mid(a, i, &j, list_size);
			big = tmp->value;
		}
		i++;
		tmp = tmp->next;
	}
	return (j);
}

/*void	target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	size_t	i;
	int		j;
	bool	k;
	size_t	mid_point;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		i = 0;
		k = false;
		j = INT_MAX;
		tmp_b = *stack_b;
		while (tmp_b)
		{
			if (tmp_a->value > tmp_b->value && j > tmp_a->value - tmp_b->value)
			{
				j = tmp_a->value - tmp_b->value;
				k = true;
				if (i <= ft_list_size(stack_a) / 2)
				{
					tmp_a->target = i;
					tmp_a->above_mid = true;
				}
				else
				{
					tmp_a->target = ft_list_size(stack_a) - i;
					tmp_a->above_mid = false;
				}
			}
			i++;
			tmp_b = tmp_b->next;
		}
		if (!k)
			tmp_a->target = big_num_index(tmp_a, stack_b);
		tmp_a = tmp_a->next;
	}
}*/
void	update_target_and_mid_status(t_stack **stack_a, t_stack *tmp_a,
		size_t index)
{
	size_t	mid_point;

	mid_point = ft_list_size(stack_a) / 2;
	if (index <= mid_point)
	{
		tmp_a->target = index;
		tmp_a->above_mid = true;
	}
	else
	{
		tmp_a->target = ft_list_size(stack_a) - index;
		tmp_a->above_mid = false;
	}
}

void	process_stack_a_element(t_stack **stack_a, t_stack **stack_b,
		t_stack *tmp_a)
{
	t_stack	*tmp_b;
	size_t	i;
	int		j;
	bool	k;

	i = 0;
	k = false;
	j = INT_MAX;
	tmp_b = *stack_b;
	while (tmp_b)
	{
		if (tmp_a->value > tmp_b->value && j > tmp_a->value - tmp_b->value)
		{
			j = tmp_a->value - tmp_b->value;
			k = true;
			update_target_and_mid_status(stack_a, tmp_a, i);
		}
		i++;
		tmp_b = tmp_b->next;
	}
	if (!k)
		tmp_a->target = big_num_index(tmp_a, stack_b);
}

void	target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		process_stack_a_element(stack_a, stack_b, tmp_a);
		tmp_a = tmp_a->next;
	}
}
