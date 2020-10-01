/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspliter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 11:46:43 by jpieczar          #+#    #+#             */
/*   Updated: 2019/08/20 11:17:07 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strspliter(char *s)
{
	char	**arr;
	int		i;
	size_t	j;
	int		k;

	i = 0;
	k = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * ft_wc(s) + 1)))
		return (NULL);
	arr[ft_wc(s)] = NULL;
	while (s[i])
	{
		j = 0;
		if (!ft_blank(s[i]))
		{
			while (s[i + j] && !ft_blank(s[i + j]))
				j++;
			arr[k] = ft_strsub(s, i, j);
			i = i + j - 1;
			k++;
		}
		i++;
	}
	arr[k] = NULL;
	return (arr);
}
