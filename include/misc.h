#ifndef _MISC_H_
#define _MISC_H_

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


//misc.c
void set_block(int x, int y, int color, int next);
int do_random(int max);
void set_label(GtkWidget *label, char *str);
<<<<<<< HEAD

=======
>>>>>>> f695707f03fe083cb19e26f57b305c254e9c517a
void add_submenu(gchar *name, GtkWidget *menu, GtkWidget *menu_bar, int right);
GtkWidget *add_menu_item_toggle(gchar *name, GtkSignalFunc func, gpointer data, gint state, GtkWidget *menu);
GtkWidget *add_menu_item_toggle(gchar *name, GtkSignalFunc func, gpointer data, gint state, GtkWidget *menu);
void set_gtk_color_style(GtkWidget *w, long red, long green, long blue);
void get_opt_file(char *buf, int len);
GtkWidget *label_box(GtkWidget *parent, GtkWidget *label, gchar *label_text);

#endif


