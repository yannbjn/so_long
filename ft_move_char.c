/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:55:47 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/21 18:05:28 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	ft_move_char(t_data *data, t_pos pos, size_t x, size_t y)
{
	t_map	*map;

	map = &(data->maps[data->i]);
	ft_display_char(data);
	if (!(map->nb_collect) && map->map[y][x] == 'E')
		next_map(data);
	else if (map->map[y][x] != '1')
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
	}
	return (1);
}
