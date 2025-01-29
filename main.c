/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:55:12 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 10:33:52 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = new_stacks();
	if (!stacks)
	{
		ft_puts(2, "Error");
		return (1);
	}
	if (!parser(ac - 1, av + 1, stacks->a) || has_duplicate(stacks->a))
	{
		free_stacks(stacks);
		ft_puts(2, "Error");
		return (1);
	}
	if (!is_sorted(stacks->a))
		sort(stacks);
	free_stacks(stacks);
}
