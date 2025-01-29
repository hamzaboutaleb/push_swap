/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:40:19 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 06:48:31 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	ra(t_stacks *stacks)
{
	t_node	*last;

	if (stacks->a->length <= 1)
		return ;
	last = pop(stacks->a);
	push_front(stacks->a, last);
}

void	rb(t_stacks *stacks)
{
	t_node	*last;

	if (stacks->b->length <= 1)
		return ;
	last = pop(stacks->b);
	push_front(stacks->b, last);
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}
