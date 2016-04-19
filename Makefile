##
## Makefile for sudoku in /home/bogard_t/Documents/sudoku
## 
## Made by Thomas Bogard
## Login   <bogard_t@epitech.net>
## 
## Started on  Fri Apr  8 21:03:42 2016 Thomas Bogard
## Last update Fri Apr  8 21:16:03 2016 Thomas Bogard
##

NAME	=	sudoku

REP	=	.

SRC	=	$(REP)/$(wildcard *.c)

RM	=	rm -rfv

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra
# CFLAGS	+=	-Werror
CFLAGS	+=	-ansi -pedantic
# CFLAGS	+=	-O0 -g3
CFLAGS	+=	-I./

LDFLAGS	=	

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
