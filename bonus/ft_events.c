/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:02:47 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/21 16:43:32 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static int	ft_set_dir(t_data *data, int dir)
{
	data->maps[data->i].p.dir = dir;
	return (1);
}

static int	set_bonus(t_data *data, int bonus)
{
	data->bonus = bonus;
	return (1);
}

static void	ft_put_exit(t_data *data, size_t x, size_t y)
{
	if (data->maps[data->i].nb_collect)
		ft_img_towindow(data, INDCLOSEDE, x, y);
	else
		ft_img_towindow(data, INDOPENE, x, y);
}

static void	ft_future(t_data *data)
{
	int		i;
	size_t	x;
	size_t	y;

	i = 0;
	x = data->maps[data->i].exit.x;
	y = data->maps[data->i].exit.y;
	while (++i < 50000)
		ft_img_towindow(data, INDCOOK1, x, y);
	while (--i)
		ft_img_towindow(data, INDCOOK2, x, y);
	while (++i < 40000)
		ft_img_towindow(data, INDCOOK3, x, y);
	while (--i)
		ft_img_towindow(data, INDCOOK4, x, y);
	while (++i < 40000)
		ft_img_towindow(data, INDCOOK1, x, y);
	while (--i)
		ft_img_towindow(data, INDCOOK2, x, y);
	while (++i < 40000)
		ft_img_towindow(data, INDCOOK3, x, y);
	while (--i > -150000)
		ft_img_towindow(data, INDCOOK5, x, y);
	ft_put_exit(data, x, y);
}

int	event_keypress(int keypress, t_data *data)
{
	t_pos	pos;

	pos = data->maps[data->i].p;
	if (data->bonus < 0)
		return (0);
	if (data->bonus == 3)
		(set_bonus(data, -1), next_map(data));
	if (keypress == 'f')
		ft_future(data);
	if (keypress == XK_Escape || (data->bonus == 2))
		ft_end_game("You lost\n", data);
	if (data->bonus == 1 && (keypress == XK_s || keypress == XK_Down))
		(ft_set_dir(data, 0), new_move(data, pos, pos.x, pos.y + 1));
	if (data->bonus == 1 && (keypress == XK_a || keypress == XK_Left))
		(ft_set_dir(data, 3), new_move(data, pos, pos.x - 1, pos.y));
	if (data->bonus == 1 && (keypress == XK_w || keypress == XK_Up))
		(ft_set_dir(data, 1), new_move(data, pos, pos.x, pos.y - 1));
	if (data->bonus == 1 && (keypress == XK_d || keypress == XK_Right))
		(ft_set_dir(data, 2), new_move(data, pos, pos.x + 1, pos.y));
	return (0);
}
