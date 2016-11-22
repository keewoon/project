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




