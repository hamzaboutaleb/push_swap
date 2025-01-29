/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboutale <hboutale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:22:26 by hboutale          #+#    #+#             */
/*   Updated: 2025/01/28 07:01:01 by hboutale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H
# define SET_SIZE 200
# include "./../stack/stack.h"
# include "./../utils/utils.h"
# include <stdlib.h>

typedef struct s_set
{
	t_node	*list[SET_SIZE];
}			t_set;

t_set		*new_set(void);
int			hash(int hash);
void		set_add(t_set *set, int value);
int			set_has(t_set *set, int value);
void		set_free(t_set *set);

#endif
