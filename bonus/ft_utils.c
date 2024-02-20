/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:31:34 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/19 21:31:38 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"
#include <time.h>

void	next_map(t_data *data)
{
	mlx_loop_end(data->mlx);
	if (++(data->i) < data->n)
	{
		destroy_mlx(data);
		ft_launch_game(data);
	}
	ft_end_game("You won\n", data);
}

int	event_destroy(char *loseorwin, t_data *data)
{
	ft_end_game(loseorwin, data);
	return (0);
}

void	ft_seed_time(void)
{
	srand(time(NULL));
}

int	ft_random_number(void)
{
	int	rdnb;

	rdnb = rand() % 4;
	return (rdnb);
}

// void	ft_cook(t_data *data)
// {
// 	t_map	*map;
// 	size_t	j;

// 	map = &(data->maps[data->i]);
// 	j = -1;
// 	while (++j + INDCOOK1 <= INDCOOK4)
// 	{
// 		ft_img_towindow(data, INDCOOK1 + j, map->exit.x, map->exit.y);
// 		ft_sprite_tempo();
// 	}
// }

// int	ft_cook(t_data *data)
// {
// 	t_map	*map;
// 	int	j;
// 	int	x;

// 	map = &(data->maps[data->i]);
// 	j = -1;
// 	x = -1;
// 	while (++x + INDCOOK1 <= INDCOOK5 && ++j < 8)
// 	{
// 		ft_img_towindow(data, INDCOOK1 + x, map->exit.x, map->exit.y);
// 		usleep(190000);
// 		if (x + 1 + INDCOOK1 == INDCOOK5)
// 			x = -1;
// 	}
// 	ft_img_towindow(data, INDCOOK5, map->exit.x, map->exit.y);
// 	data->anim = 0;
// 	return (0);
// }
