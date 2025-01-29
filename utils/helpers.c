/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:33:52 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 11:54:32 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *s, int *error)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (*s && (*s == '-' || *s == '+'))
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s && *s >= '0' && *s <= '9')
	{
		if (sign == 1 && (result > INT_MAX / 10 || (result == INT_MAX / 10 && *s
					- '0' > INT_MAX % 10)))
			return (*error = 1);
		if (sign == -1 && (result > -(INT_MIN / 10) || (result == -(INT_MIN
						/ 10) && *s - '0' > -(INT_MIN % 10))))
			return (*error = 1);
		result = result * 10 + *s - '0';
		s++;
	}
	return (result * sign);
}

int	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	has_duplicate(t_stack *stack)
{
	t_set	*set;
	t_node	*curr;
	int		result;

	result = 0;
	set = new_set();
	if (set == NULL)
		return (1);
	curr = stack->head;
	while (curr)
	{
		if (set_has(set, curr->value))
		{
			result = 1;
			break ;
		}
		set_add(set, curr->value);
		curr = curr->next;
	}
	set_free(set);
	return (result);
}

void	run_operation(int n, t_stacks *s, void (*fn)(t_stacks *), char *str)
{
	int	i;

	i = 0;
	while (i < n)
	{
		fn(s);
		ft_puts(1, str);
		i++;
	}
}
