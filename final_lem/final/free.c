/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:02:53 by hlibago           #+#    #+#             */
/*   Updated: 2018/04/28 13:58:36 by hlibago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_tab(char **tab)
{
	int		i;

	i = -1;
	if (!(tab[i]))
		return ;
	else
	{
		while (tab[++i] != NULL)
			free(tab[i]);
		free(tab);
	}
}

void		free_edges(t_edges *ptr)
{
	t_edges *tmp;

	tmp = ptr;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		(tmp) ? free(tmp) : 0;
	}
}

void		free_rooms(t_room *ptr)
{
	t_room *tmp;

	tmp = ptr;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(ptr->value);
		free_edges(tmp->edges);
		free(tmp);
	}
}

void		free_list(t_path *path)
{
	t_path	*tmp;

	tmp = path;
	while (path != NULL)
	{
		tmp = path;
		path = path->next;
		free(tmp);
	}
}

void		free_queue(t_queue *ptr)
{
	t_queue *tmp;

	tmp = ptr;
	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}
