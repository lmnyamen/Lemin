/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 09:20:53 by jpieczar          #+#    #+#             */
/*   Updated: 2019/06/05 09:14:24 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s1, char (*f) (char))
{
	int		i;
	char	*str;

	i = 0;
	if (s1 != NULL)
	{
		while (s1[i])
			i++;
		if (!(str = malloc((i + 1) * sizeof(char))))
			return (NULL);
		i = 0;
		while (s1[i])
		{
			str[i] = f(s1[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
