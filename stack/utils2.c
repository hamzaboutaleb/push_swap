/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:42:48 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 06:51:16 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./stack.h"

t_stacks	*new_stacks(void)
{
	t_stacks	*s;

	s = (t_stacks *)malloc(sizeof(t_stacks));
	if (!s)
		return (NULL);
	s->a = new_stack();
	s->b = new_stack();
	if (!s->a || !s->b)
	{
		free(s);
		return (NULL);
	}
	return (s);
}

t_index	*new_index(t_node *el, int i, int ops)
{
	t_index	*idx;

	idx = (t_index *)malloc(sizeof(t_index));
	if (!idx)
		return (NULL);
	idx->element = el;
	idx->position = i;
	idx->cost = ops;
	return (idx);
}

t_index	*get_min(t_stack *stack)
{
	t_index	*idx;
	t_node	*curr;
	int		i;

	i = 0;
	curr = stack->tail;
	idx = new_index(curr, i, 1);
	while (curr)
	{
		if (curr->value < idx->element->value)
		{
			idx->element = curr;
			idx->position = i;
		}
		i++;
		curr = curr->prev;
	}
	return (idx);
}

t_index	*get_max(t_stack *stack)
{
	t_index	*idx;
	t_node	*curr;
	int		i;

	i = 0;
	curr = stack->tail;
	idx = new_index(curr, i, 1);
	while (curr)
	{
		if (curr->value > idx->element->value)
		{
			idx->element = curr;
			idx->position = i;
		}
		i++;
		curr = curr->prev;
	}
	return (idx);
}
