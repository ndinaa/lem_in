


#include "../libft/libft.h"


char        *ft_print_map()
{
    char    *line;
    char    *buff;

    buff = ft_strnew(1);
    while(get_next_line(0, &line))
    {
        ft_putendl(line);
        buff= ft_strjoin(buff, line);
        buff = ft_strjoin(buff, "\n");
    }
    return (buff);
}

int     main(){
    
    char    *line;
    char    **ret;

    line = ft_print_map();
    ret = ft_strsplit(line, '\n');
    save_data(ret);



}

