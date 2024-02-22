/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:08:10 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/22 15:33:16 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_win_init(t_data *data)
{
	size_t	x;
	size_t	y;

	x = (data->maps[data->i].width) * TILE_SIZE;
	y = (data->maps[data->i].height) * TILE_SIZE;
	data->win = mlx_new_window(data->mlx, x, y, "Cook the cat");
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

void	ft_launch_game(t_data *data)
{
	ft_mlx_init(data);
	ft_sprites_init(data);
	ft_display_map(data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &event_keypress, data);
	mlx_hook(data->win, DestroyNotify, 0L, &on_destroy, data);
	mlx_loop(data->mlx);
}

int	main(int argc, const char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_error_args();
	ft_fill_data(&data, argc - 1);
	ft_start_parse(argv, argc, &data);
	ft_launch_game(&data);
}

//PROTEGER LES RETOURS DES FONCTIONS DE LA MLX QUI MALLOC!!!!!!!!!!!!!!!!!!
//LEAKS PARSING
//checker la modif du split grace a funcheck
//bien tout tester avec funcheck
//Fix l'animation 
//(trouver comment faire avec time.h au lieu de boucle while degueulasse)
//leaks onlynewline
//clock get time pour l'anim
//get time of the day