/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:59:22 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 09:54:35 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../utils/utils.h"
#include "./parser.h"

int	parser(int ac, char **av, t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (i < ac)
	{
		if (!parse_argument(stack, av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_argument(t_stack *stack, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_whitespace(str[i]))
			i++;
		else if (is_number(str[i]) || str[i] == '+' || str[i] == '-')
		{
			if (!parse_number(stack, str, &i))
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_strndup(char *src, size_t slen)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc(slen + 1);
	if (res == NULL)
		return (NULL);
	while (i < slen)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	parse_number(t_stack *stack, char *s, int *start)
{
	int		end;
	int		error;
	char	*str_num;
	int		res;

	error = 0;
	end = *start;
	if (s[end] == '+' || s[end] == '-')
		end++;
	if (!is_number(s[end]))
		return (0);
	while (s[end] && is_number(s[end]))
		end++;
	if (s[end] != '\0' && !is_whitespace(s[end]))
		return (0);
	str_num = ft_strndup(s + *start, end - *start);
	if (!str_num)
		return (0);
	res = ft_atoi(str_num, &error);
	free(str_num);
	if (error)
		return (0);
	push_front(stack, new_node(res));
	*start = end;
	return (1);
}
