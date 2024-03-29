NAME = so_long

SRC =	borders.c checker.c elements.c get_next_line_utils.c\
		get_next_line.c main.c sizeposition.c utils1.c utils2.c window.c\
		window2.c window3.c mouvements.c zed.c zed2.c

GCC = cc

FLAG = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

OBJS = $(SRC:.c=.o)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(FLAG) $(OBJS) -o $(NAME) 
clean :
	$(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME)
re : fclean all