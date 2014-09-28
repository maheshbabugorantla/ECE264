#include<stdio.h>
#include<stdlib.h>

int main(int argc , char** argv)
{
	FILE *fileptr = NULL; // Pointer to the File

	int index = 0; // Used to run through all the Arguments in the Command Line

	int c;

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

		
