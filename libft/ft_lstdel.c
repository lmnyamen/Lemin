/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:27:28 by jpieczar          #+#    #+#             */
/*   Updated: 2019/06/14 15:27:49 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*pntr;
	t_list	*rtnp;

	pntr = *alst;
	while (pntr->next)
	{
		rtnp = pntr->next;
		del(pntr, pntr->content_size);
		pntr = rtnp;
	}
	del(pntr, pntr->content_size);
	*alst = NULL;
}
