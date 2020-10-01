/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:26:20 by jpieczar          #+#    #+#             */
/*   Updated: 2019/06/14 15:26:46 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = (void *)content;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

t_list	*ft_lstdup(t_list *head)
{
	t_list	*new;
	t_list	*ptr;

	ptr = head;
	new = NULL;
	while (ptr)
	{
		ft_lstpushback(&new, ft_lstnew(ptr->content, ptr->content_size));
		ptr = ptr->next;
	}
	return (new);
}