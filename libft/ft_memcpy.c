/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 07:28:44 by jpieczar          #+#    #+#             */
/*   Updated: 2019/05/29 11:47:08 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p1;
	char	*p2;

	p1 = dst;
	p2 = (char*)src;
	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dst);
}
