NAME = libftprintf.a 

HEADER = ft_printf.h

SOURCES = print_hexa.c print_numbers.c print_characters.c ft_printf.c 

OBJECTS = $(SOURCES:.c=.o)

OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

ARFLAGS = -rcs

RMFLAGS = -rf 

all : $(NAME)

$(NAME) : $(OBJECTS) $(HEADER)
	ar $(ARFLAGS) $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm $(RMFLAGS) $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	rm $(RMFLAGS) $(NAME)

re : fclean all

PHONY = all, clean, fclean, re
