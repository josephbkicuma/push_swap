/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:02:13 by jquicuma          #+#    #+#             */
/*   Updated: 2024/09/10 14:14:52 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stack  *get_target_adress(size_t index_target, t_stack **stack_b)
{
    t_stack *aux;
    
    aux = *stack_b;
    while (aux)
    {
        if (index_target == aux->index)
            return (aux);
        aux = aux->next;
    }
    return (NULL);
}

static int  set_cost_above(t_stack **stack)
{
    t_stack *aux;
    size_t  mid_stack_size;
    size_t  index;

    aux = *stack;
    mid_stack_size = ft_list_size(stack) / 2;
    index = aux->index + 1;
    return (mid_stack_size - index);
}

/*static int  set_cost_below(t_stack **stack)
{
    return (0);
}*/

void    calculate_coast(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *aux;
    t_stack *target_node;

    aux = *stack_a;
    while (aux)
    {
        target_node = get_target_adress(aux->target, stack_b);
        if (!target_node->above_mid && aux->above_mid)
        {
            aux->cost = set_cost_above(&target_node) + set_cost_above(&aux);
        }
        aux = aux->next;
    }
}
