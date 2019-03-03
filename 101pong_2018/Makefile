##
## EPITECH PROJECT, 2018
## makefile
## File description:
## yes
##

NAME	=	101pong

SRC	=	pong.c

$(NAME):	$(SRC)
		gcc $(SRC) -o $(NAME) -lm

clean:
		rm -f *.o

fclean: clean
		$(RM) $(NAME)

re : clean all

all : $(NAME)

.phony : all clean fclean re

yoann : re all
