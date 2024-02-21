/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_npc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:22:09 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/21 20:44:27 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static int	npc_can_move(char **map, size_t x, size_t y)
{
	if (map[y][x] == '0' || map[y][x] == 'C')
		return (1);
	return (0);
}

static int	ft_dir_npc(t_pos *pos, t_pos npc, int dir)
{
	if (!dir && ft_pos_init(pos, npc.x + 1, npc.y))
		pos->dir = dir;
	if (dir == 1 && ft_pos_init(pos, npc.x - 1, npc.y))
		pos->dir = dir;
	if (dir == 2 && ft_pos_init(pos, npc.x, npc.y + 1))
		pos->dir = dir;
	if (dir == 3 && ft_pos_init(pos, npc.x, npc.y - 1))
		pos->dir = dir;
	return (1);
}

static int	rand_pos(char **map, t_pos *pos, t_pos npc)
{
	int	r;

	r = ft_random_number();
	while (ft_dir_npc(pos, npc, r) && !npc_can_move(map, pos->x, pos->y))
		r = ft_random_number();
	return (1);
}

void	ft_move_npc(t_data *data)
{
	t_map		*map;
	t_pos		pos;
	size_t		i;

	ft_seed_time();
	map = &(data->maps[data->i]);
	i = -1;
	while (++i < map->nb_npc)
	{
		if (rand_pos(map->map, &pos, map->npc[i]))
		{
			ft_diplay_corb(data, map->npc[i].x, map->npc[i].y);
			ft_img_towindow(data, INDPUMPR + pos.dir, pos.x, pos.y);
			map->npc[i] = pos;
		}
	}
}
