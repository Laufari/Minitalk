NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_strings.c ft_printf_numbers.c \
	   ft_printf_unsigned_numbers.c ft_printf_hexa.c \
	   ft_printf_hexamin.c ft_printf_pointer.c 

OBJECTS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra
RM	= rm -rf
 
# Metodo implicito:
%.o: %.c ft_printf.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@ 

# Mis metodos:
all: ${NAME}

${NAME}: ${OBJECTS}
	ar rc ${NAME} ${OBJECTS}
	ranlib ${NAME}  #Ponerle un indice a nuestra libereria (opcional)


clean:
	$(RM) $(OBJECTS) 
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re
