CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ft_printf.c string_funcs.c char_funcs.c

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
