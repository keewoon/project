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
   
struct Options
{
  int level;
  int noise_l;
  int noise_h;
  gint shw_nxt;
};

struct Options options;

// tetris.c
void draw_block(int x,int y,int block,int frame,int clear,int next);
void to_virtual();
void from_virtual();
int valid_position(int x,int y,int block,int frame);
void move_block(int x,int y,int f);
int check_lines();
int move_down();
void new_block();
void game_over_clean();
void game_init();
void make_noise(int level,int height);    
void set_block(int x,int y,int color,int next);

#endif                  
