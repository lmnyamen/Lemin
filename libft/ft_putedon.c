/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putedon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:42:37 by jpieczar          #+#    #+#             */
/*   Updated: 2019/09/12 11:04:25 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putedon(t_node **list, char **av, int ac)
{
	t_node	*tsil;
	int		i;

	*list = ft_newdnode();
	(*list)->data = ft_atoi(av[0]);
	(*list)->pos = 0;
	tsil = *list;
	i = 1;
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
