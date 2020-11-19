##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/parser.c	\
		src/encrypte.c	\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-Wshadow -I ./include

LIB	=	-lm

NAME	=	103cipher

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)
	rm -f *.gcno *.gcda

fclean:	clean
	rm -f $(NAME)

re:	fclean all
