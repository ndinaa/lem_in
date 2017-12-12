/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 08:37:40 by hlibago           #+#    #+#             */
/*   Updated: 2017/12/12 11:20:24 by hlibago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct s_links
{
    struct s_links *next;
    struct s_room  *room;
}               t_links;

typedef struct s_room{

    char	*id;
    int		is_start;
    int		is_end;
    int		num_of_lem;
	struct s_room *next;

}              t_room;


int             has_char(char **line, char c);
void      		save_data(char  **input);
int             is_num(char *str);
t_room   		*make_room(char **input, int start_end, int num_of_lem);
t_room          *ft_get_data(char **input);
t_room          *read_input(char **line, int num_of_lem);
char            **get_link(char **line);

#endif
