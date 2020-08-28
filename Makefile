CC = gcc

main:
	${CC} src/mish.c -o mish

install:
	${CC} src/mish.c -o mish

clean:
	rm lish