/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:09:48 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/25 21:06:23 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rra(t_stacks *stacks)
{
	t_node	*first;

	if (stacks->a->length <= 1)
		return ;
	first = dequeue(stacks->a);
	push(stacks->a, first);
}

void	rrb(t_stacks *stacks)
{
	t_node	*first;

	if (stacks->b->length <= 1)
		return ;
	first = dequeue(stacks->b);
	push(stacks->b, first);
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
