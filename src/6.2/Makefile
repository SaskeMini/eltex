FLAGS=-Wall -Wextra -Werror

all: build_programm run clean


dinamic_lib:
	gcc $(FLAGS) -fPIC -c dlinked_list_funcs.c
	gcc $(CFLAGS) -shared -o din_lib.so dlinked_list_funcs.o

build_programm:
	make dinamic_lib
	gcc $(FLAGS) dlinked_list.c din_lib.so -Wl,-rpath,. -o prog

run:
	./prog

clean:
	rm -rf prog *.so *.o