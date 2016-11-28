libfuncs.a: highscore.o misc.o tetris.o
	ar rv libfuncs.a highscore.o misc.o tetris.o
%.o: %.c
	gcc -g -Wall -c $< -o $@
clean:
	rm -f highscore.o misc.o tetris.o
