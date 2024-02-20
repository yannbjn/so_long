/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:44:45 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/13 18:31:58 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_put_counter(t_data *data)
{
	t_map	*map;

	map = &(data->maps[data->i]);
	ft_printf("moves: %d\n", map->p.moves);
}

void	ft_displaymovecount(t_data *data)
{
	ft_printf("moves: %d\n", data->maps[data->i].p.moves);
}
