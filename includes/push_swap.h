/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:13:33 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/08 12:40:13 by jquicuma         ###   ########.fr       */
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

#endif
