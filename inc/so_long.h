/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:01:23 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/08 17:10:43 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>

# define WINDOW_WIDTH 1980
# define WINDOW_HEIGHT 1020

# define MLX_ERROR 1

# define TILE_SIZE 32

# define WALLC "./assets/wall.xpm"
# define INDWALLC 0
# define WALLL "./assets/walll.xpm"
# define INDWALLL 1
# define WALLD "./assets/walld.xpm"
# define INDWALLD 2
# define WALLR "./assets/wallr.xpm"
# define INDWALLR 3
# define WALLU "./assets/wallu.xpm"
# define INDWALLU 4
# define CORNERDR "./assets/cornerdr.xpm"
# define INDCORNERDR 5
# define CORNERDL "./assets/cornerdl.xpm"
# define INDCORNERDL 6
# define CORNERUL "./assets/cornerul.xpm"
# define INDCORNERUL 7
# define CORNERUR "./assets/cornerur.xpm"
# define INDCORNERUR 8
# define FLOOR1 "./assets/tmpfloor.xpm"
# define INDFLOOR1 9
# define CATINIT "./assets/Cat_init.xpm"
# define INDCATINIT 10
# define CATMVD1 "./assets/catmvd1.xpm"
# define INDCATMVD1 11
# define CATMVU1 "./assets/catmvu1.xpm"
# define INDCATMVU1 12
# define CATMVR2 "./assets/catmvr2.xpm"
# define INDCATMVR2 13
# define CATMVL2 "./assets/catmvl2.xpm"
# define INDCATMVL2 14
# define CATBBQ "./assets/catonbbq.xpm"
# define INDCATBBQ 15
# define CLOSEDE "./assets/eclosed.xpm"
# define INDCLOSEDE 16
# define OPENE "./assets/eopen.xpm"
# define INDOPENE 17
# define COLLECT1 "./assets/collect1.xpm"
# define INDCOLLECT1 18
# define BACKG "./assets/background.xpm"
# define INDBACKG 19
# define NB_IMG 20

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
	int			color;
}				t_rect;

typedef struct s_pos
{
	size_t		x;
	size_t		y;
	size_t		moves;
	int			dir;
}				t_pos;

typedef struct s_tmpmap
{
	size_t		nb_collect;
	size_t		nb_exit;
	char		**map;
}				t_tmpmap;

typedef struct s_map
{
	size_t		width;
	size_t		height;
	size_t		nb_collect;
	size_t		nb_exit;
	size_t		nb_p;
	size_t		nb_npc;
	t_pos		exit;
	t_pos		p;
	t_pos		*npc;
	char		**map;
	char const	*mapber;

}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		*maps;
	t_img		*imgs;
	size_t		i;
	size_t		n;
}				t_data;

void			ft_error_args(void);
void			ft_error_ber(t_data *data);
void			ft_error_emptymap(t_data *data);
void			ft_error_rect(t_data *data);
void			ft_error_malloc(t_data *data, int flag);
void			ft_error_walls(t_data *data);
void			ft_error_chars(t_data *data);
void			ft_error_path(t_data *data);
void			ft_error_nb_pe(t_data *data);
void			ft_freeandclose(char *s1, char *s2, int fd);

int				ft_pos_init(t_pos *pos, size_t x, size_t y);
void			ft_fill_map(t_map *map, char const *mapber);
void			ft_fill_data(t_data *data, size_t n);

int				ft_check_ber(char const *mapber);
char			*ft_gnltomap1(int fd, t_data *data);
void			ft_gnltomap2(int fd, t_map *map, t_data *data);
int				ft_vert_walls(t_map map);
int				ft_topbot_walls(t_map map);
void			ft_parsing(char const *mapber, int fd, t_map *map, t_data *data);
void			ft_count_ecpn01(t_map *map, t_data *data);
void			ft_check_path(t_map *map, t_data *data);

void			ft_map(char const *mapber, t_data *data, size_t i);
void			ft_start_parse(char const **argv, int argc, t_data *data);

void			ft_mlx_init(t_data *data);

void			ft_launch_game(t_data *data);

void			ft_sprites_init(t_data *data);

void			ft_display_map(t_data *data);

void			ft_displaymovecount(t_data *data);
void			ft_update_counter(t_data *data);

void			ft_display_char(t_data *data);
int				ft_move_char(t_data *data, t_pos pos, size_t x, size_t y);

void			ft_img_towindow(t_data *data, size_t i, size_t x, size_t y);
void			ft_display_e(t_data *data, size_t x, size_t y);

int				event_keypress(int keysym, t_data *data);

void			ft_end_game(int status, t_data *data);
void			free_maps(t_data *data);
int				free_parse(char *s1, char *s2, int fd);
void			destroy_mlx(t_data *data);
void			next_map(t_data *data);
int				event_destroy(t_data *data);

#endif