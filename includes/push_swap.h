/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:13:33 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/10 13:09:09 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	size_t			target;
	size_t			index;
	bool			above_mid;
	struct s_stack	*next;
}					t_stack;

int					init_stack(t_stack **stack_a, char ***args);
t_stack				*lst_add_end(t_stack **stack, int value);
void				free_stack(t_stack **stack);
void				free_matrix(char ***matrix);
void				free_arr(char **arr);
void				print_error(t_stack **stack_a, t_stack **stack_b,
						char ***args);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				verify_stack_order(t_stack *stack);
void				verify_duplicated_numbers(t_stack *stack);
void				sort_three(t_stack **stack_a);
void				set_above_midle(t_stack **stack_a);
void				set_target(t_stack **stack_a, t_stack **stack_b);
void				set_stack_index(t_stack **stack_a, t_stack **stack_b);
size_t				ft_list_size(t_stack **stack);
// DELETAR ESSA FUNCAO
void				target(t_stack **stack_a, t_stack **stack_b);

#endif
