NAME = Hashtable.a
FILES = Hashtable.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(FILES:.c=.o)

all: $(NAME)

reqs:
	(cd ./libft && make bonus && cp libft.a ../libft.a)

$(NAME): $(OBJS) reqs
	ar rc $(NAME) $(OBJS) libft.a

clean:
	rm -f $(OBJS)
	(cd ./libft && make clean)

fclean:	clean
	rm -f $(NAME) libft.a

re:	fclean all