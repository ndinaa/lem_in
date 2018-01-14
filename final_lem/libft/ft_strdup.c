/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:15:48 by hlibago           #+#    #+#             */
/*   Updated: 2017/08/10 09:30:40 by hlibago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *sc)
{
	size_t		i;
	char		*str;

	i = 0;
	if (!(str = (char*)malloc(sizeof(*str) * (ft_strlen(sc) + 1))))
		return (NULL);
	while (i < ft_strlen(sc))
	{
		str[i] = sc[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
