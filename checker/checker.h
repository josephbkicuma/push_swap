/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:28:15 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/14 14:23:23 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack
{
	int				value;
	int				cost;
	int				un_cost;
	size_t			target;
	size_t			index;
	bool			above_mid;
	struct s_stack	*next;
}					t_stack;

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
void				print_error(t_stack **stack_a, t_stack **stack_b,
						char ***args);
void				free_stack(t_stack **stack);
void				free_arr(char **arr);
void				free_matrix(char ***matrix);
void				free_exit_sucess(t_stack **stack);
char				***split_args(char **av, int ac);
t_stack				*lst_add_end(t_stack **stack, int value);
int					init_stack(t_stack **stack_a, char ***args);
void				verify_stack_order(t_stack *stack, t_stack *b);
void				verify_duplicated_numbers(t_stack *stack);
size_t				ft_list_size(t_stack **stack);
void				set_above_midle(t_stack **stack_a);
void				set_stack_index(t_stack **stack_a, t_stack **stack_b);
long				ft_atol(const char *str);
int					ft_isdigit(int i);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *str, char c);
char				*get_next_line(int fd);

#endif
