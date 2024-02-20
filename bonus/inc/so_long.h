/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabejani <yabejani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:01:23 by yabejani          #+#    #+#             */
/*   Updated: 2024/02/20 17:38:36 by yabejani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libft/libft.h"
# include "../../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <time.h>

# define WINDOW_WIDTH 1980
# define WINDOW_HEIGHT 1020

# define TILE_SIZE 32

# define ANIM_TIME 175000000

# define WALLC "./textures/wall.xpm"
# define INDWALLC 0
# define WALLL "./textures/walll.xpm"
# define INDWALLL 1
# define WALLD "./textures/walld.xpm"
# define INDWALLD 2
# define WALLR "./textures/wallr.xpm"
# define INDWALLR 3
# define WALLU "./textures/wallu.xpm"
# define INDWALLU 4
# define CORNERDR "./textures/cornerdr.xpm"
# define INDCORNERDR 5
# define CORNERDL "./textures/cornerdl.xpm"
# define INDCORNERDL 6
# define CORNERUL "./textures/cornerul.xpm"
# define INDCORNERUL 7
# define CORNERUR "./textures/cornerur.xpm"
# define INDCORNERUR 8
# define FLOOR1 "./textures/tmpfloor.xpm"
# define INDFLOOR1 9
# define CATINIT "./textures/Cat_init.xpm"
# define INDCATINIT 10
# define CATMVD1 "./textures/catmvd1.xpm"
# define INDCATMVD1 11
# define CATMVU1 "./textures/catmvu1.xpm"
# define INDCATMVU1 12
# define CATMVR2 "./textures/catmvr2.xpm"
# define INDCATMVR2 13
# define CATMVL2 "./textures/catmvl2.xpm"
# define INDCATMVL2 14
# define CATBBQ "./textures/catonbbq.xpm"
# define INDCATBBQ 15
# define CLOSEDE "./textures/eclosed.xpm"
# define INDCLOSEDE 16
# define OPENE "./textures/eopen.xpm"
# define INDOPENE 17
# define COLLECT1 "./textures/collect1.xpm"
# define INDCOLLECT1 18
# define BACKG "./textures/background.xpm"
# define INDBACKG 19
# define CATBURG "./textures/cateatburger.xpm"
# define INDCATBURG 20
# define PUMP1 "./textures/pump1.xpm"
# define INDPUMP1 21
# define PUMP2 "./textures/pump2.xpm"
# define INDPUMP2 22
# define PUMP3 "./textures/pump3.xpm"
# define INDPUMP3 23
# define PUMP4 "./textures/pump4.xpm"
# define INDPUMP4 24
# define PUMP5 "./textures/pump5.xpm"
# define INDPUMP5 25
# define PUMP6 "./textures/pump6.xpm"
# define INDPUMP6 26
# define PUMP7 "./textures/pump7.xpm"
# define INDPUMP7 27
# define PUMPR "./textures/pumpr.xpm"
# define INDPUMPR 28
# define PUMPL "./textures/pumpl.xpm"
# define INDPUMPL 29
# define PUMPDR "./textures/pumpdr.xpm"
# define INDPUMPDR 30
# define PUMPDL "./textures/pumpdl.xpm"
# define INDPUMPDL 31
# define COOK1 "./textures/cook1.xpm"
# define INDCOOK1 32
# define COOK2 "./textures/cook2.xpm"
# define INDCOOK2 33
# define COOK3 "./textures/cook3.xpm"
# define INDCOOK3 34
# define COOK4 "./textures/cook4.xpm"
# define INDCOOK4 35
# define COOK5 "./textures/cook5.xpm"
# define INDCOOK5 36
# define NB_IMG 37

typedef struct s_img
{
	void		*mlx_img;
	int			width;
	int			height;
}				t_img;

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
	int			bonus;
}				t_data;

void			ft_error_args(void);
void			ft_error_ber(t_data *data);
void			ft_error_emptymap(t_data *data);
void			ft_error_rect(t_data *data);
void			ft_error_malloc(t_data *data, int flag);
void			ft_error_walls(t_data *data);
void			ft_error_chars(t_data *data);
void			ft_error_path(t_data *data);
void			ft_error_nb_cpe(t_data *data);

int				ft_pos_init(t_pos *pos, size_t x, size_t y);
void			ft_fill_map(t_map *map, char const *mapber);
void			ft_fill_data(t_data *data, size_t n);

int				ft_check_ber(char const *mapber);
char			*ft_gnltomap1(int fd, t_data *data);
void			ft_gnltomap2(int fd, t_map *map, t_data *data);
int				ft_vert_walls(t_map map);
int				ft_topbot_walls(t_map map);
void			ft_count_ecpn01(t_map *map, t_data *data);
void			ft_check_path(t_map *map, t_data *data);

void			ft_map(char const *mapber, t_data *data, size_t i);
void			ft_start_parse(char const **argv, int argc, t_data *data);

void			ft_mlx_init(t_data *data);

void			ft_launch_game(t_data *data);

void			ft_sprites_init(t_data *data);

void			ft_display_map(t_data *data);

void			ft_put_counter(t_data *data);

void			ft_display_char(t_data *data);
int				ft_move_char(t_data *data, t_pos pos, size_t x, size_t y);

void			ft_img_towindow(t_data *data, size_t i, size_t x, size_t y);
void			ft_display_eorb(t_data *data, size_t x, size_t y);
void			ft_diplay_corb(t_data *data, size_t x, size_t y);

int				event_keypress(int keysym, t_data *data);

void			ft_end_game(char *loseorwin, t_data *data);
void			free_maps(t_data *data);
void			destroy_mlx(t_data *data);
void			next_map(t_data *data);
int				event_destroy(char *loseorwin, t_data *data);
int				on_destroy(t_data *data);

void			new_move(t_data *data, t_pos pos, size_t x, size_t y);
void			move_npc(t_data *data);
void			ft_display_npc(t_data *data);
void			check_for_npc(t_data *data);
void			ft_seed_time(void);
int				ft_random_number(void);
void			ft_sprite_tempo(void);
int				ft_cook(t_data *data);

#endif