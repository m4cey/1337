FLAGS = -Wall -Werror -Wextra -g
NAME = out

all: *.c ft_printf.h
	gcc $(FLAGS) -g -c *.c
	ar rv libftprintf.a *.o
	ranlib libftprintf.a
r: *.c ft_printf.h
	gcc $(FLAGS) *.c build/main.c -o build/$(NAME)
	build/$(NAME)
clean:
	rm -f build/$(NAME)
	rm -f *.o libftprintf.a
