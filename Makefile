NAME = so_long

SRC =	borders.c checker.c elements.c get_next_line_utils.c\
		get_next_line.c main.c sizeposition.c utils1.c utils2.c window.c\
		window2.c window3.c mouvements.c zed.c zed2.c

CC = cc

CFLAGS = -fsanitize=address -g3 -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)  -lmlx -framework OpenGL -framework AppKit
clean :
	$(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME)
re : fclean all