#include<stdio.h>
#include<string.h>
#include<gtk/gtk.h>

#include "../include/highscore.h"

struct item
{
	char name[10];
	long score;
	int level;
	int lines;

};

GtkWidget *highscore_window;

struct item highscore[NUM_HIGHSCORE];

void read_highscore()
{
  FILE *fp;
  if((fp = fopen(HIGHSCORE_FILE,"r")))
    {
      fread(&highscore,1,sizeof(highscore),fp);
      fclose(fp);
    }
}

void write_highscore()
{
  FILE *fp;
  if(!(fp = fopen(HIGHSCORE_FILE,"w")))
    return;
  fwrite(&highscore,1,sizeof(highscore),fp);
  fclose(fp);
}

void write_highscore()
{
  FILE *fp;
  if(!(fp = fopen(HIGHSCORE_FILE,"w")))
    return;
  fwrite(&highscore,1,sizeof(highscore),fp);
  fclose(fp);
}

core_close(){
  gtk_widget_hide(highscore_window);}

void show_highscore(int place)
{
        GtkWidget *highscore_border;
        GtkWidget *label;
        GtkWidget *table;
        GtkWidget *vbox;
        GtkWidget *Highscore_close_button;
        int temp;
        char dummy[40];

        highscore_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(highscore_window),"Highscores");
        gtk_window_set_policy(GTK_WINDOW(highscore_window),FALSE,FALSE,TRUE);
        gtk_window_set_position(GTK_WINDOW(highscore_window),GTK_WIN_POS_NONE/*CENTER*/);

        highscore_border = gtk_frame_new(NULL);
        gtk_frame_set_shadow_type(GTK_FRAME(highscore_border),GTK_SHADOW_IN/*OUT*/);
 	gtk_widget_show(highscore_border);
        gtk_container_add(GTK_CONTAINER(highscore_window),highscore_border);

        vbox = gtk_vbox_new(FALSE,3);
        gtk_container_add(GTK_CONTAINER(highscore_border),vbox);

        table = gtk_table_new(NUM_HIGHSCORE+1,5,FALSE);
        gtk_container_add(GTK_CONTAINER(vbox),table);

        label = gtk_label_new(" # ");
        gtk_widget_show(label);
        gtk_table_attach_defaults(GTK_TABLE(table),label,0,1,0,1);
        gtk_widget_set_usize(label,25,0);

        label = gtk_label_new(" Name: ");
        gtk_widget_show(label);
        gtk_table_attach_defaults(GTK_TABLE(table),label,1,2,0,1);
        gtk_widget_set_usize(label,100,0);

        label = gtk_label_new(" Lines: ");
        gtk_widget_show(label);
        gtk_table_attach_defaults(GTK_TABLE(table),label,2,3,0,1);

        label = gtk_label_new(" Level: ");
        gtk_widget_show(label);
	gtk_table_attach_defaults(GTK_TABLE(table),label,2,3,0,1);

        label = gtk_label_new(" Level: ");
        gtk_widget_show(label);
        gtk_table_attach_defaults(GTK_TABLE(table),label,3,4,0,1);

        label = gtk_label_new(" Score: ");
        gtk_widget_show(label);
        gtk_table_attach_defaults(GTK_TABLE(table),label,4,5,0,1);
                      
