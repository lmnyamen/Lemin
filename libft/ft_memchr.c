/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 07:56:23 by jpieczar          #+#    #+#             */
/*   Updated: 2019/05/29 14:50:00 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pntr;
	unsigned char	w;

	i = 0;
	w = (unsigned char)c;
	pntr = (unsigned char*)s;
	while (i < n)
	{
		if (pntr[i] == w)
			return ((void*)s);
		i++;
	}
	return (NULL);
}
