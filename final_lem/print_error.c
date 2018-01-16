#include "lem_in.h"

void		print_error(int i)
{
	if (i == 1)
		ft_putendl("Error : The number of ants is invalid");
	else if (i ==2)
		ft_putendl("Error : you can not have more than one strating rooms");
	else if (i == 3)
		ft_putendl("Error : you can not have more than one end rooms");
	else if (i == 4)
		ft_putendl("Error : A room can not start with a letter '#' or 'L'");
	else if (i == 5 || i == 6)
		ft_putendl("Error : invalid room");

}
