/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:40:17 by jpieczar          #+#    #+#             */
/*   Updated: 2019/09/16 09:18:51 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		possiblemove(t_path *path, int ants)
{
	int		t_ants;
	int		loop;
	int		cur;
	t_path	*ptr;

	loop = 0;
	ptr = path;
	t_ants = 0;
	cur = 0;
	while (t_ants < ants)
	{
		while (ptr && ptr->size == cur && t_ants < ants)
		{
			loop++;
			t_ants++;
			ptr = ptr->next;
		}
		t_ants += loop;
		cur++;
	}
	return (loop);
}

void	makeants(t_room *head, char *ants)
{
	long long	n;
	t_room		*ptr;

	ptr = head;
	while (ptr && !ptr->s)
		ptr = ptr->next;
	if (ptr == NULL)
		starterror();
	if (ft_isnumber(ants))
	{
		n = ft_atoi(ants);
		if (n > 0 && n < 2147483647)
			ptr->ants = n;
		else
		{
			ft_putendl("Enter a proper number of ants.");
			exit(0);
		}
	}
	else
		anterror();
}

t_list	**addant(t_list **arr, int *loop, int n, t_path *ref)
{
	int		i;
	t_path	*paths;
	t_room	*room;

	paths = ref;
	i = 0;
	while (i < n)
	{
		arr[*loop] = paths->aroute->next;
		paths = paths->next;
		room = arr[*loop]->content;
		room->ants++;
		outputant((*loop) + 1, room->name);
		room = ref->aroute->content;
		room->ants--;
		if (i != n - 1)
			ft_putstr(" ");
		(*loop)++;
		i++;
	}
	return (arr);
}

t_list	**pushant(t_list **arr, int n, t_path *head)
{
	int		loop;
	t_room	*room;
	t_list	*ptr;
	t_path	*ref;

	loop = -1;
	while (arr[++loop] != NULL)
	{
		room = arr[loop]->content;
		if (room->e)
			continue ;
		ptr = arr[loop]->next;
		arr[loop] = ptr;
		room = ptr->content;
		room->ants++;
		outputant(loop + 1, room->name);
		if (arr[loop + 1] || n != 0)
			ft_putstr(" ");
	}
	ref = head;
	arr = addant(arr, &loop, n, ref);
	return (arr);
}

void	outputants(t_path *path)
{
	int		ants;
	int		n;
	int		a;
	t_list	**arr;
	t_room	*room;

	room = path->aroute->content;
	ants = room->ants;
	a = ants;
	arr = makearr(a);
	room = path->broute->content;
	while (a > room->ants)
	{
		room = path->aroute->content;
		ants = room->ants;
		n = possiblemove(path, ants);
		pushant(arr, n, path);
		ft_putendl("");
		room = path->broute->content;
	}
	free(arr);
}


