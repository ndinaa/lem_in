/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:37:20 by hlibago           #+#    #+#             */
/*   Updated: 2018/04/28 13:57:46 by hlibago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	queue(t_main **list, t_room *room)
{
	t_queue	*new;

	new = (*list)->queue;
	while ((*list)->queue == NULL)
	{
		(*list)->queue = (t_queue *)malloc(sizeof(t_queue));
		(*list)->queue->room = room;
		(*list)->queue->next = NULL;
		return ;
	}
	while (new->next != NULL)
		new = new->next;
	new->next = (t_queue *)malloc(sizeof(t_queue));
	new->next->room = room;
	new->next->next = NULL;
}

t_room	*dequeue(t_queue **queue, t_room *room)
{
	t_queue	*current;
	t_queue	*new;

	if (*queue == NULL)
		return (NULL);
	else
	{
		current = *queue;
		room = current->room;
		new = current->next;
		free(current);
		*queue = new;
	}
	return (room);
}

void	create_path(t_path **path, t_room *room)
{
	if (room == NULL)
		return ;
	create_path(path, room->parent);
	build_path(path, room->value);
}

void	bfs(t_main *list)
{
	list->current = get_room(list->rooms, list->start);
	list->current->searched = 1;
	queue(&list, list->current);
	list->que = list->queue;
	while (list->que != NULL)
	{
		list->current = dequeue(&list->queue, list->current);
		if (ft_strcmp(list->current->value, list->end) == 0)
		{
			create_path(&(list->path), list->current);
			return ;
		}
		while (list->current->edges != NULL)
		{
			list->child = (t_room *)list->current->edges->room;
			if (!list->child->searched)
			{
				list->child->searched = 1;
				list->child->parent = list->current;
				queue(&list, list->child);
			}
			list->current->edges = list->current->edges->next;
		}
	}
}
