NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/main.c
OBJ = $(SRCS:c=o)

%.o: %.c
	$(CC) -g $(CFLAGS) -Imlx -Iinc -c $< -o $@	#source files of mlx on a folder "mlx" inside root of project (where Makefile is)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L/usr/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)	 # -framework OpenGL -framwork AppKit for the specified applications (macOS); libmlx.dylib needs to be on the same directory as build target (*.o)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re