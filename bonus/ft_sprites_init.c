/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:57:55 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/20 21:26:18 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static void	ft_xpmtoimg(t_data *data, size_t i, char *path)
{
	data->imgs[i].mlx_img = mlx_xpm_file_to_image(data->mlx, path,
			&data->imgs[i].width, &data->imgs[i].height);
	if (!data->imgs[i].mlx_img)
	{
		free_maps(data);
		destroy_mlx(data);
		ft_printf("Error\nError bad xpm\n");
		exit(1);
	}
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
	ft_xpmtoimg(data, INDCATBURG, CATBURG);
}

static void	ft_sprites_animations(t_data *data)
{
	ft_xpmtoimg(data, INDPUMP1, PUMP1);
	ft_xpmtoimg(data, INDPUMP2, PUMP2);
	ft_xpmtoimg(data, INDPUMP3, PUMP3);
	ft_xpmtoimg(data, INDPUMP4, PUMP4);
	ft_xpmtoimg(data, INDPUMP5, PUMP5);
	ft_xpmtoimg(data, INDPUMP6, PUMP6);
	ft_xpmtoimg(data, INDPUMP7, PUMP7);
	ft_xpmtoimg(data, INDPUMPR, PUMPR);
	ft_xpmtoimg(data, INDPUMPL, PUMPL);
	ft_xpmtoimg(data, INDPUMPDR, PUMPDR);
	ft_xpmtoimg(data, INDPUMPDL, PUMPDL);
	ft_xpmtoimg(data, INDCOOK1, COOK1);
	ft_xpmtoimg(data, INDCOOK2, COOK2);
	ft_xpmtoimg(data, INDCOOK3, COOK3);
	ft_xpmtoimg(data, INDCOOK4, COOK4);
	ft_xpmtoimg(data, INDCOOK5, COOK5);
}

void	ft_sprites_init(t_data *data)
{
	data->imgs = ft_calloc(NB_IMG, sizeof(t_img));
	if (!(data->imgs))
		ft_error_malloc(data, 0);
	ft_init_map(data);
	ft_sprites_animations(data);
}
