FLAGS=-Wall -Wextra -Werror

all: build_programm example1 example2 clean

build_programm:
	gcc $(FLAGS) main.c -o prog

example2:
	./prog

example1:
	./prog -777 main.c

clean:
	rm -rf prog