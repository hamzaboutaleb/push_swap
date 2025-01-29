/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:39:23 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 09:59:25 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	move_to_b(t_stacks *stacks, t_node **arr, t_sort_info *info)
{
	t_index	*idx;

	while (stacks->a->length > 0)
	{
		idx = get_element_range(stacks->a, arr[info->start]->value,
				arr[info->end]->value);
		if (idx->element == NULL)
		{
			change_range(&info->start, &info->end, info->size, info->offset);
		}
		else if (idx->position == 0)
		{
			run_operation(1, stacks, pb, "pb");
			if (idx->element->value < info->mid)
				run_operation(1, stacks, rb, "rb");
		}
		else if (idx->position <= stacks->a->length / 2)
			run_operation(1, stacks, ra, "ra");
		else
			run_operation(1, stacks, rra, "rra");
		free(idx);
	}
}

void	push_immediate(t_stacks *stacks, int *max, int *bot_size)
{
	t_index	*idx;

	idx = find_element(stacks->b, *max);
	if (idx->element == NULL)
	{
		run_operation(1, stacks, rra, "rra");
		(*max)--;
		(*bot_size)--;
	}
	else
	{
		if (idx->position <= stacks->b->length / 2)
			run_operation(idx->position, stacks, rb, "rb");
		else
			run_operation(stacks->b->length - idx->position, stacks, rrb,
				"rrb");
		run_operation(1, stacks, pa, "pa");
		(*max)--;
	}
	free(idx);
}

void	push_bottom_stack(t_stacks *stacks, int *bot_size, int expected_max)
{
	int	head_a;
	int	tail_b;

	while (stacks->b->length > 0)
	{
		if (*bot_size == 0)
		{
			run_operation(1, stacks, pa, "pa");
			run_operation(1, stacks, ra, "ra");
			(*bot_size)++;
		}
		else
		{
			head_a = stacks->a->head->value;
			tail_b = stacks->b->tail->value;
			if (tail_b > head_a && tail_b != expected_max)
			{
				run_operation(1, stacks, pa, "pa");
				run_operation(1, stacks, ra, "ra");
				(*bot_size)++;
			}
			else
				break ;
		}
	}
}

void	move_to_a(t_stacks *stacks, t_sort_info *info)
{
	int	bot_size;
	int	expected_max;

	bot_size = 0;
	expected_max = info->size - 1;
	while (stacks->b->length > 0)
	{
		push_immediate(stacks, &expected_max, &bot_size);
		push_bottom_stack(stacks, &bot_size, expected_max);
	}
	while (bot_size > 0)
	{
		run_operation(1, stacks, rra, "rra");
		bot_size--;
	}
}

t_index	*find_element(t_stack *s, int value)
{
	t_index	*idx;
	t_node	*curr;
	int		i;

	i = 0;
	idx = new_index(NULL, -1, -1);
	curr = s->tail;
	while (curr)
	{
		if (curr->value == value)
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
