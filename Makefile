CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

NAME    = fdf
SRCS    = main.c color.c node.c map.c fdf.c line.c pixel.c dnode.c renders.c inputs.c
OBJS    = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
MLX_DIR   = ./mlx

LIBFT     = $(LIBFT_DIR)/libft.a
MLX       = $(MLX_DIR)/mlx.a

INCS      = -I$(LIBFT_DIR) -I$(MLX_DIR)
LDFLAGS   = -L$(LIBFT_DIR) -L$(MLX_DIR) -L/opt/X11/lib
LDLIBS    = -lft -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR) > /dev/null

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean > /dev/null

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean > /dev/null

re: fclean all

.PHONY: all clean fclean re
