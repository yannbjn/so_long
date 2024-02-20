/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endandfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:53:01 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/17 14:07:58 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_end_game(char *loseorwin, t_data *data)
{
	if (!data)
		exit(1);
	if (data->maps)
		free_maps(data);
	ft_printf("%s", loseorwin);
	destroy_mlx(data);
	exit(0);
}

void	free_maps(t_data *data)
{
	size_t	i;

	i = -1;
	while (data->maps && data->maps[++i].map)
	{
		if (data->bonus)
			free(data->maps[i].npc);
		free_tab(data->maps[i].map);
	}
	free(data->maps);
}

void	destroy_mlx(t_data *data)
{
	size_t	i;

	i = -1;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	while (data->imgs && ++i < NB_IMG)
		if (data->imgs[i].mlx_img)
			mlx_destroy_image(data->mlx, data->imgs[i].mlx_img);
	if (data->imgs)
		free(data->imgs);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	on_destroy(t_data *data)
{
	size_t	i;

	i = -1;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	while (data->imgs && ++i < NB_IMG)
		mlx_destroy_image(data->mlx, data->imgs[i].mlx_img);
	mlx_destroy_display(data->mlx);
	data->win = NULL;
	free_maps(data);
	free(data->imgs);
	free(data->mlx);
	exit(0);
	return (0);
}
