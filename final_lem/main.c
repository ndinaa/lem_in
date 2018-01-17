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
	new->start = NULL;
	new->end = NULL;

	return (new);
}

void	print_room(t_room *room)
{
	while (room)
	{
		printf("%s", room->value);
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
	//print_list(new);
}
