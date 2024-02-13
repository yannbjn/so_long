/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:02:47 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/05 18:44:42 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static int	ft_set_dir(t_data *data, int dir)
{
	data->maps[data->i].p.dir = dir;
	return (1);
}

int	event_keypress(int keysym, t_data *data)
{
	t_pos	pos;

	pos = data->maps[data->i].p;
	if (keysym == XK_Escape)
		ft_end_game(ft_printf("Game Over\n"), data);
	if (keysym == XK_s && ft_set_dir(data, 1))
		ft_move_char(data, pos, pos.x, pos.y + 1);
	if (keysym == XK_a && ft_set_dir(data, 4))
		ft_move_char(data, pos, pos.x - 1, pos.y);
	if (keysym == XK_w && ft_set_dir(data, 2))
		ft_move_char(data, pos, pos.x, pos.y - 1);
	if (keysym == XK_d && ft_set_dir(data, 3))
		ft_move_char(data, pos, pos.x + 1, pos.y);
	return (0);
}
