/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:31:34 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/16 18:25:11 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	next_map(t_data *data)
{
	t_map	*map;

	mlx_loop_end(data->mlx);
	map = &(data->maps[data->i]);
	map->p.moves++;
	ft_put_counter(data);
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
