/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibago <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:14:54 by hlibago           #+#    #+#             */
/*   Updated: 2018/04/07 14:24:13 by hlibago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		build_path(t_path **path, char *room)
{
	t_path	*new;

	new = *path;
	if (*path == NULL)
	{
		*path = (t_path *)malloc(sizeof(t_path));
		(*path)->room = room;
		(*path)->next = NULL;
	}
	else
	{
		while (new->next != NULL)
			new = new->next;
		new->next = (t_path *)malloc(sizeof(t_path));
		new->next->room = room;
		new->next->next = NULL;
	}
}

int			move_ants(t_main *list, int iter, int ant)
{
	int		print;
	t_path	*path;

	path = list->path->next;
	print = iter - ant;
	while (print && path != NULL)
	{
		if (print == 1)
		{
			ft_putchar('L');
			ft_putnbr(ant + 1);
			ft_putchar('-');
			ft_putstr(path->room);
			ft_putchar(' ');
			if (((ant + 1) == list->ants) && !path->next)
				return (1);
		}
		path = path->next;
		print--;
	}
	return (0);
}

void		print_ants(t_main *list)
{
	int		iter;
	int		ant;
	int		done;
	t_path	*path;

	iter = 1;
	done = 0;
	path = list->path->next;
	ft_putchar('\n');
	while (!done)
	{
		ant = -1;
		while (++ant < list->ants)
			done = move_ants(list, iter, ant);
		ft_putchar('\n');
		iter++;
	}
}
