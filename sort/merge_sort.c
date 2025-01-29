/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:23:22 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 07:35:16 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	fill_array(t_node **dest, t_node **src, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = NULL;
}

void	merge_arrays(t_node **left, t_node **right, t_node **dest, int start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (left[i] && right[j])
	{
		if (left[i]->value >= right[j]->value)
			dest[start++] = right[j++];
		else
			dest[start++] = left[i++];
	}
	while (left[i])
	{
		dest[start++] = left[i];
		i++;
	}
	while (right[j])
	{
		dest[start++] = right[j];
		j++;
	}
}

int	merge(t_node *arr[], int left, int mid, int right)
{
	int		n1;
	int		n2;
	t_node	**left_arr;
	t_node	**right_arr;

	n1 = (mid - left + 1);
	n2 = (right - mid);
	left_arr = (t_node **)malloc(sizeof(t_node *) * (n1 + 1));
	if (!left_arr)
		return (0);
	right_arr = (t_node **)malloc(sizeof(t_node *) * (n2 + 1));
	if (!right_arr)
	{
		free(left_arr);
		return (0);
	}
	fill_array(left_arr, arr, left, n1);
	fill_array(right_arr, arr, mid + 1, n2);
	merge_arrays(left_arr, right_arr, arr, left);
	free(left_arr);
	free(right_arr);
	return (1);
}

int	merge_sort(t_node *arr[], int left, int right)
{
	int	mid;

	if (left >= right)
		return (1);
	mid = left + (right - left) / 2;
	if (!merge_sort(arr, left, mid))
		return (0);
	if (!merge_sort(arr, mid + 1, right))
		return (0);
	if (!merge(arr, left, mid, right))
		return (0);
	return (1);
}
