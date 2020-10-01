/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 09:41:33 by jpieczar          #+#    #+#             */
/*   Updated: 2019/06/05 08:55:34 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*p1;
	unsigned char	*p2;
	unsigned char	chr;

	i = 0;
	p1 = (char*)dst;
	p2 = (unsigned char*)src;
	chr = c;
	while (i < n)
	{
		p1[i] = p2[i];
		if (p2[i] == chr)
			return ((void*)dst + i + 1);
		i++;
	}
	return (NULL);
}
