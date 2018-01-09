/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:25:04 by hlibago           #+#    #+#             */
/*   Updated: 2018/01/08 14:24:29 by hlibago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		bfs(t_main *list)
{
	t_room *current;
	t_room *child;
	
	current = find_room(list->rooms, list->start);
	current->searched = 1;
	queue(&list, current);
	while (list->queue != NULL)
	{
		current = dequeue(&list->queue);
		if (ft_strcmp(current->value, list->end) != 0)
		{
			ft_putendl(current->value);
		}
		while (current->edges)
		{
			child = (t_room *)current->edges->room;
			if (!child->searched)
			{
				child->parent = current;
				child->searched = 1;
				queue(&list, child);
			}
			current->edges = current->edges->next;
		}
		
	}
}
