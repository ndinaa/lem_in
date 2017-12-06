/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 08:48:20 by hlibago           #+#    #+#             */
/*   Updated: 2017/12/04 09:20:20 by hlibago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include  "../libft/libft.h"


int      is_num(char *str)
{
        int             i;

        i = -1;
        while (str[++i] != '\0')
        {
                if (!(str[i] <= '9' && str[i] >= '0'))
                        return (0);
        }
        return (1);
}

int      has_char(char **line, char c)
{
        char    	*str;
        int             i;
        int             j;

        i = -1;
        j = 0;
        str = *line;
        if (str[0] == '#')
                return (0);
        while (str[++i])
        {
                if (str[i] == c)
                        j++;
        }
        return (j);
}

t_room   *make_room(char **input, int start_end, int num_of_lem)
{
        t_room  *room;

        room = (t_room *)malloc(sizeof(t_room));
        room->id = input[0];
        room->next = NULL;
        room->is_start = 0;
        room->is_end = 0;
        room->num_of_lem = 0;
      
        if (start_end == 1)
        {
                room->is_start = 1;
                room->num_of_lem = num_of_lem;
        }
        else if (start_end == 2)
        {
                room->is_end = 1;
        }
        return (room);
}


t_room   *read_input(char **line, int num_of_lem)
{
        char            **input;
        t_room          *room;

        int start_end = 1;
        while ((*line)[0] == '#' && (*line)[1] != '#')
        {
                return NULL;
        }
        if(ft_strcmp(*line, "##start") == 0 || ft_strcmp(*line, "##end")== 0)
        {
                if ((*line)[2] == 's')
                        start_end = 1;
                else 
                        start_end = 2;
		free(*line);
		line++;	
        }

        if(has_char(line, ' ') == 2)
        {
                input = ft_strsplit(*line, ' ');
                if(is_num(input[1]) && is_num(input[2]))
                {
                        room = make_room(input, start_end, num_of_lem);
                        return (room);
                }
        }
        return NULL;
}

static void    ft_add_room(t_room **head, t_room *new)
{
        t_room *tmp;

        if(*head == NULL)
                *head = new;
        else
        {
                 tmp = *head;
                 while(tmp->next)
                        tmp = tmp->next;
                  tmp->next = new;
                  new->next = NULL;

        }

}

t_room     *ft_get_data(char **input)
{
	int num_of_lem;
	t_room *room;
        t_room *head;
    
        num_of_lem = 0;
        head = NULL;
	while(*input && !has_char(input, '-'))
	{
                
             if (has_char(input, ' ') == 0 && num_of_lem == 0)
                num_of_lem = ft_atoi(*input);
             else if ((room = read_input(input, num_of_lem)))
                     ft_add_room(&head, room);
             else 
                        return (head);
             *input++;
        }
        return (head);
}
