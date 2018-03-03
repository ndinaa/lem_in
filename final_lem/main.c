#include "lem_in.h"

t_main		*initialize()
{
	t_main *new;

	if (!(new = (t_main *)malloc(sizeof(t_main))))
		return (NULL);
	new->start = NULL;
	new->end = NULL;
	new->error = 0;
	new->ants = 0;
	new->rooms = NULL;
	new->queue = NULL;
	new->path = NULL;
	return (new);
}

void	free_em_up(t_main *main)
{
	if (main->path)
		free_list(main->path);
	/*if (main->rooms)
		free_rooms(main->rooms);*/
	if (main->queue)
		free_queue(main->queue);
	if (main->start)
		free(main->start);
	if (main->end)
		free(main->end);
	free(main);
}

int	main()
{
	t_main *new;

	new = initialize();
	read_map(new);
	if (!new->error && new->start && new->end && ft_strcmp(new->start, new->end) != 0)
		bfs(new);
	if (!new->error && new->path)
		print_ants(new);
	else
		ft_putendl("An error was encountered");
		free_em_up(new);
	return (0);
}
