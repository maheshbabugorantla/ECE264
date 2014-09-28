#include<stdio.h>
#include<stdlib.h>

int main(int argc , char* argv)
{
	FILE *fptr = NULL;

	fptr = fopen(argv[1],"r");

	int count = 0;// Line Number of the Text File

	char c;

	if(fptr == NULL)	
	{
		printf("File Cannot Opened\n");
		return(EXIT_SUCCESS);
	}

	while((c = fgetc(fptr)) != EOF)
	{
		printf(" %d : ",count);		
		fgets(fptr);

		count++;
	}

	fclose(fptr);

	return(EXIT_SUCCESS);
}

