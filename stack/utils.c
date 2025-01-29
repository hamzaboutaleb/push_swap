/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:25:40 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/25 11:13:06 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->length = 0;
	return (stack);
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

int	add_first(t_stack *stack, t_node *node)
{
	stack->head = node;
	stack->tail = node;
	stack->length++;
	return (1);
}

t_node	*dequeue(t_stack *stack)
{
	t_node	*head;
	t_node	*next;

	if (!stack || stack->head == NULL)
		return (NULL);
	if (stack->length == 1)
		return (delete_one(stack));
	head = stack->head;
	next = head->next;
	next->prev = NULL;
	stack->head = next;
	head->next = NULL;
	stack->length--;
	return (head);
}
