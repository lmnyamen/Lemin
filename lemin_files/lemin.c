/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:40:17 by jpieczar          #+#    #+#             */
/*   Updated: 2019/09/16 09:18:51 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	makemap(char **arr, t_room **head, char **input)
{
	if (ft_isnumber(arr[1]) && ft_isnumber(arr[2]))
	{
		makeroom(head, arr[0], NULL);
		endorstart(*head, arr[0], *input);
	}
	else
	{
		ft_putendl("Improper coordinates.");
		exit(0);
	}
	if (*input)
		ft_strdel(input);
}

t_room	*make(t_room **head)
{
	char	*str;
	char	**arr;
	char	*comment;

	comment = NULL;
	while (get_next_line(0, &str) > 0)
	{
		ft_putendl(str);
		if (str[0] == '#')
		{
			if (str[1] == '#')
				comment = ft_strdup(str);
			ft_strdel(&str);
			continue ;
		}
		arr = ft_strsplit(str, ' ');
		if (arr[1] != NULL && arr[2] != NULL)
			makemap(arr, head, &comment);
		else
			head = makelinks(head, str);
		ft_freedub(arr);
		(comment) ? ft_strdel(&comment) : 0;
		ft_strdel(&str);
	}
	return (*head);
}

void	checkrooms(t_room *head)
{
	int		s;
	int		e;
	t_room	*ptr;

	s = 0;
	e = 0;
	ptr = head;
	while (ptr)
	{
		if (ptr->s)
			s++;
		if (ptr->e)
			e++;
		ptr = ptr->next;
	}
	if (s != 1 || e != 1)
		roomerror();
}

void	checkforend(t_path *paths)
{
	int		e;
	t_room	*r;
	t_path	*p;

	p = paths;
	e = 0;
	while (p)
	{
		r = p->broute->content;
		if (r->e == 1)
			e = 1;
		p = p->next;
	}
	if (!e)
	{
		ft_putendl("No path found.");
		exit(0);
	}
}


int		main()
{
	char	*ants;
	t_room	*head;
	t_path	*paths;

	head = NULL;
	if (!(get_next_line(0, &ants) > 0 && ft_isnumber(ants)))
		anterror();
	ft_putendl(ants);
	head = make(&head);
	checkrooms(head);
	makeants(head, ants);
	ft_putendl("");
	paths = pathfinder(head);
	checkforend(paths);
	if (!paths)
		ft_putendl("Error.");
	cleanpath(paths);
	outputants(paths);
	deletemap(&head);
	deletepaths(&paths);
}
