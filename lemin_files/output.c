/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpieczar <jpieczar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:40:17 by jpieczar          #+#    #+#             */
/*   Updated: 2019/09/16 09:18:51 by jpieczar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	outputant(int ant, char *name)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(name);
}

void	starterror(void)
{
	ft_putendl("Path error.");
	exit(0);
}

void	linkerror(void)
{
	ft_putendl("Unknown room.");
	exit(0);
}



void	roomerror(void)
{
	ft_putendl("Provide a start and an end room.");
	exit(0);
}

void	anterror(void)
{
	ft_putendl("Provide ants");
	exit(0);
}
