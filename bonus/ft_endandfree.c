/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endandfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:53:01 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/07 14:40:50 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_end_game(int status, t_data *data)
{
	if (!data)
		exit(status);
	if (data->maps)
		free_maps(data);
	destroy_mlx(data);
	exit(status);
}

void	free_maps(t_data *data)
{
	size_t	i;

	i = -1;
	while (data->maps && data->maps[++i].map)
		free_tab(data->maps[i].map);
	free(data->maps);
}

int	free_parse(char *s1, char *s2, int fd)
{
	free(s1);
	free(s2);
	close(fd);
	return (1);
}

void	destroy_mlx(t_data *data)
{
	size_t	i;
	size_t	limit;

	i = -1;
	limit = NB_IMG;
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	while (data->imgs && ++i < limit)
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
