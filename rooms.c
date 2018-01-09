#include "lem_in.h"

static int 	exists(t_main **list, char *value, int x, int y)
{
	t_room *new;

	new = (*list)->rooms;
	if (new != NULL)
	{
		if (ft_strcmp(new->value, value) == 0 || (new->x == x && new->y == y))
		{
			(*list)->error = 1;
			return (1);
		}
	}
	return (0);
}

void	add_to_room(t_main **head, char *value, int x, int y)
{
	t_room *new;

	if (exists(head, value, x, y) == 1)
		return ;
	if((*head)->rooms == NULL)
	{
		(*head)->rooms = (t_room *)malloc(sizeof(t_room));
		(*head)->rooms->value = value;
		(*head)->rooms->parent =  NULL;
		(*head)->rooms->searched = 0;
		(*head)->rooms->edges = NULL;
		(*head)->rooms->parent = NULL;
		(*head)->rooms-> x = x;
		(*head)->rooms-> y = y;
		(*head)->rooms->next = NULL;
		return ;
	}
	new = (t_room *)malloc(sizeof(t_room));
	new->value = value;
	new->parent = NULL;
	new->searched = 0;
	new->edges = NULL;
	new->parent = NULL;
	new->x = x;
	new->y = y;
	new->next = (*head)->rooms;
	(*head)->rooms = new;
}

void	add_to_edges(t_room **room1, t_room **room2)
{
	t_edges *new_edge;

	if ((*room1)->edges == NULL)
	{
		(*room1)->edges = (t_edges *)malloc(sizeof(t_edges));
		(*room1)->edges->room = *room2;
		(*room1)->edges->next = NULL;
		return ;
	}
	new_edge =  (t_edges *)malloc(sizeof(t_edges));
	new_edge->room = *room2;
	new_edge->next = (*room1)->edges;
	(*room1)->edges = new_edge;
}

t_room		*find_room(t_room *room, char *value)
{
	while (room)
	{
		if (ft_strcmp(room->value, value) == 0)
			return (room);
		room = room->next;
	}
	return (NULL);
}

int		join_rooms(t_room *r1, t_room *r2)
{
	if (r1 == NULL || r2 == NULL)
		return (-1);
	if (ft_strcmp(r1->value, r2->value) == 0)
		return (-1);
	add_to_edges(&r1, &r2);
	add_to_edges(&r2, &r1);
	return (1);
}	

void		create_edges(char *line, t_main *list)
{
	char **tab;
	t_room *r1;
	t_room *r2;

	tab = ft_strsplit(line, '-');
	if (tab[0] && tab[1] && !tab[2])
	{
		r1 = find_room(list->rooms, tab[0]);
		r2 = find_room(list->rooms, tab[1]);
		if (!r1 || !r2)
			list->error = 1;
		join_rooms(r1, r2);
	}
	else
		list->error = 1;
}
