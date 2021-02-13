##
## EPITECH PROJECT, 2021
## Test_my_malloc
## File description:
## Makefile
##

SRC=		src/malloc2.c		\
			src/gest_node2.c		\


NAME=		libmy_malloc.so

XX=			gcc

OBJ=		$(SRC:.c=.o)

LDFLAGS=	-shared -fPIC

CFLAGS=		-fPIC -Wall -Wextra

CPPFLAGS=	-I ./include -lm

all:		$(NAME)

$(NAME):	$(OBJ)
			$(XX) -o $(NAME) $(OBJ) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re