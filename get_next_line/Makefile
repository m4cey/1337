FLAGS := -Wall -Werror -Wextra -g

all: main.c get_next_line.h get_next_line.c get_next_line_utils.c
	gcc $(FLAGS) main.c get_next_line.c get_next_line_utils.c 
run: all
	./a.out
clean:
	rm a.out
