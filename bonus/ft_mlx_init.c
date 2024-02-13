/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:33:33 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/09 15:22:01 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_win_init(t_data *data)
{
	data->win = mlx_new_window(data->mlx, \
				((data->maps[data->i].width + 2) * TILE_SIZE), \
				((data->maps[data->i].height + 2) * TILE_SIZE), "Cook the cat");
	if (!(data->win))
		ft_error_malloc(data, 0);
}

void	ft_mlx_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!(data->mlx))
		ft_error_malloc(data, 0);
	ft_win_init(data);
}
