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
	return (new);
}

void	print_list(t_main *list)
{
		printf("%d\n",list->error);
		printf("%d\n", list->ants);
}


int	main()
{
	t_main *new;

	new = initialize();
	read_map(new);
	print_list(new);
}
