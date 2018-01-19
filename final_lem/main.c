#include "lem_in.h"

t_main		*initialize()
{
	t_main *new;

	if (!(new = (t_main *)malloc(sizeof(t_main))))
		return (NULL);
	new->start = NULL;
	new->end = NULL;
	new->error = 0;
	new->ants = 0;
	new->rooms = NULL;
	new->queue = NULL;
	return (new);
}

void	print_room(t_room *room)
{
	t_room *temp;

	while (room)
	{
		printf("room %s\n", room->value);
		while (room->edges)
		{
			temp = (t_room *)room->edges->room;
			printf(" edge %s\n", temp->value);
			room->edges = room->edges->next;
		}
		room = room->next;
	}
}

void	print_list(t_main *list)
{
		printf("%d\n",list->error);
		printf("%d\n", list->ants);
		printf("%s\n", list->start);
		printf("%s\n", list->end);
}

int	main()
{
	t_main *new;

	new = initialize();
	read_map(new);
	print_room(new->rooms);
	bfs(new);
	//print_list(new);
}
