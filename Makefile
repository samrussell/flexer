flexer: scanner.c
	gcc -o scanner main.c scanner.c

scanner.c: scanner.flex
	flex -o scanner.c scanner.flex

