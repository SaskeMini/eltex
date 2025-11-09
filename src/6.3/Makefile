FLAGS=-Wall -Wextra -Werror

all: build_programm run clean

dinamic_libs:
	gcc $(FLAGS) -fPIC -c funcs/sum.c funcs/div.c funcs/sub.c funcs/mult.c
	gcc $(FLAGS) -shared -o libs/sum.so sum.o
	gcc $(FLAGS) -shared -o libs/div.so div.o
	gcc $(FLAGS) -shared -o libs/mult.so mult.o
	gcc $(FLAGS) -shared -o libs/sub.so sub.o

build_programm:
	make dinamic_libs
	gcc $(FLAGS) new_calc.c libs/sum.so libs/div.so libs/mult.so libs/sub.so -Wl,-rpath,. -o prog

run:
	./prog

clean:
	rm -rf prog libs/*.so *.o