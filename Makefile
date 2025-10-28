all: $(NAME)

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

SRC:= $(wildcard src/*.c)

OBJ:= $(SRC:%.c=%.o)

HEADERS:= headers/ft_printf.h

LIBFT_SRC:= src/ft_printf.c

LIBFT_OBJ = $(LIBFT_SRC:%.c=%.o)

LIBFT = libft/libft.a

%.o: %.c $(HEADERS)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ./libft all

$(NAME): $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: $(NAME) $(LIBFT) re clean fclean all
