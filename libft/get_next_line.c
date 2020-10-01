/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:24:05 by jpieczar          #+#    #+#             */
/*   Updated: 2019/07/03 08:22:48 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joindel(char *enil, char *buff)
{
	char	*str;

	str = ft_strjoin(enil, buff);
	free(enil);
	return (str);
}

int		ft_readstr(int fd, char **enil)
{
	char	buff[BUFF_SIZE + 1];
	int		res;

	while ((res = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (enil[fd] == NULL)
			enil[fd] = ft_strdup(buff);
		else
			enil[fd] = ft_joindel(enil[fd], buff);
		if (ft_strchr(enil[fd], '\n'))
			break ;
	}
	return (res);
}

int		ft_movestr(char **line, char **enil)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*enil)[i] != '\n' && (*enil)[i] != '\0')
		i++;
	if (ft_strchr(*enil, '\n') != NULL)
	{
		*(ft_strchr(*enil, '\n')) = '\0';
		*line = ft_strsub(*enil, 0, i);
		temp = ft_strdup(ft_strchr(*enil, '\0') + 1);
		free(*enil);
		*enil = ft_strdup(temp);
		free(temp);
		if ((*enil)[0] == '\0')
			ft_strdel(enil);
	}
	else
	{
		*line = ft_strdup(*enil);
		ft_strdel(enil);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*enil[1024];
	int			res;

	res = 0;
	if (fd < 0 || (read(fd, NULL, 0)) < 0 || !line)
		return (-1);
	res = ft_readstr(fd, enil);
	if (res < 0)
		return (-1);
	if (res == 0 && !enil[fd])
		return (0);
	return (ft_movestr(line, &enil[fd]));
}
