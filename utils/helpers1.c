/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 06:41:55 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/29 10:42:48 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_puts(int fd, char *s)
{
	size_t	slen;

	slen = ft_strlen(s);
	write(fd, s, slen);
	write(fd, "\n", 1);
}

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->head == NULL || stack->length <= 1)
	{
		return (1);
	}
	current = stack->head;
	while (current->next != NULL)
	{
		if (current->value < current->next->value)
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
