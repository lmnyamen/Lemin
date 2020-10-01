/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:25:39 by jpieczar          #+#    #+#             */
/*   Updated: 2019/06/05 08:53:51 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*pntr;
	unsigned char	d;

	pntr = b;
	d = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		pntr[i] = d;
		i++;
	}
	return (b);
}
