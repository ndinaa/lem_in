#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <string.h>

typedef struct 			s_edges
{
		void		*room;
		struct s_edges 	*next; 
}				t_edges;

typedef struct  	s_room
{

	char		*value;
	int		x;
	int		y;
	t_edges 	*edges;
	int		searched;
	struct s_room	*parent;
	struct s_room 	*next;

}			t_room;


typedef struct		s_queue
{
	t_room		*room;
	struct	s_queue *next;
}			t_queue;

typedef struct		s_path
{
	char 		*room;
	struct s_path	*next;	

}			t_path;


typedef struct 	s_main
{
	
	char	*start;
	char 	*end;
	int 	error;
	int 	ants;
	t_room 	*rooms;
	t_queue *queue;
	t_path	*path;

}		t_main;

void	read_map(t_main *list);
void	create_room(t_main **list, char *line, int i);
void	check_coords(t_main *list, char *x, char *y);
void	print_error(int n);
int	check_char(char *str, int c);
void	create_edges(t_main *list, char *line);
t_room	*get_room(t_room *room, char *value);
void	bfs(t_main *list);
void	build_path(t_path **path, char *room);
void	print_ants(t_main *list);
void	free_tab(char **tab);
void	free_list(t_path *path);
void	free_edges(t_edges *ptr);
void	free_rooms(t_room *ptr);
void	free_queue(t_queue *ptr);

#endif
