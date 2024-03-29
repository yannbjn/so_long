/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:00:05 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/20 17:05:37 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_check_returnline(t_data *data, char *bigline)
{
	size_t	i;

	i = -1;
	if (bigline[0] == '\n')
		(free(bigline), ft_error_rect(data));
	while (bigline[++i])
	{
		if (bigline[i] == '\n' && bigline[i + 1] == '\n')
			(free(bigline), ft_error_rect(data));
	}
}

char	*ft_gnltomap1(int fd, t_data *data)
{
	int		readbytes;
	char	*bigline;
	char	*buffer;

	readbytes = 1;
	bigline = ft_calloc(1, sizeof(char));
	if (!bigline)
		return (ft_error_malloc(data, 1), NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (ft_error_malloc(data, 1), NULL);
	while (readbytes > 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
			return (free(bigline), free(buffer), NULL);
		if (readbytes == 0)
			return (free(buffer), close(fd), bigline);
		buffer[readbytes] = '\0';
		bigline = ft_strjoinfree(bigline, buffer);
	}
	close(fd);
	return (free(buffer), bigline);
}

void	ft_gnltomap2(int fd, t_map *map, t_data *data)
{
	int		i;
	size_t	n;
	char	*bigline;

	bigline = ft_gnltomap1(fd, data);
	if (!bigline || ft_strlen(bigline) < 17)
		(free(bigline), ft_error_emptymap(data));
	ft_check_returnline(data, bigline);
	map->map = ft_split(bigline, '\n');
	free(bigline);
	if (!map->map)
		ft_error_malloc(data, 0);
	if (!(map->map[0]))
		ft_error_emptymap(data);
	i = -1;
	map->width = ft_strlen(map->map[++i]);
	while (map->map[++i] && ++(map->height))
	{
		n = ft_strlen(map->map[i]);
		if (n != map->width)
			(ft_error_rect(data));
	}
	ft_count_ecpn01(map, data);
}

void	ft_map(const char *mapber, t_data *data, size_t i)
{
	int		fd;
	t_map	*map;

	map = &(data->maps[i]);
	fd = open(mapber, __O_DIRECTORY);
	if (fd > 0)
		(close(fd), ft_error_ber(data));
	fd = open(mapber, O_RDONLY);
	if (fd < 0 || !ft_check_ber(mapber))
		ft_error_ber(data);
	ft_fill_map(&(data->maps[i]), mapber);
	ft_gnltomap2(fd, &(data->maps[i]), data);
	if (map->nb_npc)
	{
		map->npc = ft_calloc(map->nb_npc + 1, sizeof(t_pos));
		if (!map->npc)
			ft_error_malloc(data, 0);
	}
	if (!ft_vert_walls(data->maps[i]) || !ft_topbot_walls(data->maps[i]))
		ft_error_walls(data);
	if (data->maps->nb_exit != 1 || data->maps->nb_p != 1 \
		|| !data->maps->nb_collect)
		ft_error_nb_cpe(data);
	ft_check_path(&(data->maps[i]), data);
}

void	ft_start_parse(char const **argv, int argc, t_data *data)
{
	int	i;

	i = 0;
	data->maps = ft_calloc(argc, sizeof(t_map));
	if (!data->maps)
		ft_error_malloc(data, 0);
	ft_fill_map(data->maps + (argc - 1), NULL);
	while (i + 1 < argc)
	{
		ft_map(argv[i + 1], data, i);
		i++;
	}
}
