#include "lem_in.h"

static void	print_list(t_main *list)
{
	printf("%d\n", list->ants);
	printf("%d\n", list->error);	
}

static t_main	*initialize(t_main *list)
{
	t_main *new;

	if(!(new = (t_main *)malloc(sizeof(t_main))))
		return (NULL) ;
	else
	{
		new->start = NULL;
		new->end = NULL;
		new->ants = 0;
		new->error = 0;
		new->rooms = NULL;
	}
	return (new);
}

void 	print_room(t_main *list)
{
	t_room *new;
	t_room *room;

	new = list->rooms;
	while (new)
	{
		printf("%s   ", new->value);
		printf("edges :");
		while (new->edges != NULL)
		{
			room = (t_room *)new->edges->room;
			printf("%s", room->value);
			new->edges = new->edges->next;
		}
		printf("\n");
		new = new->next;
	}
}	

static	int	read_data(char *line, t_main *list)
{
	get_ants(line, list);
	while(get_next_line(0, &line) > 0 && !list->error)
	{
		ft_putendl(line);
		if(line[0] == '#')

			commands(line, list);
		else if (check_char(line, ' ') == 2 && !list->error)
			create_room(line, list, 2);
		else if (check_char(line, '-') == 1 && !list->error)
			create_edges(line, list);
		else if (ft_strlen(line) < 2)
			list->error = 1;
	}
	return(0);
}



int	main(void)
{
	char *line;
	t_main *list;
	
	list = initialize(list);
	read_data(line, list);
	bfs(list);
}
