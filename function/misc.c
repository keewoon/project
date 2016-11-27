#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <string.h>

#include "../include/tetris.h"

void set_block(int x,int y,int color,int next)
{
        gdk_draw_pixmap((!next ? game_area->window : next_block_area->window),
                        (!next ? game_area->style->black_gc : next_block_area->style->black_gc),
                        blocks_pixmap,
                        color*BLOCK_WIDTH,0,
                        x*BLOCK_WIDTH,y*BLOCK_HEIGHT,
                        BLOCK_WIDTH,BLOCK_HEIGHT);
}

int do_random(int max)
{
        return max*((float)random()/RAND_MAX);
}

void set_label(GtkWidget *label,char *str)
{
        gtk_label_set(GTK_LABEL(label), str);
}


void set_gtk_color_style(GtkWidget *w, long red, long green,  long blue)
{
        GtkStyle *style;
        GdkColormap *colormap;
        GdkColor color;

        style = gtk_style_new();
        colormap = gdk_colormap_get_system();
        color.red = red;
        color.green = green;
        color.blue = blue;
        gdk_color_alloc(colormap,&color);
        memcpy(style->fg,&color,sizeof(GdkColor));
        gtk_widget_set_style(w,style);
        gtk_style_unref(style);
}
