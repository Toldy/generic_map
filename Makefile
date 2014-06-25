##
## Makefile
## 
## Made by julien colin
## Login   <colin_g@epitech.eu>
## 
## Started on  mer. juin 25 14:57:59 2014 julien colin
## Last update mer. juin 25 15:17:41 2014 julien colin
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -I.

NAME	= map_test

SRCS	= main.c \
		  map.c \
		  cmp_func.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

