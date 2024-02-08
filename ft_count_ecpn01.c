/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_ecpn01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:57:05 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/08 15:03:54 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static size_t	ft_char_count(char const *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_findandcount(t_map *map, size_t height, char c)
{
	size_t	i;
	size_t	x;

	i = ft_char_count(map->map[height], c);
	if (i && c == 'P')
	{
		x = ft_strchr(map->map[height], c) - map->map[height];
		ft_pos_init(&(map->p), x, height);
		map->map[height][x] = '0';
		map->nb_p += i;
	}
	else if (i && c == 'C')
		map->nb_collect += i;
	else if (i && c == 'E' && ft_pos_init(&(map->exit),
			ft_strchr(map->map[height], c) - map->map[height], height))
		map->nb_exit += i;
	return (i);
}

void	ft_count_ecpn01(t_map *map, t_data *data)
{
	size_t	i;
	size_t	y;

	y = 0;
	while (y < map->height)
	{
		i = ft_findandcount(map, y, '0');
		i += ft_findandcount(map, y, '1');
		i += ft_findandcount(map, y, 'P');
		i += ft_findandcount(map, y, 'C');
		i += ft_findandcount(map, y, 'E');
		if (i != map->width)
			ft_error_chars(data);
		y++;
	}
}
