/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:16:33 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/08 16:13:11 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_error_args(void)
{
	ft_printf("Error\nYou must provide one .ber file as arg\n");
	exit(1);
}

void	ft_error_ber(t_data *data)
{
	if (!data)
		(ft_printf("Error\nMap not valid, needs to be a .ber file!\n"), exit (1));
	if (data->maps)
		free_maps(data);
	ft_printf("Error\nMap not valid, needs to be a .ber file!\n");
	exit(1);
}

void	ft_error_emptymap(t_data *data)
{
	ft_printf("Error\nEmpty or almost empty map is not valid!\n");
	free_maps(data);
	exit(1);
}

void	ft_error_rect(t_data *data)
{
	ft_printf("Error\nMap not in good format, it must be a rectangle\n");
	free_maps(data);
	exit(1);
}

void	ft_error_walls(t_data *data)
{
	ft_printf("Error\nMap must be surrounded by walls!\n");
	free_maps(data);
	exit(1);
}
