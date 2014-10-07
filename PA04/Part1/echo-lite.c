#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char * * argv)
{

	/*if(argc < 2)
	{
		fprintf(stderr,"Please enter atleast one arguments\n\n");
		
		return(EXIT_FAILURE);	
	}*/
	
		//printf("No.of arguments passed are %d.\n\n",argc);
		
		int count = 1;
	
		while(count < argc)
		{
			printf("%s ",argv[count]);			
			count++;
		} 

		printf("\n\n");
	return(EXIT_SUCCESS);
}		
