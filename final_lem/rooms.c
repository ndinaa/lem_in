#include "lem_in.h"

void	add_to_room(t_main **list, char *value, int x, int y)
{
	t_room *new;

	if ((*list)->rooms == NULL)
	{
		(*list)->rooms = (t_room *)malloc(sizeof(t_room));
		(*list)->rooms->value = value;
		(*list)->rooms->x = x;
		(*list)->rooms->y = y;
		(*list)->rooms->searched = 0;
		return ;		
	}
	new = (t_room *)malloc(sizeof(t_room));
	new->value = value;
	new->x = x;
	new->y = y;
	new->searched = 0;
	new->next = (*list)->rooms;
	(*list)->rooms = new;
	
}

t_room 		*get_room(t_room *room, char *value)
{
	while (room != NULL)
	{
		if (ft_strcmp(room->value, value) == 0)
			return room;
		room = room->next;
	}
	return NULL;
}

void	add_edges(t_room **room1, t_room *room2)
{
	t_edges *new;

	if ((*room1)->edges == NULL)
	{
		(*room1)->edges = (t_edges *)malloc(sizeof(t_edges));
		(*room1)->edges->room = room2;
		(*room1)->edges->next = NULL;
		return ;
	}
	new = (t_edges *)malloc(sizeof(t_edges));
	new->room = room2;
	new->next = (*room1)->edges;
	(*room1)->edges = new;

}

void 	create_edges(t_main *list, char *line)
{
	char 	**tab;
	t_room *room1;
	t_room *room2;
	
	tab = ft_strsplit(line, '-');
	if (tab[0] && tab[1] && !tab[2])
	{
		room1 = get_room (list->rooms, tab[0]);
		room2 = get_room (list->rooms, tab[1]);
		if (!room1 || !room2)
			list->error = 7;
		add_edges(&room1, room2);
		add_edges(&room2, room1);
	}
}

void	create_room(t_main **list, char *line, int i)
{
	char 	**tab;
	int 	x;
	int 	y;
	char	*value;

	tab = ft_strsplit(line, ' ');
	value = ft_strdup(tab[0]);
	x = ft_atoi(tab[1]);
	y = ft_atoi(tab[2]);
	if (tab[0] && tab[1] && tab[2] && !tab[3])
	{
		if (tab[0][0] == 'L' || tab[0][0] == '#')
		{
			(*list)->error = 4; 
			return ;
		}
		//check_coords(*list, tab[1], tab[2]);
		add_to_room(&(*list),  value, x, y);
	}
	if (i == 0)
		(*list)->start = ft_strdup(tab[0]);
	else if (i == 1)
		(*list)->end = ft_strdup(tab[0]);
}
