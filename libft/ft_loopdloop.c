/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loopdloop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:41:34 by jpieczar          #+#    #+#             */
/*   Updated: 2019/07/29 11:41:37 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_loopdloop(t_node **list)
{
	t_node	*tsil;

	tsil = *list;
	while (tsil->next)
	{
		ft_putnbr(tsil->data);
		ft_putendl("");
		tsil = tsil->next;
	}
}
