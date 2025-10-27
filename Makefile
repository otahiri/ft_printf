all = $(NAME)

CC = cc

NAME = libftprintf

CFLAGS = -Wall -Werror -Wextra

SRC = scr/*

OBJ = %.c:%.o

HEADER = headers/*

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: re $(NAME)

