/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:40:47 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/07 14:24:36 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_display_corners(t_data *data, t_map *map)
{
	ft_img_towindow(data, INDCORNERUL, 0, 0);
	ft_img_towindow(data, INDCORNERUR, (map->width - 1), 0);
	ft_img_towindow(data, INDCORNERDL, 0, (map->height - 1));
	ft_img_towindow(data, INDCORNERDR, (map->width - 1), (map->height - 1));
}

static void	ft_display_wc(t_data *data, t_map *map)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (!y)
				ft_img_towindow(data, INDWALLU, x, y);
			else if (y == map->height - 1)
				ft_img_towindow(data, INDWALLD, x, y);
			else if (!x)
				ft_img_towindow(data, INDWALLL, x, y);
			else if (x == map->width - 1)
				ft_img_towindow(data, INDWALLR, x, y);
			else if (map->map[y][x] == '1')
				ft_img_towindow(data, INDWALLC, x, y);
			else if (map->map[y][x] == 'C')
				ft_img_towindow(data, INDCOLLECT1, x, y);
		}
	}
}

static void	ft_display_0(t_data *data, t_map *map)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			ft_display_e(data, x, y);
		}
	}
	ft_img_towindow(data, INDCLOSEDE, map->exit.x, map->exit.y);
}

void	ft_display_map(t_data *data)
{
	ft_display_0(data, &(data->maps[data->i]));
	ft_display_wc(data, &(data->maps[data->i]));
	ft_display_corners(data, &(data->maps[data->i]));
}
