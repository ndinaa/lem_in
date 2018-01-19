#include "lem_in.h"

void	get_ants(t_main *list, char *line)
{
	int	ants;

	if (get_next_line(0, &line))
	{
		ft_putendl(line);
		ants = ft_atoi(line);
		if (ants <= 0)
		{
			list->error = 1;
			free(line);
			return ;
		}
		list->ants = ants;
		free(line);
	}
}

void	check_coords(t_main *list, char *x, char *y)
{
	int i;

	i =  0;
	while (x[i])
	{
		if (ft_isdigit(x[i]) == 0)
		{
			ft_putendl("yes");
			i++;
		}
	}
	i = 0;
	while (y[i])
	{
		if (ft_isdigit(y[i]) == 0)
		{
			ft_putendl("y");
			i++;
		}
	}
			ft_putendl("yes");
}

void	commands(t_main *list, char  *line)
{
	char *temp;

	if (ft_strcmp(line, "##start") == 0)
	{
		if (list->start != NULL)
			list->error = 2;
		get_next_line(0, &temp);
		create_room(&list, temp, 0);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (list->end != NULL)
			list->error = 3;
		get_next_line(0, &temp);
		create_room(&list, temp, 1);
	}
}


void	read_map(t_main *list)
{
	char *line;

	get_ants(list, line);
	while(get_next_line(0, &line) > 0 && !list->error)
	{
		ft_putendl(line);
		if (line[0] == '#')
			commands(list, line);
		else if ((check_char(line, ' ')) > 0 && !list->error)
			create_room(&list, line, 3);
		else if ((check_char(line, '-')) > 0 && !list->error)
			create_edges(list, line);
		else if (ft_strlen(line) > 3)
			list->error = 8;		
	}
	if (list->error)
		print_error(list->error);
}
