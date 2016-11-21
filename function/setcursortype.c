#include<stdio.h>
#include<unistd.h>
#include<ncurses.h>
#include<time.h>
#include<stdlib.h>

typedef enum{NOCURSOR, SOLIDCURSOR, NORMALCURSOR} CURSOR_TYPE;

void setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO Curlnfo;

	switch(c)
	{
		case NOCURSOR:
			Curlnfo.dwSize = 1;
			Curlnfo.bVisible = 0;
			break;
		case SOLIDCURSOR:
			Curlnfo.dwSize = 100;
			Curlnfo.bVisible = 1;
			break;
		case NORMALCURSOR:
			Curlnfo.dwSize = 20;
			Curlnfo.bVisible = 1;
			break;
			
	}
		SetConsoleCursorlnfo(GetStdHandle(STD_OUTPUT_HANDLE),&Curlnfo);


}
