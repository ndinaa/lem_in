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


void	create_room(t_main *list, char *line)
{
	if (ft_strcmp(line, "##"))
}


void	read_map(t_main *list)
{
	char *line;

	get_ants(list, line);
	while(get_next_line(0, &line))
	{
		if (line[0] == '#')
			ft_putendl("room");
	}
}
