/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:44:45 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/09 15:57:10 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_black_towindow(t_data *data, size_t i, size_t x, size_t y)
{	
	mlx_put_image_to_window(data->mlx, data->win, data->imgs[i].mlx_img, \
	x * TILE_SIZE, y * TILE_SIZE);
}

void	ft_update_counter(t_data *data)
{
	t_map	*map;
	char	*count;
	char	*movecount;

	map = &(data->maps[data->i]);
	ft_black_towindow(data, INDFLOOR1, 0, 0);
	ft_black_towindow(data, INDFLOOR1, 1, 0);
	ft_black_towindow(data, INDFLOOR1, 2, 0);
	ft_black_towindow(data, INDFLOOR1, 3, 0);
	ft_black_towindow(data, INDFLOOR1, 4, 0);
	movecount = "move count = ";
	count = ft_itoa(map->p.moves);
	movecount = ft_strjoin(movecount, count);
	mlx_string_put(data->mlx, data->win, 10, 20, 0x0000FF, movecount);
	free(count);
	free(movecount);
}

// void	ft_displaymovecount(t_data *data)
// {
// 	(void)data;
// 	// map = &(data->maps[data->i]);
// 	// mlx_string_put(data->mlx, data->win, 0, 0, 0xFF0000, "Hello Word");
// 	// ft_printf("moves: %d\n", data->maps[data->i].p.moves); 
//10 20 & 100 20 && mur == (0,3) et (0,4)
// }
