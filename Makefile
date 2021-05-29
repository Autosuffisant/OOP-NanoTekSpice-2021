##
## EPITECH PROJECT, 2021
## NanoTekSpice
## File description:
## Makefile
##

NAME	=	nanotekspice

CC	=	g++

RM	=	rm -f

SRCS	:=	$(shell find src/ -name *.cpp)

OBJS	=	$(SRCS:.cpp=.o)

IDIR	=	./include/

CFLAGS	=	-Wall -Wextra -Werror -I$(IDIR)

LDFLAGS	=	\

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re