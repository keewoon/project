#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "../include/tetris.h"
#include "tetris.xpm"

#ifdef BIGBLOCKS
#include "big_blocks.xpm"
#else
#ifdef BIGGERBLOCKS
#include "bbig_blocks.xpm"
#else
#include "block.xpm"
#endif
#endif

int level_speeds[NUM_LEVELS] = {1000,886,785,695,616,546,483,428,379,336,298,
                                264,234,207,183,162,144,127,113,100};
void update_game_values()
{
        char dummy[20] = "";

        sprintf(dummy,"%lu",current_score);	
        set_label(score_label2,dummy);

        sprintf(dummy,"%d",current_level);
        set_label(level_label2,dummy);

        sprintf(dummy,"%d",current_lines);
        set_label(lines_label2,dummy);
}

gint keyboard_event_handler(GtkWidget *widget, GdkEventKey *event, gpointer data)
{
   int dropbonus = 0;
   if(game_over || game_pause)
	return FALSE;
   switch(event->keyval)
   {
	case GDK_x; case GDK_X;
	move_block(0,0,1);
	event->keyval=0;
	return TRUE;
	break;
	
	case GDK_w: case GDK_W: case GDK_Up:
        move_block(0,0,-1);
        event->keyval=0;
        return TRUE;
        break;

	case GDK_s: case GDK_S:
      	move_down();
      	event->keyval=0;
      	return TRUE;
      	break;

	case GDK_a: case GDK_A: case GDK_Left:
      	move_block(-1,0,0);
      	event->keyval=0;
      	return TRUE;
      	break;

	case GDK_d: case GDK_D: case GDK_Right:
      	move_block(1,0,0);
      	event->keyval=0;
      	return TRUE;
      	break;

	case GDK_space: case GDK_Down:
      	   while(move_down())
        	dropbonus++;
      	current_score += dropbonus*(current_level+1);
      	update_game_values();
     	event->keyval=0;
       	return TRUE;
     	break;
   }
   return FALSE;
}





