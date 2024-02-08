/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:31:34 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/07 18:14:56 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	next_map(t_data *data)
{
	mlx_loop_end(data->mlx);
	if (++(data->i) < data->n)
	{
		destroy_mlx(data);
		ft_launch_game(data);
	}
	ft_end_game(ft_printf("WIN"), data);
}

int	event_destroy(t_data *data)
{
	ft_end_game(ft_printf("GAME_OVER"), data);
	return (0);
}
