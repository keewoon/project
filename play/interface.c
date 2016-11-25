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


int game_play;
char options_f[100];
char *pause_str[2]={"Pause\0","Resume\0"};
char *start_stop_str[2]={"Start Game\0","Stop game\0"};
gint timer;
GtkWidget *score_label1;
GtkWidget *score_label2;
GtkWidget *level_label1;
GtkWidget *level_label2;
GtkWidget *lines_label1;
GtkWidget *lines_label2;
GtkWidget *menu_game_quick;
GtkWidget *menu_game_start;
GtkWidget *menu_game_stop;
GtkWidget *menu_game_quit;
GtkWidget *menu_game_pause;
GtkWidget *menu_game_show_next_block;
GtkWidget *menu_save_options;
GtkWidget *spin_level;
GtkWidget *spin_noise_level;
GtkWidget *spin_noise_height;
GtkWidget *new_game_window;
GtkWidget *Start_stop_button;
GtkWidget *Start_stop_button_label;
GtkWidget *Pause_button;
GtkWidget *Pause_button_label;
GtkWidget *help_window;
GtkWidget *about_window;



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

void game_show_next_block(GtkMenuItem *menuitem, gpointer user_data)
{
   options.shw_nxt = !options.shw_nxt;
   if(!game_over)
   {
	if(!option.shw_nxt)
	   draw_block(0,0,next_block, next_frame, TRUE, TRUE);
	else
	   draw_block(0,0,next_block, next_frame, FALSE, TRUE);
   }
}

gint game_area_expose_event(GtkWidget *widget, GdkEventExpose *event, gpointer user_data)
{
   if(!game_over)
   {
	from_virtual();
	move_blcok(0,0,0);
   }
   else
	gdk_draw_rectangler(widget->window, 
			    widget->style->black_gc,
			    TRUE,
			    0, 0,
			    widget->allocation.width,
			    widget->allocation.height);
   return FALSE;
}

gboolean next_block_area_expose_event(GtkWidget *widget, GdkEventExpose *event, gpointer user_data)
{
        gdk_draw_rectangle(widget->window,
               		   widget->style->black_gc,
                	   TRUE,
                	   0,0,
                	   widget->allocation.width,
                	   widget->allocation.height);
        if(!game_over && options.shw_nxt)
                draw_block(0,0,next_block,next_frame,FALSE,TRUE);
        return FALSE;
}

int game_loop()
{
	if(!game_over)
	{
		timer = gtk_timeout_add(level_speeds[current_level],
					(GtkFunction)game_loop, NULL);
		move_down();
	}
	return FALSE;
}

void game_set_pause_b()
{
  if(game_pause)
    gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu_game_pause),FALSE);
  else
    gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu_game_pause),TRUE);
  return;
}

void game_set_pause(GtkWidget    *menuitem,
                    gpointer         user_data)
{
   if (game_over)
    {
      gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(menu_game_pause),
                                     FALSE);
      return;
    }
  game_pause = !game_pause;
  if(game_pause) {
    gtk_timeout_remove(timer);
    gtk_label_set(GTK_LABEL(Pause_button_label),pause_str[1]);
  }
  else {
    timer = gtk_timeout_add(level_speeds[current_level],
                            (GtkFunction)game_loop,NULL);
    gtk_label_set(GTK_LABEL(Pause_button_label),pause_str[0]);
  }
}


void game_over_init()
{
        int high_dummy;
        read_highscore();
        if(current_score && (high_dummy = addto_highscore((char *)getenv("USER"),current_score,current_level,current_lines)))
        {
                write_highscore();
                show_highscore(high_dummy);
        }

        game_over = TRUE;
        game_play = FALSE;
        gdk_draw_rectangle(game_area->window,
                game_area->style->black_gc,
                TRUE,
                0,0,
                game_area->allocation.width,
                game_area->allocation.height);

        gdk_draw_rectangle(next_block_area->window,
                next_block_area->style->black_gc,
                TRUE,
                0,0,
                next_block_area->allocation.width,
                next_block_area->allocation.height);
        game_set_pause(GTK_WIDGET(menu_game_pause),NULL);
        gtk_label_set(GTK_LABEL(Start_stop_button_label),start_stop_str[0]);
        gtk_widget_set_sensitive(menu_game_quick,TRUE);
        gtk_widget_set_sensitive(menu_game_start,TRUE);
        gtk_widget_set_sensitive(menu_game_stop,FALSE);
        gtk_widget_set_sensitive(Start_stop_button,TRUE);
        gtk_widget_grab_default(Start_stop_button);
        gtk_label_set(GTK_LABEL(Pause_button_label),pause_str[0]);
        gtk_widget_set_sensitive(Pause_button,FALSE);

        gtk_timeout_remove(timer);
}


void game_start_stop(GtkMenuItem     *widget,
                     gpointer user_data)
{
  game_play=!game_play;
  gtk_widget_set_sensitive(GTK_WIDGET(widget), FALSE);
  if(game_play)
    {
      gtk_widget_set_sensitive(menu_game_stop,TRUE);
      gtk_widget_set_sensitive(menu_game_quick,FALSE);
      gtk_widget_set_sensitive(menu_game_start,FALSE);
      gtk_widget_set_sensitive(Start_stop_button,TRUE);
      gtk_label_set(GTK_LABEL(Start_stop_button_label),start_stop_str[1]);
      gtk_widget_set_sensitive(Pause_button,TRUE);
      gtk_widget_grab_default(Pause_button);
      game_init();
      make_noise(options.noise_l,options.noise_h);
      from_virtual();
      move_block(0,0,0);
      current_level = options.level;
      update_game_values();
      timer = gtk_timeout_add(level_speeds[current_level],(GtkFunction)game_loop,NULL);
    }
  else
    game_over_init();
}

void about_close()
{
   gtk_widget_hide(about_window);
}

void show_about(GtkMenuItem	*menuitem, gpointer	user_data)
{
	GtkWidget *About_close_button;
	GtkWidget *about_label;
	GtkWidget *about_border;
	GtkWidget *about_border;
	GtkWidget *v_box;

	about_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(about_window), "About");
	gtk_window_set_policy(GTK_WINDOW(about_window), FALSE, FALSE, TRUE);
	gtk_window_set_position(GTK_WINDOW(about_window), GTK_WIN_POS_CENTER);
	gtk_container_border_width(GTK_CONTAINER(about_window),1);

	about_border = gtk_frame_new(NULL);
	gtk_frame_set_shadow_type(GTK_FRAME(about_border), GTK_SHADOW_OUT);
	gtk_container_Add(GTK_CONTAINER(about_window), about_border);

	v_box = gtk_vbox_new(FALSE, 0);
	gtk_container_Add(GTK_CONTAINER(about_border),v_box);

	about_label = gtk_label_new(  "\nJust another GTK Tetris v0.6.2\n\n"
                                        "(c)1999,2000 Mattias Wadman\n\n"
                                        "Modified by Iavor Veltchev, 2002-2006\n\n"
                                        "This program is distributed under the terms of GPL.\n");
	gtk_box_pack_start(GTK_BOX(v_box), about_label, FALSE, FALSE, 0);

	About_close_button = gtk_button_new_with_label("Close");
	g_signal_connect((gpointer) About_close_button, "clicked",
			 G_CALLBACK (about_close), NULL);
	gtk_box_pack_start(GTK_BOX(v_box), About_close_button, FALSE, TRUE,0);
	GTK_WIDGET_sET_FLAGS(About_close_butto, GTK_CAN_DEFAULT);
	gtk_widget_grab_default(About_close_button);

	gtk_window_show_all(about_window);

}

void help_close()
{
	gtk_widget_hide(help_window);
}

void show_help(GtkMenuItem	*menuitem, gpointer	user_data)
{
	GtkWidget *Help_close_button;
	GtkWidget *help_label;
	GtkWidget *help_border;
	GtkWidget *hbox;
	GtkWidget *vbox;

	help_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(help_window), "Help");
	gtk_window_set_policy(GTK_WINDOW(help_window), FALSE, FALSE, TRUE);
	gtk_window_set_position(GTK_WINDOW(help_window), GTK_WIN_POS_CENTER);
	gtk_container_border_width(GTK_CONTAINER(help_window),1);
	
	help_border = gtk_frame_new(NULL);
	gtk_frame_Set_shadow_type(GTK_FRAME(help_border), GTK_SHADOW_OUT);
	gtk_container_add(GTK_CONTAINER(help_window), help_border);

	vbox = gtk_vbox_new(FALSE, 3);
	gtk_container_add(GTK_CONTAINER(help_border), vbox);

	hbox = gtk_hbox_new(FALSE, 30);
	gtk_container_add(GTK_CONTATINER(vbox), hbox);

	help_label = gtk_label_new(	"\nKeys:\n"
					"Right and \"d\"\n"
					"Left and \"a\"\n"
					"\"s\"\n"
					"Up and \"w\"\n"
					"\"x\"\n"
                                        "Space ans Down\n\n"
                                        "Score: score*level\n"
                                        "Single\n"
                                        "Double\n"
                                        "Triple\n"
                                        "TETRIS\n\n"
                                        "Drop bonus: rows*level\n");

	gtk_misc_set_alignment(GTK_MISC(help_label), 0,0);
	gtk_label_set_justify(GTK_LABEL(help_label), GTK_JUSTIFY_LEFT);
	gtk_box_pack_start(GTK_BOX(hbox), help_label, TRUE, TRUE, TRUE);
	
	help_label = gtk_label_new(	"\n\n"
                                        "move right\n"
                                        "move left\n"
                                        "move down\n"
                                        "rotate ccw\n"
                                        "rotate cw\n"
                                        "drop block\n\n\n"
                                        "40\n100\n"
                                        "300\n1200\n");

	gtk_mise_set_alignment(GTK_MISC(help_label), 0,0);
	gtk_label_set_justify(GTK_LABEL(help_label), GTK_JUSTIFY_LEFT);
	gtk_box_pack_start(GTK_BOX(hbox), help_label, TRUE, TRUE, TRUE);
	
	Help_close_button = gtk_button_new_with_label("Close");
	g_signal_connect ((gpointer) Help_close_button, "clicked", 
			  G_CALLBACK (help_close), NULL);

	gtk_box_pack_start(GTK_BOX(vbox), HELP_close_buttion, FALSE, TRUE, 0);
	GTK_WIDGET_SET_FLAGS(Help_close_button, GTK_CAN_DEFAULT);
	gtk_window_grab_default(Help_close_button);

	gtk_widget_show_all(help_window);
}



















