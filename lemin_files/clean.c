/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:40:17 by jpieczar          #+#    #+#             */
/*   Updated: 2019/09/16 09:18:51 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	usedornot(t_path *r)
{
	t_list	*l;
	t_room	*room;

	l = r->aroute;
	while (l)
	{
		room = l->content;
		if (!(room->s || room->e))
			room->used = 1;
		l = l->next;
	}
}

void	deletelist(void *c)
{
	c = NULL;
	ft_memdel(&c);
}

void	cleanpathdel(t_path **r_ptr, t_list **t_ptr)
{
	t_path	*del;

	del = *r_ptr;
	*r_ptr = (*r_ptr)->next;
	*t_ptr = NULL;
	if (*r_ptr)
		*t_ptr = (*r_ptr)->aroute;
	deletepath(&del);
}

void	cleanpath(t_path *head)
{
	t_path	*r_ptr;
	t_list	*t_ptr;
	t_room	*m_ptr;

	r_ptr = head;
	while (r_ptr)
	{
		t_ptr = r_ptr->aroute;
		while (t_ptr)
		{
			m_ptr = t_ptr->content;
			if (m_ptr->used)
			{
				cleanpathdel(&r_ptr, &t_ptr);
				continue ;
			}
			else
				t_ptr = t_ptr->next;
		}
		if (r_ptr)
		{
			usedornot(r_ptr);
			r_ptr = r_ptr->next;
		}
	}
}


