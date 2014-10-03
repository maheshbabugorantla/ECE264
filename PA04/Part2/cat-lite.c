#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc , char** argv)
{
	FILE *fileptr = NULL; // Pointer to the File

	int index = 0; // Used to run through all the Arguments in the Command Line

	int c;


	for(index = 1;index < argc;index++)
	{
		if(strcmp(argv[index],"--help") == 0)
		{
			printf("Usage: cat-lite [--help] [FILE]...\nWith no FILE, or when FILE is -, read standard input.\n\nExamples:\n  cat-lite README   Print the file README to standard output.\n  cat-lite f - g    Print f's contents, then standard input, \n                    then g's contents.\n  cat-lite          Copy standard input to standard output.\n\n"); 

			return(EXIT_SUCCESS);
		}
	}
			
	index = 0;

	for(index = 1; index < argc; index++)
	{

		fileptr = fopen(argv[index],"r");

		if(fileptr == NULL)
		{
			
			return(EXIT_FAILURE);
		}

		else 
		{	
			if(fileptr)
			{
				while((c = fgetc(fileptr)) != EOF)
				{				
					putchar(c);
				}
						
				fclose(fileptr);
			}

		}
	}


	return(EXIT_SUCCESS);
}

		
