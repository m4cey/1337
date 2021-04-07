FLAGS = -Wall -Werror -Wextra -g
NAME = out

out: *.c ft_printf.h
	gcc $(FLAGS) *.c build/main.c -o build/$(NAME)
r: $(NAME)
	build/$(NAME)
clean:
	rm build/$(NAME)
test: *.c build/tester.c ft_printf.h
	gcc $(FLAGS) *.c build/tester.c -o build/test
	build/test
