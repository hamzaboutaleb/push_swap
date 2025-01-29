/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:58:53 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/25 15:59:59 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "./../stack/stack.h"

int	parser(int ac, char **av, t_stack *stack);
int	parse_argument(t_stack *stack, char *str);
int	parse_number(t_stack *stack, char *s, int *start);
#endif
