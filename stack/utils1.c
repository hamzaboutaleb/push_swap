/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:32:43 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 10:25:52 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*delete_one(t_stack *s)
{
	t_node	*head;

	head = s->head;
	s->head = NULL;
	s->tail = NULL;
	s->length--;
	return (head);
}

int	push(t_stack *s, t_node *n)
{
	if (!s || !n)
		return (0);
	if (s->length == 0)
		return (add_first(s, n));
	n->prev = s->tail;
	s->tail->next = n;
	s->tail = n;
	s->length++;
	return (1);
}

t_node	*pop(t_stack *s)
{
	t_node	*tail;

	if (!s || s->length == 0)
		return (NULL);
	if (s->length == 1)
		return (delete_one(s));
	tail = s->tail;
	s->tail = tail->prev;
	s->tail->next = NULL;
	tail->prev = NULL;
	s->length--;
	return (tail);
}

int	push_front(t_stack *s, t_node *node)
{
	if (!s || !node)
		return (0);
	if (s->length == 0)
		return (add_first(s, node));
	node->next = s->head;
	s->head->prev = node;
	s->head = node;
	s->length++;
	return (1);
}

void	free_stacks(t_stacks *stacks)
{
	if (!stacks)
		return ;
	free_stack(stacks->a);
	free_stack(stacks->b);
	free(stacks);
}
