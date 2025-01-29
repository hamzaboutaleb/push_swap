/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:32:03 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 09:59:39 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "./../operations/operations.h"
# include "./../stack/stack.h"
# include "./../utils/utils.h"

typedef struct s_sort_info
{
	int	start;
	int	end;
	int	mid;
	int	size;
	int	offset;
}		t_sort_info;

void	sort(t_stacks *stacks);
void	sort_two(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	sort_small(t_stacks *stacks);
void	sort_large(t_stacks *stacks, int div);
int		merge_sort(t_node *arr[], int left, int right);
// sort1
t_index	*get_element_range(t_stack *a, int min, int max);
void	change_range(int *start, int *end, int size, int offset);
// sort large
void	move_to_b(t_stacks *stacks, t_node **arr, t_sort_info *info);
void	push_immediate(t_stacks *stacks, int *max, int *bot_size);
void	push_bottom_stack(t_stacks *stacks, int *bot_size, int expected_max);
void	move_to_a(t_stacks *stacks, t_sort_info *info);
t_index	*find_element(t_stack *s, int value);
#endif
