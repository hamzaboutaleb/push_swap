/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:11:34 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/29 20:42:28 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	init_stacks(t_stacks **stacks, t_stack **instruction)
{
	*stacks = new_stacks();
	if (!*stacks)
	{
		ft_puts(2, "Error");
		return (0);
	}
	*instruction = new_stack();
	if (!*instruction)
	{
		free_stacks(*stacks);
		ft_puts(2, "Error");
		return (0);
	}
}

static void	free_all(t_stacks *stacks, t_stack *instruction)
{
	free_stacks(stacks);
	free_stack(instruction);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	t_stack		*instruction;

	if (ac == 1)
		return (0);
	if (!init_stacks(&stacks, &instruction))
		return (1);
	if (!parser(ac - 1, av + 1, stacks->a) || has_duplicate(stacks->a))
	{
		free_all(stacks, instruction);
		ft_puts(2, "Error");
		return (1);
	}
	if (!read_instruction(instruction))
	{
		free_all(stacks, instruction);
		ft_puts(2, "Error");
		return (1);
	}
	execute(instruction, stacks);
	if (stacks->b->length == 0 && is_sorted(stacks->a))
		ft_puts(1, "OK");
	else
		ft_puts(1, "KO");
	free_all(stacks, instruction);
}
