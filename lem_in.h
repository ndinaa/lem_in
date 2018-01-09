#ifndef LEM_IN_H
# define LEM_IN_H

#include "libft/libft.h"
#include <stdio.h>

typedef	struct		s_edges{

	void		*room;
	struct	s_edges	*next;
}			t_edges;


typedef	struct		s_room{

	char		*value;
	int		searched;
	t_edges		*edges;
	int		x;
	int		y;
	struct s_room	*parent;
	struct s_room 	*next;

}			t_room;

typedef struct		s_queue{

	t_room		*room;
	struct	s_queue *next;
}			t_queue;

typedef struct		s_main{

	char		*start;
	char		*end;
	int		ants;
	int		error;
	t_room		*rooms;
	t_queue		*queue;

}			t_main;


int     get_ants(char *line, t_main *list);
int     commands(char *line, t_main *list);
void    add_to_room(t_main **head, char *value, int x, int y);
int	check_char(char *str, char c);
void	create_room(char *line, t_main *list, int i);
void	create_edges(char *line, t_main *list);
void	bfs(t_main *list);
t_room	*find_room(t_room *room, char *value);
void	queue(t_main **list, t_room *room);
void	bfs(t_main *list);
t_room	*dequeue(t_queue **queue);

#endif
