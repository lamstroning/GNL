NAME=libft.a
SRCS=libft/*.c
OBJECTS= *.o
HEADERS_FOLDER= get_next_line.h libft/libft.h 

all: $(NAME) fclean
	
$(NAME):
	gcc -I $(HEADERS_FOLDER) -c $(SRCS) main.c
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	gcc main.o -L. -lft -o test
clean:
	rm -rf libft/*.o
	rm -rf *.o
fclean: clean
	rm -f $(NAME)
re: fclean all