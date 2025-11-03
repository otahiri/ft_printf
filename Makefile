CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = char_funcs.c convert_base.c decimal_func.c ft_printf.c hex_funcs.c HEX_funcs.c \
			int_funcs.c main.c pointer_funcs.c string_funcs.c uint_funcs.c

OBJ:= $(SRC:%.c=%.o)

LIBFT = libft.a

HEADER = libftprintf.h

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C ./libft all
	cp ./libft/$(LIBFT) $@
	ar rcs $(NAME) $(OBJ)

clean:
	make -C ./libft clean
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
