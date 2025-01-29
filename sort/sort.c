/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:32:24 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 10:26:39 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort(t_stacks *stacks)
{
	if (stacks->a->length <= 1)
		return ;
	else if (stacks->a->length == 2)
		sort_two(stacks);
	else if (stacks->a->length == 3)
		sort_three(stacks);
	else if (stacks->a->length <= 10)
		sort_small(stacks);
	else if (stacks->a->length < 250)
		sort_large(stacks, 8);
	else
		sort_large(stacks, 18);
}

void	sort_two(t_stacks *stacks)
{
	t_node	*tail;
	t_node	*prev;

	if (stacks->a->length < 2)
		return ;
	tail = stacks->a->tail;
	prev = tail->prev;
	if (tail->value > prev->value)
		run_operation(1, stacks, sa, "sa");
}

static void	sort_three_cases(t_node *bot, t_node *mid, t_node *top,
		t_stacks *stacks)
{
	if (bot->value > mid->value && top->value > mid->value
		&& bot->value > top->value)
		run_operation(1, stacks, sa, "sa");
	else if (top->value > mid->value && top->value > bot->value
		&& bot->value > mid->value)
		run_operation(1, stacks, ra, "ra");
	else if (mid->value > top->value && mid->value > bot->value
		&& top->value > bot->value)
		run_operation(1, stacks, rra, "rra");
	else if (top->value > mid->value && top->value > bot->value
		&& mid->value > bot->value)
	{
		run_operation(1, stacks, sa, "sa");
		run_operation(1, stacks, rra, "rra");
	}
	else if (mid->value > top->value && mid->value > bot->value
		&& bot->value > top->value)
	{
		run_operation(1, stacks, sa, "sa");
		run_operation(1, stacks, ra, "ra");
	}
}

void	sort_three(t_stacks *stacks)
{
	t_node	*top;
	t_node	*mid;
	t_node	*bot;

	if (stacks->a->length < 3)
	{
		sort_two(stacks);
		return ;
	}
	top = stacks->a->tail;
	mid = top->prev;
	bot = mid->prev;
	sort_three_cases(bot, mid, top, stacks);
}

void	sort_small(t_stacks *stacks)
{
	t_index	*idx;

	while (stacks->a->length > 3)
	{
		idx = get_min(stacks->a);
		if (idx->position < stacks->a->length / 2)
			run_operation(idx->position, stacks, ra, "ra");
		else
			run_operation(stacks->a->length - idx->position, stacks, rra,
				"rra");
		run_operation(1, stacks, pb, "pb");
		free(idx);
	}
	sort_three(stacks);
	while (stacks->b->length > 0)
	{
		run_operation(1, stacks, pa, "pa");
	}
}
