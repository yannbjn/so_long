/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:57:55 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/07 16:49:32 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"
#include <stddef.h>

static void	ft_xpmtoimg(t_data *data, size_t i, char *path)
{
	data->imgs[i].mlx_img = mlx_xpm_file_to_image(data->mlx, path,
			&data->imgs[i].width, &data->imgs[i].height);
}

static void	ft_init_map(t_data *data)
{
	ft_xpmtoimg(data, INDWALLC, WALLC);
	ft_xpmtoimg(data, INDWALLL, WALLL);
	ft_xpmtoimg(data, INDWALLD, WALLD);
	ft_xpmtoimg(data, INDWALLR, WALLR);
	ft_xpmtoimg(data, INDWALLU, WALLU);
	ft_xpmtoimg(data, INDCORNERDR, CORNERDR);
	ft_xpmtoimg(data, INDCORNERDL, CORNERDL);
	ft_xpmtoimg(data, INDCORNERUL, CORNERUL);
	ft_xpmtoimg(data, INDCORNERUR, CORNERUR);
	ft_xpmtoimg(data, INDFLOOR1, FLOOR1);
	ft_xpmtoimg(data, INDCATINIT, CATINIT);
	ft_xpmtoimg(data, INDCATMVU1, CATMVU1);
	ft_xpmtoimg(data, INDCATMVD1, CATMVD1);
	ft_xpmtoimg(data, INDCATMVR2, CATMVR2);
	ft_xpmtoimg(data, INDCATMVL2, CATMVL2);
	ft_xpmtoimg(data, INDCATBBQ, CATBBQ);
	ft_xpmtoimg(data, INDCLOSEDE, CLOSEDE);
	ft_xpmtoimg(data, INDOPENE, OPENE);
	ft_xpmtoimg(data, INDCOLLECT1, COLLECT1);
	ft_xpmtoimg(data, INDBACKG, BACKG);
}

void	ft_sprites_init(t_data *data)
{
	data->imgs = ft_calloc(NB_IMG, sizeof(t_img));
	if (!(data->imgs))
		ft_error_malloc(data, 0);
	ft_init_map(data);
}
