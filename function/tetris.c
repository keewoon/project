#include<stdio.h>
#include<unistd.h>
#include<string.h>

#include"../include/tetris.h"

int virtual[MAX_Y][MAX_X];
int blocks = 7;
int block_frames[7] = {1,2,2,2,4,4,4};
int lines_score[4] = {40,100,300,1200};
int block_data[7][4][2][4] =
{
	{
	{{0,1,0,1},{0,0,1,1}}
	},
	{
	{{0,1,1,2},{1,1,0,0}}
	{{0,0,1,1},{0,1,1,2}}
	},
	{
	{{0,1,1,2},{0,0,1,1}},
	{{1,1,0,0},{0,1,1,2}}
	},
	{
	{{1,1,1,1},{0,1,2,3}},
	{{0,1,2,3},{2,2,2,2}}
	},
	{
	{{1,1,1,2},{2,1,0,0}},
	{{0,1,2,2},{1,1,1,2}},
	{{0,1,1,1},{2,2,1,0}},	
	{{0,0,1,2},{0,1,1,1}}
	},
	{
	{{0,1,1,1},{0,0,1,2}},
	{{0,1,2,2},{1,1,1,0}},
	{{1,1,1,2},{0,1,2,2}},
	{{0,0,1,2},{2,1,1,1}}
	},
	{
	{{1,0,1,2},{0,1,1,1}},
	{{2,1,1,1},{1,0,1,2}},
	{{1,0,1,2},{2,1,1,1}},
	{{0,1,1,1},{1,0,1,2}}
	}

};

void draw_block(int x,int y,int block,int frame,int clear,int next)
{
        int temp;
        for(temp=0;temp < 4;temp++)
                set_block(x+block_data[block][frame][0][temp],
                        y+block_data[block][frame][1][temp],
                        (clear ? 0 : block+1),
                        next);
}

void to_virtual()
{
        int temp;
        for(temp=0;temp < 4;temp++)
                virtual[current_y+block_data[current_block][current_frame][1][temp]]
                        [current_x+block_data[current_block][current_frame][0][temp]] = current_block+1;
}
void from_virtual()
{
        int temp_x,temp_y;
        for(temp_y=0;temp_y < MAX_Y;temp_y++)
                for(temp_x=0;temp_x < MAX_X;temp_x++)
                        set_block(temp_x,temp_y,virtual[temp_y][temp_x],FALSE);
}

int valid_position(int x,int y,int block,int frame)
{
        int temp;
        for(temp=0;temp < 4;temp++)
                if(virtual[y+block_data[block][frame][1][temp]][x+block_data[block][frame][0][temp]] != 0 ||
                                x+block_data[block][frame][0][temp] < 0 ||
                                x+block_data[block][frame][0][temp] > MAX_X-1 ||
                                y+block_data[block][frame][1][temp] < 0 ||
                                y+block_data[block][frame][1][temp] > MAX_Y-1)
                        return FALSE;
        return TRUE;
}



