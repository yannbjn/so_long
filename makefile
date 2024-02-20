NAME		=	so_long

BNAME		=	so_long_bonus

CC			=	cc

FLAG		=	-Wall -Wextra -Werror -g3

LIBFT_PATH	=	libft

LIBFT_FILE	=	libft.a

MLX_FILE	=	libmlx.a

LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

MLX_FLAGS	=	-lX11 -lXext

MLX_PATH	=	./minilibx-linux

MLX_LIB		=	$(MLX_PATH)/$(MLX_FILE)

MLX_EX		=	$(MLX_LIB) $(MLX_FLAGS)

C_FILE		=	main.c \
				ft_parse_map.c \
				ft_parse_map_utils.c \
				ft_count_ecpn01.c \
				ft_fill_structs.c \
				ft_check_path.c \
				ft_error.c \
				ft_error2.c \
				ft_display_char.c \
				ft_display_count.c \
				ft_display_map.c \
				ft_display_utils.c \
				ft_endandfree.c \
				ft_events.c \
				ft_mlx_init.c \
				ft_sprites_init.c \
				ft_utils.c

BC_FILE		=	./bonus/main.c \
				./bonus/ft_parse_map.c \
				./bonus/ft_parse_map_utils.c \
				./bonus/ft_count_ecpn01.c \
				./bonus/ft_fill_structs.c \
				./bonus/ft_check_path.c \
				./bonus/ft_error.c \
				./bonus/ft_error2.c \
				./bonus/ft_display_char.c \
				./bonus/ft_display_count.c \
				./bonus/ft_display_map.c \
				./bonus/ft_display_utils.c \
				./bonus/ft_endandfree.c \
				./bonus/ft_events.c \
				./bonus/ft_mlx_init.c \
				./bonus/ft_sprites_init.c \
				./bonus/ft_utils.c \
				./bonus/ft_npc.c \
				./bonus/ft_npc_utils.c

OBJS		=	$(C_FILE:.c=.o)

BOBJS		=	$(BC_FILE:.c=.o)

.c.o:
	@printf "\r\033[K[so_long] \033[0;32mBuilding : $<\033[0m\n"
	@$(CC) $(FLAG) -c $< -o $@

all:	$(NAME)

ball:	$(NAME) $(BNAME)

lib:
	@make -C $(LIBFT_PATH)

mlx:
	@printf "\r\033[K[so_long] \033[0;32mLinking...\033[0m"
	@make -sC $(MLX_PATH)

$(NAME): lib mlx $(OBJS)
	@$(CC) $(OBJS) $(LIBFT_LIB) $(MLX_EX) -o $(NAME) -lm 
	@printf "\r\033[K[so_long] \033[0;32mDone!\033[0m\n"

clean:
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJS)
	@rm -f $(BOBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BNAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

bre: fclean ball

bonus: $(BNAME)

$(BNAME): lib mlx $(BOBJS)
	@$(CC) $(BOBJS) $(LIBFT_LIB) $(MLX_EX) -o $(BNAME) -lm 
	@printf "\r\033[K[so_long] \033[0;32mDone!\033[0m\n"

.PHONY: all clean fclean re bonus