/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 11:17:08 by jpieczar          #+#    #+#             */
/*   Updated: 2019/06/06 16:11:27 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	unsigned	int	i;
	size_t			len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while ((i < len) && (s[len - 1] == ' ' || s[len - 1] == '\n' ||
		s[len - 1] == '\t'))
		len--;
	if (len == i)
		return (ft_strnew(1));
	return (ft_strsub(s, i, (len - i)));
}
