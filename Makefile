flexer: scanner.c parser.c
	gcc -o scanner main.c scanner.c parser.c

scanner.c: scanner.flex
	flex -o scanner.c scanner.flex

parser.c: parser.bison
	bison --defines=token.h --output=parser.c parser.bison