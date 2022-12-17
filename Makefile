NAME = ht_test
FILES = Hashtable/ht_get.c \
	Hashtable/ht_hash.c \
	Hashtable/ht_new.c \
	Hashtable/ht_set.c \
	Hashtable/ht_isempty.c \
	Hashtable/ht_contains.c \
	ht_test.c
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJS = $(FILES:.c=.o)

all: $(NAME)

reqs:
	(cd ./libft && make && cp libft.a ../Hashtable/)

$(NAME): $(OBJS) reqs
	$(CC) $(OBJS) Hashtable/libft.a -o $(NAME)

clean:
	rm -f $(OBJS)
	(cd ./libft && make clean)

fclean:	clean
	rm -f $(NAME) libft.a
	(cd ./libft && make fclean)

re:	fclean all