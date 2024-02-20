/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:35:54 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/19 21:15:34 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	ft_pos_init(t_pos *pos, size_t x, size_t y)
{
	pos->x = x;
	pos->y = y;
	pos->moves = 0;
	pos->dir = 0;
	return (1);
}

void	ft_fill_map(t_map *map, char const *mapber)
{
	map->width = 0;
	map->height = 1;
	map->nb_collect = 0;
	map->nb_exit = 0;
	map->nb_p = 0;
	map->nb_npc = 0;
	map->map = NULL;
	map->mapber = mapber;
	map->npc = NULL;
	ft_pos_init(&(map->exit), -1, -1);
	ft_pos_init(&(map->p), -1, -1);
}

void	ft_fill_data(t_data *data, size_t n)
{
	data->mlx = NULL;
	data->win = NULL;
	data->maps = NULL;
	data->imgs = NULL;
	data->i = 0;
	data->n = n;
	data->bonus = -1;
}
