/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:39:23 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/29 20:44:36 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bonus.h"

int	push_instruction(t_stack *stack, char *line)
{
	static char	*ins[8] = {"pa\n", "pb\n", "ra\n", "rb\n", "rra\n", "rrb\n",
		"sa\n", "sb\n"};
	int			i;

	i = 0;
	while (i < 8)
	{
		if (ft_strcmp(ins[i], line) == 0)
		{
			push(stack, new_node(i));
			return (1);
		}
		i++;
	}
	return (0);
}

int	read_instruction(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!push_instruction(stack, line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

void	execute(t_stack *instruction, t_stacks *stacks)
{
	static void	(*f[8])(t_stacks *) = {pa, pb, ra, rb, rra, rrb, sa, sb};
	t_node		*curr;

	curr = instruction->head;
	while (curr)
	{
		f[curr->value](stacks);
		curr = curr->next;
	}
}
