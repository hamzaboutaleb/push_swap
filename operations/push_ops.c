/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:39:33 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 06:48:13 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./operations.h"

void	pa(t_stacks *stacks)
{
	t_node	*element;

	if (stacks->b->length == 0)
		return ;
	element = pop(stacks->b);
	push(stacks->a, element);
}

void	pb(t_stacks *stacks)
{
	t_node	*element;

	if (stacks->a->length == 0)
		return ;
	element = pop(stacks->a);
	push(stacks->b, element);
}
