/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:34:18 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/29 10:43:00 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# include "./../set/set.h"
# include "./../stack/stack.h"
# include <unistd.h>

int		ft_atoi(const char *s, int *error);
int		is_whitespace(char c);
int		is_number(char c);
int		has_duplicate(t_stack *stack);
void	run_operation(int n, t_stacks *s, void (*fn)(t_stacks *), char *str);
// helpers 1
size_t	ft_strlen(char *s);
void	ft_puts(int fd, char *s);
int		ft_abs(int i);
int		is_sorted(t_stack *stack);
int		ft_strcmp(char *s1, char *s2);
#endif
