CC = gcc
FLAGS = -g -Wall

all:
	${CC} ${FLAGS} src/mish.c -o mish
	
# all: mish.o builtins.o
# 	${CC} ${FLAGS} mish.o builtins.o -o mish

install: all
	chmod -x install.sh
	sh install.sh

# %.o: src/%.c
# 	${CC} ${FLAGS} -c $^

clean:
	rm *.o mish