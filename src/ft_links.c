/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:35:04 by hlibago           #+#    #+#             */
/*   Updated: 2017/12/12 16:34:59 by hlibago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "../libft/libft.h"

static int link_len(char **link)
{
	int i;

	i = 0;
	while(link[i])
		i++;
	return (i);
}

char    **get_link(char **line)
{
    char **link;

    link = NULL;
    if ((*line)[0] == '#' && (*line)[1] != '#')
    {
		return (NULL);
    }
    link = ft_strsplit(*line, '-');
    if (link_len(link) != 2 || ft_strcmp(link[0], link[1]) == 0)
    {
	while(*link != '\0')
	{
		free(*link++);
	}
	link = NULL;
    }
    return (link);
}



int     ft_make_links(t_room **room, char **line)
{
    char    **link;
    t_room  *room1;
    t_room  *room2;

    room1 = *room;
    room2 = *room;

    if(link = get_link(line))
    {
	while(ft_strcmp(room1->id, link[0]) != 0)
	{
		ft_putendl(link[0]);
	}
	return (1);
	
    }
    return (0);

}
