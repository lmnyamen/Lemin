/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelthis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:27:28 by jpieczar          #+#    #+#             */
/*   Updated: 2019/09/09 15:27:49 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelthis(t_node **alst)
{
	t_node	*pntr;
	t_node	*rtnp;

	pntr = *alst;
	while (pntr->next)
	{
		rtnp = pntr->next;
		free(pntr);
		pntr = NULL;
		pntr = rtnp;
	}
	free(pntr);
	pntr = NULL;
	*alst = NULL;
}
