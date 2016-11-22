#ifndef _TETRIS_H_
#define _TETRIS_H_

#include <gtk/gtk.h>

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#define MAX_X 10
#define MAX_Y 18

#ifdef BIGBLOCKS
#define BLOCK_WIDTH 22
#define BLOCK_HEIGHT 22
#else
#ifdef BIGGERBLOCKS
#define BLOCK_WIDTH 33
#define BLOCK_HEIGHT 33
#else
#define BLOCK_WIDTH 15
#define BLOCK_HEIGHT 15
#endif
#endif


#define NUM_LEVELS 20
#define NUM_HIGHSCORE 10

#define START_LEVEL_VALUE 6 // Iavor

// global variables
GtkWidget *game_area;
GtkWidget *next_block_area;
GdkPixmap *blocks_pixmap;
int game_over;
int game_pause;
int current_x;
int current_y;
int current_block;
int current_frame;
long current_score;
int current_level;
int current_lines;
int next_block;
int next_frame;
//int show_next_block;


struct Options
{
  int level;
  int noise_l;
  int noise_h;
  gint shw_nxt;
};

struct Options options;


// highscore.c
void read_highscore();
void write_highscore();
void show_highscore(int place);
void check_highscore();
int addto_highscore(char *name,long score, int level, int lines);

#endif

