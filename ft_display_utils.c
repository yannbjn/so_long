/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:23:14 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/20 17:35:23 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_img_towindow(t_data *data, size_t i, size_t x, size_t y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[i].mlx_img, \
	x * TILE_SIZE, y * TILE_SIZE);
}

void	ft_display_eorb(t_data *data, size_t x, size_t y)
{
	t_map	*map;

	map = &(data->maps[data->i]);
	if (map->map[y][x] == 'E' && map->nb_collect)
		ft_img_towindow(data, INDCLOSEDE, x, y);
	else
		ft_img_towindow(data, INDBACKG, x, y);
}
