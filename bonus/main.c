/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:08:10 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/21 18:13:15 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_print_surprise(t_data *data)
{
	char	*future;
	size_t	y;

	y = (data->maps[data->i].height + 2) * TILE_SIZE;
	future = "Press f for surprise";
	mlx_string_put(data->mlx, data->win, 10, y - 10, 0xFF0000, future);
}

static void	ft_win_init(t_data *data)
{
	size_t	x;
	size_t	y;
	char	*lvl;
	char	*lvlnb;

	lvlnb = ft_itoa(data->i + 1);
	lvl = ft_strjoin("Cook the cat lvl ", lvlnb);
	x = (data->maps[data->i].width + 2) * TILE_SIZE;
	y = (data->maps[data->i].height + 2) * TILE_SIZE;
	data->win = mlx_new_window(data->mlx, x, y, lvl);
	if (!(data->win))
		(free(lvlnb), free(lvl), ft_error_malloc(data, 0));
	free(lvlnb);
	free(lvl);
}

void	ft_mlx_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!(data->mlx))
		ft_error_malloc(data, 0);
	ft_win_init(data);
}

void	ft_launch_game(t_data *data)
{
	ft_mlx_init(data);
	ft_sprites_init(data);
	ft_put_counter(data);
	ft_print_surprise(data);
	ft_display_map(data);
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