#ifndef LEM_IN_H
# define LEM_IN_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct 	s_main{
	
	char	*start;
	char 	*end;
	int 	error;
	int 	ants;

}				t_main;

void	read_map(t_main *list);
void	create_room(t_main **list, char *line, int i);
void	check_coords(t_main *list, char *x, char *y);
#endif
