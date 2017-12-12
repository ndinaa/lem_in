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

char    get_link(char **line)
{
    char **link;

    link = NULL;
    while(*line)
    {
		ft_putendl(*line++);
	}
	return NULL;
}

/*t_links     ft_make_links(t_room **room, char **line)
{
    char    **link;
    t_room  *room1;
    t_room  *room2;

    room1 = room;
    room2 = room;



}*/


