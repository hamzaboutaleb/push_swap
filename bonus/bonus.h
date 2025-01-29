/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:14:48 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/29 20:45:33 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include "./../gnl/get_next_line.h"
# include "./../parser/parser.h"
# include "./../sort/sort.h"
# include "./../stack/stack.h"
# include "./../utils/utils.h"
# define PA 0
# define PB 1
# define RA 2
# define RB 3
# define RRA 4
# define RRB 5
# define SA 6
# define SB 7

int	push_instruction(t_stack *stack, char *line);
int	read_instruction(t_stack *stack);
void	execute(t_stack *instruction, t_stacks *stacks);
#endif
