/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:24:03 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/21 16:43:24 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	exit_level(t_data *data)
{
	t_map	*map;

	map = &(data->maps[data->i]);
	data->bonus = 3;
	ft_display_eorb(data, map->p.x, map->p.y);
	ft_img_towindow(data, INDCOOK5, map->exit.x, map->exit.y);
	map->p.moves++;
	ft_put_counter(data);
	ft_printf("Press a key to go to next lvl if there is one\n");
}

void	new_move(t_data *data, t_pos pos, size_t x, size_t y)
{
	int	i;

	i = ft_move_char(data, pos, x, y);
	if (!i)
		exit_level(data);
	if (i == 1)
	{
		check_for_npc(data);
		move_npc(data);
		check_for_npc(data);
	}
}

int	ft_move_char(t_data *data, t_pos pos, size_t x, size_t y)
{
	t_map	*map;

	map = &(data->maps[data->i]);
	ft_display_char(data);
	if (!(map->nb_collect) && map->map[y][x] == 'E')
		return (0);
	if (map->map[y][x] != '1')
	{
		map->p.x = x;
		map->p.y = y;
		map->p.moves++;
		ft_display_char(data);
		ft_put_counter(data);
		ft_display_eorb(data, pos.x, pos.y);
		if (map->map[y][x] == 'C' && map->nb_collect--)
		{
			map->map[y][x] = '0';
			if (!(map->nb_collect))
				ft_img_towindow(data, INDOPENE, map->exit.x, map->exit.y);
		}
		return (1);
	}
	return (-1);
}

void	ft_display_char(t_data *data)
{
	t_map	*map;

	map = &(data->maps[data->i]);
	if (map->map[map->p.y][map->p.x] == 'E' && map->nb_collect)
		ft_img_towindow(data, INDCATBBQ, map->p.x, map->p.y);
	else if (map->map[map->p.y][map->p.x] == 'C')
		ft_img_towindow(data, INDCATBURG, map->p.x, map->p.y);
	else
		ft_img_towindow(data, INDCATMVD1 + map->p.dir, \
		map->p.x, map->p.y);
}
