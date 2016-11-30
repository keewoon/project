PROGRAM = gtktetris
BIN_PATH = /usr/local/bin
HIGHSCORE_PATH = /usr/local/games/gtktetris
GROUP = root
HIGHSCORE_FILE  = $(HIGHSCORE_PATH)/highscore.dat

libfuncs.a: highscore.o misc.o tetris.o
	ar rv libfuncs.a highscore.o misc.o tetris.o
%.o: %.c
	gcc -g -Wall -c $< -o $@ `pkg-config --cflags --libs gtk+-2.0` 
clean:
	rm -f highscore.o misc.o tetris.o

install:
	mkdir -p $(BIN_PATH)
	mkdir -p $(HIGHSCORE_PATH)
	install -o root -g $(GROUP) $(PROGRAM) $(BIN_PATH)
	if [ ! -f $(HIGHSCORE_FILE) ]; then \
                : > $(HIGHSCORE_FILE); \
        fi
	chown root.$(GROUP) $(HIGHSCORE_FILE)
	chmod 666 $(HIGHSCORE_FILE)
#	ln -s $(BIN_PATH)/$(PROGRAM) /usr/games/bin/tetris   
