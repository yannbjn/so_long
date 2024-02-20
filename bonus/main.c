/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:08:10 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/20 17:06:23 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_put_future(t_data *data)
{
	char	*future;
	size_t	y;

	y = (data->maps[data->i].height + 2) * TILE_SIZE;
	future = "Press f for surprise";
	mlx_string_put(data->mlx, data->win, 10, y - 10, 0xFF0000, future);
}

void	ft_launch_game(t_data *data)
{
	ft_mlx_init(data);
	ft_sprites_init(data);
	ft_put_future(data);
	ft_display_map(data);
	ft_display_char(data);
	if (data->maps[data->i].nb_npc)
		ft_display_npc(data);
	data->bonus = 1;
	mlx_hook(data->win, KeyPress, KeyPressMask, &event_keypress, data);
	mlx_hook(data->win, DestroyNotify, 0, &on_destroy, data);
	mlx_loop(data->mlx);
}

int	main(int argc, const char **argv)
{
	t_data	data;

	if (argc < 2)
		ft_error_args();
	ft_fill_data(&data, argc - 1);
	ft_start_parse(argv, argc, &data);
	ft_launch_game(&data);
}

//PROTEGER LES RETOURS DES FONCTIONS DE LA MLX QUI MALLOC!!!!!!!!!!!!!!!!!!
//LEAKS PARSING