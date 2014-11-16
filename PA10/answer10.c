#include<stdio.h>
#include<stdlib.h>
#include"answer10.h"
#include<inttypes.h>

struct ReviewNode
{
	int no_reviews = 0;
	long int offset;
}

struct LocationNode
{	
	LocationNode* left = NULL;
	char* Address;
	char* city;
	char* state;
	char* zip_code;
	ReviewNode* reviews;
}	

struct BusinessNode
{
	//BusinessNode* Root = NULL;
	BusinessNode* Left = NULL;
	BusinessNode* Right = NULL;
	LocationNode* location = NULL;
	char* BusinessName;
}	 

struct BusinessTree
{
			
