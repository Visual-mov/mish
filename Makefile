CC = gcc
FLAGS = -g -Wall

all: 
	lex
	mish.o builtins.o
	${CC} ${FLAGS} mish.o builtins.o -o mish

install: all
	chmod a+x install.sh
	sudo ./install.sh

lex:
	flex --outfile ./src/lex/lex.yy.c src/lex/scanner.lex
	
%.o: src/%.c
	${CC} ${FLAGS} -c $^

clean:
	rm -f *.o mish