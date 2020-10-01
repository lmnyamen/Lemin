/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 07:27:33 by jpieczar          #+#    #+#             */
/*   Updated: 2019/06/06 08:29:57 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen((const char*)dst);
	k = j;
	if (j > dstsize)
		k = dstsize;
	k += ft_strlen(src);
	while (src[i] != '\0' && i + j < dstsize - 1 && dstsize > 0)
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (k);
}
