/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_npc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:49:58 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/21 20:46:22 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_sprite_tempo(void)
{
	usleep(150000);
}

static void	ft_npc_pos(t_map *map)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	y = -1;
	while (i < map->nb_npc && ++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			if (map->map[y][x] == 'N')
				ft_pos_init(&(map->npc[i++]), x, y);
	}
}

void	ft_display_npc(t_data *data)
{
	size_t		i;
	int			x;
	int			j;
	t_map		*map;

	i = 0;
	x = -1;
	j = -1;
	map = &(data->maps[data->i]);
	ft_npc_pos(map);
	while (++x + INDPUMP1 <= INDPUMPR && ++j < 14)
	{
		i = -1;
		while (++i < map->nb_npc)
		{
			ft_img_towindow(data, INDPUMP1 + x, map->npc[i].x, \
			map->npc[i].y);
		}
		ft_sprite_tempo();
		if (x + 1 + INDPUMP1 == INDPUMPR)
			x = -1;
	}
}

int	ft_check_npc(t_data *data)
{
	size_t	i;
	t_pos	*pos;

	if (!data->maps[data->i].nb_npc)
		return (-1);
	i = -1;
	pos = &(data->maps[data->i].p);
	while (++i < data->maps[data->i].nb_npc)
	{
		if (pos->x == data->maps[data->i].npc[i].x && \
		pos->y == data->maps[data->i].npc[i].y)
		{
			data->bonus = 2;
			ft_img_towindow(data, INDMEAT, pos->x, pos->y);
			ft_printf("Press a key to continue\n");
			return (1);
		}
	}
	return (2);
}
