


#include "../libft/libft.h"
#include "lem_in.h"
#include <unistd.h>

char        *ft_print_map()
{
    char    *line;
    char    *buff;

    buff = ft_strnew(1);
    while(get_next_line(0, &line))
    {
        //ft_putendl(line);
        buff= ft_strjoin(buff, line);
        buff = ft_strjoin(buff, "\n");
    }
    return (buff);
}

#include <stdio.h>

static void    print_list(t_room **room)
{
        t_room  *tmp;
	
        tmp = *room;
        while (tmp)
        {
				ft_putstr("id = ");
                ft_putendl(tmp->id);
                ft_putstr("start = ");
                ft_putendl(ft_itoa(tmp->is_start));
                ft_putstr("end = ");
                ft_putendl(ft_itoa(tmp->is_end));
                ft_putstr("ants= ");
                ft_putendl(ft_itoa(tmp->num_of_lem));
		ft_putendl("\n");
                tmp = tmp->next;
        }
}

int     main()
{
    char    *line;
    char    **ret;
    t_room  *new;
    char    **input;

    line = ft_print_map();
    ret = ft_strsplit(line, '\n');
    //new = ft_get_data(ret);
    //print_list(&new);
    get_link(ret);
}
