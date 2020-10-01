/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:40:17 by jpieczar          #+#    #+#             */
/*   Updated: 2019/09/16 09:18:51 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		checkpaths(t_path *head, t_room *room)
{
	t_path	*r_ptr;
	t_list	*links;
	t_room	*ptr;

	r_ptr = head;
	links = r_ptr->aroute;
	while (links)
	{
		ptr = links->content;
		if (ptr == room)
			return (0);
		links = links->next;
	}
	return (1);
}

t_path	*pathfinder(t_room *rooms)
{
	t_path	*new;
	t_room	*ptr;
	t_list	*lst;

	ptr = rooms;
	while (ptr && !ptr->s)
		ptr = ptr->next;
	if (ptr == NULL)
		starterror();
	lst = ft_lstnew(ptr, sizeof(ptr));
	new = newpath(lst);
	pathstepper(&new);
	return (new);
}

void	pathstepperdelete(t_path **head, t_path **ptr)
{
	t_path	*next;

	next = (*ptr)->next;
	if (*head == *ptr)
		*head = next;
	deletepath(ptr);
	*ptr = next;
}

void	pathstepper(t_path **head)
{
	t_path	*ptr;
	t_list	*rooms;
	t_room	*tmp;

	ptr = *head;
	while (ptr)
	{
		rooms = ptr->broute;
		tmp = (t_room *)rooms->content;
		rooms = tmp->links;
		if (tmp->e != 1)
		{
			while (rooms != NULL)
			{
				tmp = (t_room *)rooms->content;
				addstep(head, ptr, tmp);
				rooms = rooms->next;
			}
			pathstepperdelete(head, &ptr);
		}
		else
			ptr = ptr->next;
	}
}

void	addstep(t_path **head, t_path *cur, t_room *room)
{
	t_path	*new;
	t_list	*l;

	if (checkpaths(cur, room) || room->e == 1)
	{
		new = duppath(cur);
		pushpath(head, new);
		l = ft_lstnew(room, sizeof(room));
		new->broute->next = l;
		new->broute = l;
	}
}
