/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:08:10 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/09 18:22:04 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

void	ft_launch_game(t_data *data)
{
	ft_mlx_init(data);
	ft_sprites_init(data);
	ft_display_map(data);
	ft_display_char(data);
	mlx_loop_hook(data->mlx, &handle_no_event, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &event_keypress, data);
	mlx_hook(data->win, DestroyNotify, 0, &event_destroy, data);
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
	ft_end_game(ft_printf("GAME_OVER"), &data);
}

//PROTEGER LES RETOURS DES FONCTIONS DE LA MLX QUI MALLOC!!!!!!!!!!!!!!!!!!
//LEAKS PARSING
//retirer bool rectangle de init et de struct