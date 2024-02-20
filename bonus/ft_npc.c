/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_npc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:22:09 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/20 17:39:37 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static int	npc_can_move(char **map, size_t x, size_t y)
{
	if (map[y][x] == '0' || map[y][x] == 'C')
		return (1);
	return (0);
}

static int	is_pos_player(char **map, t_pos *pos, t_pos npc, t_pos p)
{
	int	x;

	x = -1;
	if (p.y == npc.y && p.x == npc.x + 1 && ft_pos_init(pos, npc.x + 1, npc.y))
		return (0);
	else if (npc_can_move(map, npc.x + 1, npc.y))
		x--;
	if (p.y == npc.y && p.x == npc.x - 1 && ft_pos_init(pos, npc.x - 1, npc.y))
		return (1);
	else if (npc_can_move(map, npc.x - 1, npc.y))
		x--;
	if (p.y == npc.y + 1 && p.x == npc.x && ft_pos_init(pos, npc.x, npc.y + 1))
		return (2);
	else if (npc_can_move(map, npc.x, npc.y + 1))
		x--;
	if (p.y == npc.y - 1 && p.x == npc.x && ft_pos_init(pos, npc.x, npc.y - 1))
		return (3);
	else if (npc_can_move(map, npc.x, npc.y - 1))
		x--;
	return (x);
}

static int	init_from_dir(t_pos *pos, t_pos foe, int dir)
{
	if (!dir && ft_pos_init(pos, foe.x + 1, foe.y))
		pos->dir = dir;
	if (dir == 1 && ft_pos_init(pos, foe.x - 1, foe.y))
		pos->dir = dir;
	if (dir == 2 && ft_pos_init(pos, foe.x, foe.y + 1))
		pos->dir = dir;
	if (dir == 3 && ft_pos_init(pos, foe.x, foe.y - 1))
		pos->dir = dir;
	return (1);
}

static int	rand_pos(char **map, t_pos *pos, t_pos foe, t_pos p)
{
	int	r;

	ft_seed_time();
	r = is_pos_player(map, pos, foe, p);
	if (r == -1)
		return (0);
	if (r >= 0)
		return (pos->dir = r, 1);
	r = ft_random_number();
	while (init_from_dir(pos, foe, r) && !npc_can_move(map, pos->x, pos->y))
		r = ft_random_number();
	return (1);
}

void	ft_diplay_corb(t_data *data, size_t x, size_t y)
{
	t_map	*map;

	map = &(data->maps[data->i]);
	if (map->map[y][x] == 'C' && map->nb_collect)
		ft_img_towindow(data, INDCOLLECT1, x, y);
	else
		ft_img_towindow(data, INDBACKG, x, y);
}

void	move_npc(t_data *data)
{
	t_map		*map;
	t_pos		pos;
	size_t		i;

	map = &(data->maps[data->i]);
	i = -1;
	while (++i < map->nb_npc)
	{
		if (rand_pos(map->map, &pos, map->npc[i], map->p))
		{
			ft_diplay_corb(data, map->npc[i].x, map->npc[i].y);
			ft_img_towindow(data, INDPUMPR + pos.dir, pos.x, pos.y);
			map->npc[i] = pos;
		}
	}
}
