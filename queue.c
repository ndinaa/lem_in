#include "lem_in.h"

void		queue(t_main **list, t_room *room)
{
	t_queue  *new;
	
	new = (*list)->queue;
	if ((*list)->queue == NULL)
	{
		(*list)->queue = (t_queue *)malloc(sizeof(t_queue));
		(*list)->queue->room = room;
		(*list)->queue->next = NULL;
		return ;
	}
	else
	{
		while(new != NULL)
			new = new->next;
		new->next= (t_queue *)malloc(sizeof(t_queue));
		new->next->room = room;
		new->next->next = NULL;
	}
	
	
}

t_room *dequeue(t_queue **queue)
{
	t_queue *que;
	t_room *room;

	if (*queue == NULL)
		return (NULL);
	que = *queue;
	*queue = que->next;
	room = que->room;
	free(que);
	return (room);
}
