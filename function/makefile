libfuncs.a: highscore.o misc.o tetris.o
	ar rv libfuncs.a highscore.o misc.o tetris.o
%.o: %.c
	gcc -g -Wall -c $< -o $@ `pkg-config --cflags --libs gtk+-2.0`  
clean:
	rm -f highscore.o misc.o tetris.o
