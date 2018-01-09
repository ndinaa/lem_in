#include "lem_in.h"

int	get_ants(char *line, t_main *list)
{
	int 	ants;
	
	if(get_next_line(0, &line) > 0)
	{	
		ft_putendl(line);
		ants = ft_atoi(line);
		if(ants <= 0)
		{
			list->error = 1;
			free(line);
			return (0);
		}
		list->ants = ants;
		return (1);
	}
	return (0);
}

static void	check_coords(t_main *list, char *x, char *y)
{
	while (*x)
	{
		if (!ft_isdigit(*x))
			list->error = 1;
		x++;
	}
	while (*y)
	{
		if (!ft_isdigit(*y))
			list->error = 1;
		y++;
	}
	
}

void		create_room(char *line, t_main *list, int i)
{
	char **tab;
	
	tab = ft_strsplit(line, ' ');
	if(tab[0] && tab[1] && tab[2] && !tab[3])
	{
		if (tab[0][0] == 'L' || tab[0][0] == '#')
			list->error = 1;
		check_coords(list, tab[1], tab[2]);
		add_to_room(&list, ft_strdup(tab[0]), ft_atoi(tab[1]), ft_atoi(tab[2]));
		if (!i)
			list->start = ft_strdup(tab[0]);
		else if (i == 1)
			list->end = ft_strdup(tab[0]);
	}
	else 
		list->error = 1;
}

int	commands(char *line, t_main *list)
{
	char	*temp;

	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
	{
		if (line[2] == 's')
		{
			if (list->start != NULL)
				list->error = 1;
			get_next_line(0, &temp);
			create_room(temp, list, 0);
		}
		else if (line[2] == 'e')
		{
			if (list->end != NULL)
				list->error = 1;
			get_next_line(0, &temp);
			create_room(temp, list, 1);				
		}
		ft_putendl(temp);
		return (1);
	}
	return (0);
}
