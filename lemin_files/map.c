/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:40:17 by jpieczar          #+#    #+#             */
/*   Updated: 2019/09/16 09:18:51 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	endorstart(t_room *head, char *name, char *input)
{
	int		e;
	int		s;
	t_room	*ptr;

	ptr = head;
	e = 0;
	s = 0;
	if (input)
	{
		if (ft_strequ("##start", input))
			s = 1;
		else if (ft_strequ("##end", input))
			e = 1;
	}
	while (ptr && !ft_strequ(ptr->name, name))
		ptr = ptr->next;
	ptr->e = e;
	ptr->s = s;
}

void	makeroom(t_room **head, char *name, t_list *links)
{
	t_room	*new;
	t_room	*ptr;

	new = newroom(name, links);
	if (*head == NULL)
		*head = new;
	else
	{
		ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

int		checkroom(t_room *head, char *name)
{
	t_room	*ptr;

	ptr = head;
	while (ptr)
	{
		if (ptr->name == name)
			return (0);
		ptr = ptr->next;
	}
	if (head->next)
		if (checkroom(head->next, head->name) == 0)
			return (0);
	return (1);
}

t_room	*newroom(char *name, t_list *links)
{
	t_room	*new;

	new = malloc(sizeof(t_room));
	new->name = ft_strdup(name);
	new->ants = 0;
	new->links = links;
	new->s = 0;
	new->e = 0;
	new->used = 0;
	new->next = NULL;
	return (new);
}

void	deletemap(t_room **head)
{
	t_list	*lst;
	t_list	*next;

	if ((*head)->next)
		deletemap(&((*head)->next));
	ft_strdel(&(*head)->name);
	lst = (*head)->links;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
	free(*head);
	*head = NULL;
}


