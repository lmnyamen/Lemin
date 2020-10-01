/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:40:17 by jpieczar          #+#    #+#             */
/*   Updated: 2019/09/16 09:18:51 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	pushpath(t_path **head, t_path *new_r)
{
	t_path	*ptr;

	ptr = *head;
	if (*head == NULL)
	{
		*head = new_r;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new_r;
	new_r->prev = ptr;
	new_r->next = NULL;
}

t_path	*duppath(t_path *src)
{
	t_path	*new;
	t_list	*ptr;

	new = malloc(sizeof(t_path));
	new->size = src->size;
	new->next = NULL;
	new->prev = NULL;
	new->aroute = ft_lstdup(src->aroute);
	ptr = new->aroute;
	while (ptr && ptr->next)
		ptr = ptr->next;
	new->broute = ptr;
	return (new);
}

t_path	*newpath(t_list *list)
{
	t_path	*new;
	t_list	*ptr;

	new = malloc(sizeof(t_path));
	new->aroute = list;
	new->size = 1;
	ptr = new->aroute;
	while (ptr && ptr->next)
	{
		ptr = ptr->next;
		new->size++;
	}
	new->broute = ptr;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	deletepath(t_path **ptr)
{
	t_list	*lst;
	t_list	*next;

	if (*ptr && (*ptr)->prev != NULL)
		(*ptr)->prev->next = (*ptr)->next;
	if (*ptr && (*ptr)->next != NULL)
		(*ptr)->next->prev = (*ptr)->prev;
	lst = (*ptr)->aroute;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
	(*ptr)->broute = NULL;
	(*ptr)->next = NULL;
	(*ptr)->size = 0;
	free(*ptr);
}

void	deletepaths(t_path **head)
{
	t_list	*lst;
	t_list	*next;

	if (*head)
	{
		deletepaths(&(*head)->next);
		(*head)->next = NULL;
		lst = (*head)->aroute;
		while (lst)
		{
			next = lst->next;
			free(lst);
			lst = next;
		}
		free(*head);
		*head = NULL;
	}
}
