/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 07:20:02 by jpieczar          #+#    #+#             */
/*   Updated: 2020/05/05 08:58:06 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*pntr;
	int		i;

	i = 0;
	pntr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (pntr == NULL)
		return (NULL);
	while (s[i])
	{
		pntr[i] = s[i];
		i++;
	}
	pntr[i] = '\0';
	return (pntr);
}
