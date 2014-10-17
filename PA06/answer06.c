#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"answer06.h"

void print_path(char** maze,int count,int height,int width,int w, int h,char dir);

void print_directions(char** maze, int height, int width)
{
	// This below loop is used to check the Entry point of the Maze  
	/***************** STATUS : Successfully Finding the Entry Point *********************************************/
	
	int w = 0; // To iterate through the Width of the Maze
	//int h = 0; // To iterate through the Height of the Maze
	//int steps = 0; // No.of steps in Each Direction
	
	for(w = 0; w < width; w++)
	{
		if( maze[0][w] == ' ')
		{
			printf("\n\nEntry Point found at point (0, %d)\n\n",w);
			break;	
		}
	}

	print_path(maze,0,height,width,w,1,'S');
	
	return;
} 


void print_path(char** maze,int count,int height,int width,int w, int h,char dir)
{
	
	//int h1 = h;
	//int w1 = w;
	
	
	if(h == height||w == width||maze [h][w] == 'X')// || maze[w][h] =="")
	{
		printf("\n%c %d\n",dir,count);
		if(dir == 'S') 
		{
			printf("\n%c %d\n",'N',count);
		}
	
		if(dir == 'W') 
		{
			printf("\n%c %d\n",'E',count);
		}
		
		if(dir == 'E') 
		{
			printf("\n%c %d\n",'W',count);
		}
	
		count = 0;
			
		return;

	}
	
	if(w >= 0 && w < width)
	{
		if (h < height)
		{
			count += 1;
			
			if((h+1) < height && maze[h+1][w] == ' ')
			{	
				print_path(maze,count,height,width,w,h + 1,'S');
			}
			
			if(((w - 1) >= 0 && (w + 1) < width) && maze[h][w - 1] == ' ')
			{	
				print_path(maze,count,height,width,w - 1,h,'W');
			}

			if(((w + 1) < width && (w - 1) >=0) && maze[h][w + 1] == ' ' && dir != 'W')
			{
				print_path(maze,count,height,width,w + 1,h,'E');
			}	
		}
	}
	
	else
	{
		return;
	}
		
}	
