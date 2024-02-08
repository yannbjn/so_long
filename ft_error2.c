/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:26:59 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/08 15:09:15 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_error_chars(t_data *data)
{
	ft_printf("Error\nMap must contain one E, one P, at least one C,\
1 and 0 for walls and nothing else!\n");
	free_maps(data);
	exit(1);
}

void	ft_error_path(t_data *data)
{
	ft_printf("Error\nNo valid path in map!\n");
	free_maps(data);
	exit(1);
}

void	ft_error_nb_pe(t_data *data)
{
	ft_printf("Error\nMap mut have one and only starting pos and exit!\n");
	free_maps(data);
	exit(1);
}

void	ft_error_malloc(t_data *data, int flag)
{
	ft_printf("Error\nError malloc\n");
	if (flag == 0 && data->maps)
		free_maps(data);
	if (flag == 1)
		exit(1);
	exit(1);
}

void	ft_freeandclose(char *s1, char *s2, int fd)
{
	free(s1);
	free(s2);
	close(fd);
}
