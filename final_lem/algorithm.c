/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:37:20 by hlibago           #+#    #+#             */
/*   Updated: 2018/04/07 15:33:13 by hlibago          ###   ########.fr       */
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
	t_room	*current;
	t_queue	*que;
	t_room	*child;

	current = get_room(list->rooms, list->start);
	current->searched = 1;
	queue(&list, current);
	que = list->queue;
	while (que != NULL)
	{
		current = dequeue(&list->queue, current);
		if (ft_strcmp(current->value, list->end) == 0)
		{
			create_path(&(list->path), current);
			return ;
		}
		while (current->edges != NULL)
		{
			child = (t_room *)current->edges->room;
			if (!child->searched)
			{
				child->searched = 1;
				child->parent = current;
				queue(&list, child);
			}
			current->edges = current->edges->next;
		}
	}
}
