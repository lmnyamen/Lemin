/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:29:01 by jpieczar          #+#    #+#             */
/*   Updated: 2019/06/14 15:29:24 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*wen;

	if (lst == NULL || f == NULL)
		return (NULL);
	wen = f(lst);
	new = wen;
	while (lst->next)
	{
		wen->next = f(lst->next);
		wen = wen->next;
		lst = lst->next;
	}
	return (new);
}
