#include "lem_in.h"

void	get_ants(t_main *list, char *line)
{
	int	ants;

	if (get_next_line(0, &line))
	{
		ft_putendl(line);
		ants = ft_atoi(line);
		check_coords(list, line, line);
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

	i = 0;
	while (x[i] && x[i] != '#')
	{
		if (ft_isdigit(x[i]) == 0)
		{
			list->error = 1;
		}
		i++;
	}
	i = 0;
	while (y[i] && y[i] != '#')
	{
		if (ft_isdigit(y[i]) == 0)
		{
			list->error = 1;
		}
		i++;
	}
}

char	*c(char *line)
{
	char	*tmp;
	int		x = 0;

	tmp = ft_strnew(ft_strlen(line) + 1);
	while (line[x] && !(line[x] == '#' &&
				line[x + 1] != '#' && line[x - 1] != '#'))
	{
		tmp[x] = line[x];
		x++;
	}
	(line) ? ft_putendl(line) : 0;
	(line) ? free(line) : 0;
   	tmp[x] = '\0';
	return (tmp);   
}

void	commands(t_main *list, char  *line)
{
	char *temp;
	
	temp = NULL;
	if (ft_strcmp(line, "##start") == 0)
	{
		if (list->start != NULL)
			list->error = 1;
		get_next_line(0, &temp);
		temp = c(temp);
		create_room(&list, temp, 0);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (list->end != NULL)
			list->error = 1;
		get_next_line(0, &temp);
		temp = c(temp);
		create_room(&list, temp, 1);
	}
	if (temp)
		free(temp);
}


void	read_map(t_main *list)
{
	char *line;

	get_ants(list, line);
	while(get_next_line(0, &line) > 0)
	{
		line = c(line);
		if (line[0] == '#')
			commands(list, line);
		else if ((check_char(line, ' ')) > 0)
			create_room(&list, line, 3);
		else if ((check_char(line, '-')) > 0)
			create_edges(list, line);
		else if (ft_strlen(line) < 3)
			list->error = 1;
		free(line);
	}
}
