#ifndef _INTERFACE_H
#define _INTERFACE_H

#include <gtk/gtk.h>

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#define MAX_X 10
#define MAX_Y 18

#ifndef BIGBLOCKS
#define BLOCK_WIDTH 22
#define BLOCK_HEIGHT 22
#else
#ifndef BIGGERBLOCKS
#define BLOCK_WIDTH 33
#define BLOCK_HEIGHT 33
#else
#define BLOCK_WIDTH 15
#define BLOCK_HEIGHT 15
#endif
#endif

#define NUM_LEVELS 20
#define NUM_HIGHSCORE 10

#define START_LEVEL_VALUE 6

//global variables
GtkWidget *game_area;
GtkWidget *next_block_area;
GdkPixmap *blocks_pixmap;
int game_over;
int game_pause;
int current_x;
int current_y;
int current_block;
int current_frame;
int current_score;
int current_level;
int current_lines;
int next_block;
int next_frame;
//int show next block

struct Options
{
   int level;
   int noise_l;
   int noise_h;
   gint shw_nxt;
};

struct Options options;

//interface.c
void update_game_values();
int game_loop();
void game_over_init();
void game_set_pause();

#endif
