CC = gcc
FLAGS = -g -Wall

all: mish.o builtins.o
	${CC} ${FLAGS} mish.o builtins.o -o mish

install: all
	chmod a+x install.sh
	sudo ./install.sh

%.o: src/%.c
	${CC} ${FLAGS} -c $^

clean:
	rm -f *.o mish