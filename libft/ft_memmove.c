/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:37:35 by jpieczar          #+#    #+#             */
/*   Updated: 2019/06/28 16:38:27 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = len;
	p1 = (unsigned char*)dst;
	p2 = (unsigned char*)src;
	if (p1 == NULL && p2 == NULL)
		return (NULL);
	if (dst > src)
	{
		while (i > 0)
		{
			i--;
			p1[i] = p2[i];
		}
		return ((void*)dst);
	}
	dst = ft_memcpy(dst, src, len);
	return ((void*)dst);
}
