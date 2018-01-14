/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:14:15 by hlibago           #+#    #+#             */
/*   Updated: 2017/08/04 10:14:21 by hlibago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	char			*str;
	unsigned int	counter;

	str = (char *)s;
	counter = 0;
	if (s)
	{
		while (str[counter])
		{
			str[counter] = '\0';
			counter++;
		}
	}
}
