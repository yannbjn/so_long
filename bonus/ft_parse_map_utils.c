/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:38:42 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/08 15:54:07 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	ft_check_ber(char const *mapber)
{
	size_t	n;

	n = ft_strlen(mapber);
	if (n < 4 || mapber[n - 1] != 'r' || mapber[n - 2] != 'e'\
	|| mapber[n - 3] != 'b' || mapber[n - 4] != '.')
		return (0);
	return (1);
}

int	ft_vert_walls(t_map map)
{
	size_t	i;

	i = 0;
	while (i < map.height)
	{
		if (map.map[i][0] != '1' || map.map[i][map.width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_topbot_walls(t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = map.height - 1;
	while (map.map[0][i])
	{
		if (map.map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map.map[j][i])
	{
		if (map.map[j][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
