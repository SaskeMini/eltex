FLAGS=-Wall -Wextra -Werror

all: build_programm run clean


stat_lib:
	gcc $(FLAGS) -c dlinked_list_funcs.c

	ar rc stat_lib.a dlinked_list_funcs.o
	ranlib stat_lib.a
	rm -rf *.o

build_programm:
	make stat_lib
	gcc $(FLAGS) dlinked_list.c -L. stat_lib.a -o prog

run:
	./prog

clean:
	rm -rf prog stat_lib.a