#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv)
{
	FILE* fp = fopen("shortfile.tsv","r");
	
	
	if(fp == NULL)
	{
		printf("\nERROR\n\n");
		return(EXIT_FAILURE);
	}
	
	char* str = malloc(sizeof(char)*2000);
	
	while(fgets(str,2000,fp)!= NULL)
	{
		printf("\n\n %s \n\n",str);
	}
	
	free(str);
	
	return(EXIT_SUCCESS);
}

