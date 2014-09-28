#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv)
{
	FILE *fileptr ; // File Pointer to read through all the contents of the File
	
	int index = 1; // 'argv' String Index  
	
	char str[1000]; // Used to get the Line from the File that matches the required Pattern

	char c;

	if(argc < 3)
	{
		printf("Minimum of 2 Arguments along with Executable file name required \n\n"); // This is like "./exefilename (argv[1])[FILE1] (argv[2])[pattern in FILE1]"
		return(EXIT_FAILURE);
	} 


	fileptr = fopen(argv[index],"r"); // Opening the First File

	if(fileptr == NULL)
	{
		printf(" Sorry! File Cannot Be Opened\n\n");
		return(EXIT_FAILURE);
	}

	while((c = fgetc(fileptr)) != EOF)
	{
		if(strstr(&c,argv[2]) != NULL)
		{
			if(fgets(str,200,fileptr) != NULL)
			{
				puts(str);
			}

		}

		
	}


	fclose(fileptr);

	return(EXIT_SUCCESS);
}
