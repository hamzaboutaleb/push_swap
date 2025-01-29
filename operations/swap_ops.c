/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:37:42 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 06:50:21 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	sa(t_stacks *stacks)
{
	t_node	*first_element;
	t_node	*second_element;

	if (stacks->a->length < 2)
		return ;
	first_element = pop(stacks->a);
	second_element = pop(stacks->a);
	push(stacks->a, first_element);
	push(stacks->a, second_element);
}

void	sb(t_stacks *stacks)
{
	t_node	*first_element;
	t_node	*second_element;

	if (stacks->b->length < 2)
		return ;
	first_element = pop(stacks->b);
	second_element = pop(stacks->b);
	push(stacks->b, first_element);
	push(stacks->b, second_element);
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}
