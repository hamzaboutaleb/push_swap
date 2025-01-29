/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 07:01:10 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 07:01:29 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void	set_add(t_set *set, int value)
{
	int		pos;
	t_node	*curr;

	pos = hash(value);
	if (set->list[pos] == NULL)
	{
		set->list[pos] = new_node(value);
		return ;
	}
	curr = set->list[pos];
	while (curr->next)
		curr = curr->next;
	curr->next = new_node(value);
}

int	set_has(t_set *set, int value)
{
	int		pos;
	t_node	*curr;

	pos = hash(value);
	if (set->list[pos] == NULL)
		return (0);
	curr = set->list[pos];
	while (curr)
	{
		if (curr->value == value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

static void	free_nodes(t_node *head)
{
	if (head == NULL)
		return ;
	free_nodes(head->next);
	free(head);
}

void	set_free(t_set *set)
{
	int	i;

	i = 0;
	while (i < SET_SIZE)
	{
		if (set->list[i] != NULL)
		{
			free_nodes(set->list[i]);
			set->list[i] = NULL;
		}
		i++;
	}
	free(set);
}
