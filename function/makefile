PROGRAM = gtktetris
BIN_PATH = /usr/local/bin
HIGHSCORE_PATH = /usr/local/games/gtktetris
GROUP = root
HIGHSCORE_FILE  = $(HIGHSCORE_PATH)/highscore.dat
CFLAGS = `pkg-config gtk+-2.0 --cflags` -Wall -O2 \
        -DHIGHSCORE_FILE=\"$(HIGHSCORE_FILE)\" $(SIZE)
LIBS = `pkg-config gtk+-2.0 --libs`
OBJS = misc.o highscore.o tetris.o interface.o
#SIZE = -DBIGGERBLOCKS
SIZE = -DBIGBLOCKS
CC = gcc


libfuncs.a: highscore.o misc.o tetris.o
<<<<<<< HEAD
   ar rv libfuncs.a highscore.o misc.o tetris.o
all: $(OBJS)
   $(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM) $(LIBS)
   strip $(PROGRAM)
=======
	ar rv libfuncs.a highscore.o misc.o tetris.o
all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM) $(LIBS)
	strip $(PROGRAM)
>>>>>>> 31657d565dc64dc881f5c5fbef8a7b8894d3827b
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




#       ln -s $(BIN_PATH)/$(PROGRAM) /usr/games/bin/tetris
uninstall:
	rm -i $(BIN_PATH)/$(PROGRAM)
	rm -i $(HIGHSCORE_FILE)
	rmdir $(HIGHSCORE_PATH)
