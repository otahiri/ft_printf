CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ft_convert_base.c ft_printf.c ft_printf_utils2.c ft_printf_utils.c ft_uitoa.c

OBJ:= $(SRC:%.c=%.o)

LIBFT = libft.a

HEADER = ft_printf.h

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
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
