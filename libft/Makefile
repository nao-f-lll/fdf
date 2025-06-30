NAME    = libft.a
CC      = cc
FLAGS   = -Wall -Wextra -Werror

M_FUNC  = ft_abs.c ft_atoi.c ft_itoa.c ft_lerp.c ft_atol.c ft_split.c\
          ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
          ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnjoin.c\
          ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
          ft_tolower.c ft_toupper.c ft_bzero.c ft_calloc.c ft_memchr.c\
          ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memrep.c ft_memset.c\
          ft_gnl.c ft_env.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
          ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c\
          ft_isspace.c ft_issign.c\

M_OBJ   = $(M_FUNC:.c=.o)

$(NAME): $(M_OBJ)
	@ar rc $(NAME) $(M_OBJ)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(M_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
