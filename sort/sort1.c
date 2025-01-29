/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:52:41 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 10:00:18 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include <unistd.h>

static t_node	**new_array(t_stack *stack)
{
	t_node	**arr;
	t_node	*curr;
	int		i;

	i = 0;
	arr = (t_node **)malloc(sizeof(t_node *) * stack->length);
	if (!arr)
		return (NULL);
	curr = stack->head;
	while (i < stack->length)
	{
		arr[i] = curr;
		curr = curr->next;
		i++;
	}
	return (arr);
}

static t_node	**sorted_stack(t_stack *stack)
{
	t_node	**arr;
	int		i;

	i = 0;
	arr = new_array(stack);
	if (!arr)
		return (0);
	if (!merge_sort(arr, 0, stack->length - 1))
	{
		free(arr);
		return (0);
	}
	i = 0;
	while (i < stack->length)
	{
		arr[i]->value = i;
		i++;
	}
	return (arr);
}

t_index	*get_element_range(t_stack *a, int min, int max)
{
	t_index	*idx;
	t_node	*curr;
	int		i;

	i = 0;
	idx = new_index(NULL, -1, -1);
	curr = a->tail;
	while (curr)
	{
		if (curr->value >= min && curr->value <= max)
		{
			idx->element = curr;
			idx->position = i;
			return (idx);
		}
		i++;
		curr = curr->prev;
	}
	return (idx);
}

void	change_range(int *start, int *end, int size, int offset)
{
	*start -= offset;
	if (*start < 0)
		*start = 0;
	*end += offset;
	if (*end >= size)
		*end = size - 1;
}

void	sort_large(t_stacks *stacks, int div)
{
	t_sort_info	info;
	t_node		**arr;

	arr = sorted_stack(stacks->a);
	info.size = stacks->a->length;
	info.offset = info.size / div;
	info.mid = info.size / 2 - 1;
	info.start = info.mid - info.offset;
	info.end = info.mid + info.offset;
	move_to_b(stacks, arr, &info);
	move_to_a(stacks, &info);
	free(arr);
}
