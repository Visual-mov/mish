CC = gcc
FLAGS = -g -Wall

LEX_DIR = src/lex/

all: lex mish.o builtins.o
	${CC} ${FLAGS} mish.o builtins.o -o mish

install: all
	chmod a+x install.sh
	sudo ./install.sh

lex:
	flex --outfile "./src/lex/lex.yy.c" "src/lex/scanner.l"
	${CC} ${FLAGS} ${LEX_DIR}/lex.yy.c ${LEX_DIR}token.c -o ${LEX_DIR}lex -lfl
	
%.o: src/%.c
	${CC} ${FLAGS} -c $^

clean:
	rm -f *.o mish lex