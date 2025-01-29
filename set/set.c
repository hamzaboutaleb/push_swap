/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:28:59 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 07:01:26 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

t_set	*new_set(void)
{
	t_set	*set;
	int		i;

	i = 0;
	set = (t_set *)malloc(sizeof(t_set));
	if (!set)
		return (NULL);
	while (i < SET_SIZE)
		set->list[i++] = NULL;
	return (set);
}

int	hash(int value)
{
	return (ft_abs(value) % (int)SET_SIZE);
}
