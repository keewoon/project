#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void gotoxy(int x, int y)
{
	COORD pos = {2 *x,y}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
