/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ooplay.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:41:34 by jpieczar          #+#    #+#             */
/*   Updated: 2019/09/12 10:57:06 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ooplay(t_node **list)
{
	t_node	*tsil;

	tsil = *list;
	while (tsil)
	{
		ft_putnbr(tsil->data);
		ft_putchar(' ');
		tsil = tsil->next;
	}
	ft_putendl("");
	tsil = *list;
	while (tsil)
	{
		ft_putstr("#");
		ft_putnbr(tsil->pos);
		ft_putchar(' ');
		tsil = tsil->next;
	}
	ft_putendl("");
}
