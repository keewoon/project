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

