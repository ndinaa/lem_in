/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 12:27:24 by hlibago           #+#    #+#             */
/*   Updated: 2017/08/16 13:42:24 by hlibago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countp(char const *s, char c)
{
	size_t	ret;
	size_t	i;

	if (*s == '\0')
		return (0);
	ret = 0;
	if (*s != c)
		ret = 1;
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			ret++;
		i++;
	}
	return (ret);
}

static int		ft_lenw(const char *s, char c)
{
	int			len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**str;
	int			nr_word;
	int			i;

	i = 0;
	if (!s || !c)
		return (NULL);
	nr_word = ft_countp((const char *)s, c);
	str = (char **)malloc(sizeof(*str) * (ft_countp((const char *)s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (nr_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		str[i] = ft_strsub((const char *)s, 0, ft_lenw((const char *)s, c));
		if (str[i] == NULL)
			return (NULL);
		s = s + ft_lenw(s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
