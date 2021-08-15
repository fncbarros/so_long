NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/main.c
OBJ = $(SRCS:c=o) $(GNL:c=o)
GNL = get_next_line/get_next_line.c
LIBFT = libft.a

%.o: %.c
	$(CC) -g $(CFLAGS) -Imlx -Iinc -c $< -o $@	#source files of mlx on a folder "mlx" inside root of project (where Makefile is)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -L/usr/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)	 # -framework OpenGL -framwork AppKit for the specified applications (macOS); libmlx.dylib needs to be on the same directory as build target (*.o)

$(LIBFT):
	$(MAKE) -C libft/
	cp libft/libft.a .

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
