/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:40:17 by jpieczar          #+#    #+#             */
/*   Updated: 2019/09/16 09:18:51 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*findinmap(t_room **head, char *name)
{
	t_room	*ptr;

	ptr = *head;
	while (ptr && !ft_strequ(ptr->name, name))
		ptr = ptr->next;
	if (ptr == NULL)
		linkerror();
	return (ptr);
}

t_list	**makearr(int n)
{
	int		loop;
	t_list	**arr;

	loop = 0;
	arr = malloc(sizeof(t_list *) * (n + 1));
	while (loop <= n)
	{
		arr[loop] = NULL;
		loop++;
	}
	return (arr);
}

t_room	**linkrooms(t_room **head, char **arr)
{
	t_room *r1;
	t_room	*r2;

	if (arr[0] != NULL && arr[1] && arr[2] == NULL)
	{
		r1 = findinmap(head, arr[0]);
		r2 = findinmap(head, arr[1]);
		ft_lstadd(&(r1->links), ft_lstnew(r2, sizeof(r2)));
		ft_lstadd(&(r2->links), ft_lstnew(r1, sizeof(r2)));
	}
	return (head);
}

t_room	**makelinks(t_room **head, char *s)
{
	char	*str;
	char	**arr;

	if (!(*head) || !(*head)->next)
		roomerror();
	if (s && ft_strlen(s) > 2)
	{
		arr = ft_strsplit(s, '-');
		head = linkrooms(head, arr);
		ft_freedub(arr);
	}
	while (get_next_line(0, &str) > 0)
	{
		ft_putendl(str);
		arr = ft_strsplit(str, '-');
		head = linkrooms(head, arr);
		ft_freedub(arr);
		ft_strdel(&str);
	}
	return (head);
}


