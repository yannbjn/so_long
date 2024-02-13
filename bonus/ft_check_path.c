/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:10:46 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/09 16:16:57 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static int	ft_copy_map(t_map *map, t_tmpmap *tmpmap)
{
	size_t	i;

	i = 0;
	tmpmap->nb_collect = 0;
	tmpmap->nb_exit = 0;
	tmpmap->map = ft_calloc((map->height + 1), sizeof(char *));
	if (!tmpmap->map)
		return (0);
	while (i < map->height)
	{
		tmpmap->map[i] = ft_strdup(map->map[i]);
		if (!tmpmap->map[i])
		{
			free_tab(tmpmap->map);
			return (0);
		}
		i++;
	}
	return (1);
}

static void	ft_backtracking(t_tmpmap *tmpmap, t_map *map, size_t y, size_t x)
{
	if (tmpmap->map[y][x] == '1' || tmpmap->map[y][x] == 'N')
		return ;
	else if (tmpmap->map[y][x] == 'E')
		tmpmap->nb_exit += 1;
	else if (tmpmap->map[y][x] == 'C')
		tmpmap->nb_collect += 1;
	tmpmap->map[y][x] = '1';
	if (x + 1 < map->width && tmpmap->map[y][x + 1] != '1')
		ft_backtracking(tmpmap, map, y, x + 1);
	if (x - 1 > 0 && tmpmap->map[y][x - 1] != '1')
		ft_backtracking(tmpmap, map, y, x - 1);
	if (y + 1 < map->height && tmpmap->map[y + 1][x] != '1')
		ft_backtracking(tmpmap, map, y + 1, x);
	if (y - 1 > 0 && tmpmap->map[y - 1][x] != '1')
		ft_backtracking(tmpmap, map, y - 1, x);
}

void	ft_check_path(t_map *map, t_data *data)
{
	t_tmpmap	tmpmap;

	if (!ft_copy_map(map, &tmpmap))
		ft_error_malloc(data, 0);
	ft_backtracking(&tmpmap, map, map->p.y, map->p.x);
	if (tmpmap.nb_exit != 1 || tmpmap.nb_collect != map->nb_collect)
	{
		free_tab(tmpmap.map);
		ft_error_path(data);
	}
	free_tab(tmpmap.map);
}
