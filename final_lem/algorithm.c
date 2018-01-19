#include "lem_in.h"


void		queue(t_main **list, t_room *room)
{
	t_queue *new;

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


t_room		*dequeue(t_queue **queue, t_room *room)
{

	t_queue *current;
	t_queue *new;

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


void		bfs(t_main *list)
{
	t_room *current;
	t_queue *new;
	t_queue *que;
	t_room *child;

	current = get_room(list->rooms, list->start);
	current->searched = 1;
	queue(&list, current);

	new = list->queue;
	int i = 1;
	while (que != NULL)
	{
		current = dequeue(&list->queue, current);
		if (ft_strcmp(current->value, list->end) == 0)
		{
			printf("reached the end");
			return ;
		}
		while (current->edges != NULL)
		{	
			child =  (t_room *)current->edges->room;			
			if (!child->searched)
			{
				
			}
		}
		que = que->next;
	}
	/*while(new)
	{		printf(" que %d %s\n", i , new->room->value);
		i++;
		new = new->next;
	}
	*/
}
