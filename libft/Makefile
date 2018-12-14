NAME=libft.a
SRCS=*.c
OBJECTS= *.o
HEADERS_FOLDER= libft.h
FLAGS= -Wall -Wextra -Werror

all: $(NAME)
	
$(NAME):
	gcc $(FLAGS) -I$(HEADERS_FOLDER) -c $(SRCS) 
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
clean:
	rm -rf *.o
fclean: clean
	rm -f $(NAME)
re: fclean all