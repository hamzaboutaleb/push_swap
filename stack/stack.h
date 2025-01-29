/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:22:45 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 09:56:46 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				length;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

typedef struct s_index
{
	t_node			*element;
	int				position;
	int				cost;
}					t_index;

// utils.c
t_stack				*new_stack(void);
t_node				*new_node(int value);
t_node				*dequeue(t_stack *stack);
int					add_first(t_stack *stack, t_node *node);
// utils1.c
t_node				*delete_one(t_stack *s);
int					push(t_stack *s, t_node *n);
t_node				*pop(t_stack *s);
int					push_front(t_stack *s, t_node *node);
void				free_stack(t_stack *stack);
void				free_stacks(t_stacks *stacks);
// utils2.
t_stacks			*new_stacks(void);
t_index				*get_min(t_stack *stack);
t_index				*new_index(t_node *el, int i, int ops);
t_index				*get_max(t_stack *stack);
#endif
