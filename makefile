PROGRAM = gtktetris
GETTEXT_PACKAGE = gtktetris
OBJS = ../function/misc.o ../function/highscore.o ../function/tetris.o ../play/interface.o
BIN_PATH = /usr/local/bin
HIGHSCORE_PATH = /usr/local/games/gtktetris
GROUP = root
HIGHSCORE_FILE = $(HIGHSCORE_PATH)/highscore.dat
#SIZE = -DBIGGERBLOCKS
SIZE = -DBIGBLOCKS
CC = gcc



CFLAGS = `pkg-config gtk+-2.0 --cflags` -Wall -O2 \
        -DHIGHSCORE_FILE=\"$(HIGHSCORE_FILE)\" $(SIZE)

LIBS = `pkg-config gtk+-2.0 --libs`

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM) $(LIBS)
	strip $(PROGRAM)

clean: 
	rm -f *.o *~ $(PROGRAM)
uninstall:
	rm -i $(BIN_PATH)/$(PROGRAM)
	rm -i $(HIGHSCORE_FILE)
	rmdir $(HIGHSCORE_PATH)

pack:   
	rm -rf gtktetris.tgz
	tar -czvf gtktetris.tgz *.c *.h *.xpm Makefile




