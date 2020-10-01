/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 11:46:43 by jpieczar          #+#    #+#             */
/*   Updated: 2019/08/20 10:38:32 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wdc(const char *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			res++;
			while (s[i] && (s[i] != c))
				i++;
		}
	}
	return (res);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**arr;
	int		i;
	size_t	j;
	int		k;

	i = 0;
	k = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * ft_wdc(s, c) + 1)))
		return (NULL);
	arr[ft_wdc(s, c)] = NULL;
	while (s[i])
	{
		j = 0;
		if (s[i] != c)
		{
			while (s[i + j] && s[i + j] != c)
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
