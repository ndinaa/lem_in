/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:11:56 by hlibago           #+#    #+#             */
/*   Updated: 2017/08/04 10:12:04 by hlibago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbrlng;

	nbrlng = (long)n;
	if (nbrlng < 0)
	{
		ft_putchar_fd('-', fd);
		nbrlng *= -1;
	}
	if (nbrlng >= 10)
	{
		ft_putnbr_fd(nbrlng / 10, fd);
		ft_putnbr_fd(nbrlng % 10, fd);
	}
	else
	{
		ft_putchar_fd(nbrlng + '0', fd);
	}
}
