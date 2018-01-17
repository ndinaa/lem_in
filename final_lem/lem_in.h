#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <string.h>

typedef struct 			s_edges
{
		void			*room;
		struct s_edges *next; 
}						t_edges;

typedef struct  s_room{

	char		*value;
	int			x;
	int			y;
	t_edges 	*edges;

	struct s_room *next;

}		t_room;

typedef struct 	s_main{
	
	char	*start;
	char 	*end;
	int 	error;
	int 	ants;
	t_room 	*rooms;

}				t_main;

void	read_map(t_main *list);
void	create_room(t_main **list, char *line, int i);
void	check_coords(t_main *list, char *x, char *y);
void	print_error(int n);
int		check_char(char *str, int c);

#endif
