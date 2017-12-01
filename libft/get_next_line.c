/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:04:11 by hlibago           #+#    #+#             */
/*   Updated: 2017/12/01 03:35:48 by hlibago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read(const int fd, char **container)
{
	int			ret;
	char		*buff;
	char		*tmp;

	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	tmp = ft_strjoin(*container, buff);
	free(*container);
	*container = tmp;
	free(buff);
	return (ret);
}

static void		free_join(char **holder, char *s1, char *s2)
{
	char		*tmp;

	tmp = *holder;
	*holder = ft_strjoin(s1, s2);
	free(tmp);
}

static int		validator(char **container, int fd, char **end_of_line)
{
	int			ret;

	if (*container == NULL)
		*container = (char *)malloc(sizeof(char));
	if (*container == NULL || fd < 0 || BUFF_SIZE < 0)
		ret = -1;
	else
		ret = 1;
	*end_of_line = ft_strchr(*container, '\n');
	return (ret);
}

static void		free_duplicate(char **container, char *s)
{
	char		*tmp;

	tmp = *container;
	*container = ft_strdup(s);
	free(tmp);
}

int				get_next_line(const int fd, char **line)
{
	static char		*container = NULL;
	char			*end_of_line;
	int				ret;

	if (validator(&container, fd, &end_of_line) == -1)
		return (-1);
	while (end_of_line == NULL)
	{
		ret = ft_read(fd, &container);
		if (ret == 0)
		{
			if (ft_strlen(container) == 0)
				return (0);
			free_join(&container, container, "\n");
			end_of_line = ft_strchr(container, '\n');
		}
		else if (ret < 0)
			return (-1);
		else
			end_of_line = ft_strchr(container, '\n');
	}
	*line = ft_strsub(container, 0, ft_strlen(container) -
			ft_strlen(end_of_line));
	free_duplicate(&container, &(end_of_line[1]));
	return (1);
}
