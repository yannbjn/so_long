/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:02:47 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/20 14:07:34 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static int	ft_set_dir(t_data *data, int dir)
{
	data->maps[data->i].p.dir = dir;
	return (1);
}

int	event_keypress(int keypress, t_data *data)
{
	t_pos	pos;

	pos = data->maps[data->i].p;
	if (keypress == XK_Escape)
		ft_end_game("You lost\n", data);
	if (keypress == XK_s && ft_set_dir(data, 1))
		ft_move_char(data, pos, pos.x, pos.y + 1);
	if (keypress == XK_a && ft_set_dir(data, 4))
		ft_move_char(data, pos, pos.x - 1, pos.y);
	if (keypress == XK_w && ft_set_dir(data, 2))
		ft_move_char(data, pos, pos.x, pos.y - 1);
	if (keypress == XK_d && ft_set_dir(data, 3))
		ft_move_char(data, pos, pos.x + 1, pos.y);
	return (0);
}
