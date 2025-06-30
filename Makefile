NAME        := fdf
LIBS        := ft mlx
LIBS_TARGET := libft/libft.a \
               mlx/mlx.a
INCS        := libft \
               mlx

SRCS        := main.c     \
               color.c    \
               node.c     \
               map.c      \
               fdf.c      \
               line.c     \
               pixel.c    \
               dnode.c    \
               renders.c  \
               inputs.c

BUILD_DIR   := .build
OBJS        := $(SRCS:%.c=$(BUILD_DIR)/%.o)

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := $(INCS:%=-I%)
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_TARGET))) -L /opt/X11/lib
LDLIBS      := $(addprefix -l,$(LIBS)) -lX11 -lXext

RM          := rm -f
MAKEFLAGS   += --silent --no-print-directory

all: $(NAME)

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(LIBS_TARGET) $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
