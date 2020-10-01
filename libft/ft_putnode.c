/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 07:53:26 by jpieczar          #+#    #+#             */
/*   Updated: 2019/09/12 11:04:23 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnode(t_node **list, char **av, int ac)
{
	t_node	*tsil;
	int		i;

	*list = ft_newdnode();
	(*list)->data = ft_atoi(av[1]);
	(*list)->pos = 0;
	tsil = *list;
	i = 2;
	while (i < ac)
	{
		tsil->next = ft_newdnode();
		tsil->next->data = ft_atoi(av[i]);
		tsil->next->pos = 0;
		tsil = tsil->next;
		i++;
	}
	tsil->next = NULL;
}
