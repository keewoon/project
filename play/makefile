interface.o: interface.c ../function/libfuncs.a
	gcc interface.c -L ../function -lfuncs -o interface.o `pkg-config --cflags --libs gtk+-2.0`
clean:
	rm -f interface.o

