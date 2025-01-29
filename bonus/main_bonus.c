/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:11:34 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/29 20:37:29 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	push_instruction(t_stack *stack, char *line)
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

static int	read_instruction(t_stack *stack)
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

static void	execute(t_stack *instruction, t_stacks *stacks)
{
	static void	((*f[8])(t_stacks *)) = {pa, pb, ra, rb, rra, rrb, sa, sb};
	t_node		*curr;

	curr = instruction->head;
	while (curr)
	{
		f[curr->value](stacks);
		curr = curr->next;
	}
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	t_stack		*instruction;

	if (ac == 1)
		return (0);
	stacks = new_stacks();
	if (!stacks)
	{
		ft_puts(2, "Error");
		return (1);
	}
	instruction = new_stack();
	if (!instruction)
	{
		free_stacks(stacks);
		ft_puts(2, "Error");
		return (1);
	}
	if (!parser(ac - 1, av + 1, stacks->a) || has_duplicate(stacks->a))
	{
		free_stacks(stacks);
		free_stack(instruction);
		ft_puts(2, "Error");
		return (1);
	}
	if (!read_instruction(instruction))
	{
		free_stack(instruction);
		free_stacks(stacks);
		ft_puts(2, "Error");
		return (1);
	}
	execute(instruction, stacks);
	if (stacks->b->length == 0 && is_sorted(stacks->a))
		ft_puts(1, "OK");
	else
		ft_puts(1, "KO");
	free_stack(instruction);
	free_stacks(stacks);
}
