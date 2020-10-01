/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:12:42 by jpieczar          #+#    #+#             */
/*   Updated: 2019/08/28 11:28:39 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	int		i;
	long	res;
	int		mul;

	i = 0;
	res = 0;
	mul = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			mul = (-1);
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		res = ((res * 10) + (str[i] - 48));
		i++;
	}
	return (res * mul);
}
