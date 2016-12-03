#ifndef _INTERFACE_H
#define _INTERFACE_H

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
void set_label(GtkWidget *label,char *str);
void move_block(int x,int y,int f);
int move_down();
void draw_block(int x,int y,int block,int frame,int clear,int next);
void from_virtual();
void set_gtk_color_style(GtkWidget *w, long red, long green,  long blue);
void get_opt_file(char *buf, int len);
void read_highscore();
void write_highscore();
void show_highscore(int place);
void game_init();
void make_noise(int level,int height);
int addto_highscore(char *name,long score, int level, int lines);
GtkWidget *label_box (GtkWidget *parent, GtkWidget *label, gchar *label_text);



#endif
