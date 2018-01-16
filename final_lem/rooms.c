#include "lem_in.h"


void	add_to_room(t_main **list, char *value, int x, int y)
{
	t_room *new;

	if ((*list)->room == NULL)
	{
		
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
		check_coords(*list, tab[1], tab[2]);
		add_to_room(&list,  value, x, y);
	}
}
