#include"answer03.h"


char * strcat_ex(char** dest, int * n, const char * src)
{

	char* new_dest_string;
	
	/*if(src == NULL && *dest == NULL)
	{
		return(" ");
	}*/

	
	if((*dest == NULL) ||( *n < (1 + strlen(src) + strlen(*dest))))
	{			
		if(*dest == NULL)
		{
			new_dest_string = malloc(sizeof(char)*(1 + 2*(strlen(src))));
			*n = (1 + 2*(strlen(src)));
			 //strcpy(new_dest_string,*dest); // This doesn't work because *dest is not a string
			 // free(*dest); // Is freeing an Invalid Pointer
		}	
		
		else
		{		
			new_dest_string = malloc(sizeof(char)*(1 + 2*(strlen(*dest) + strlen(src))));
			*n = (1 + 2*(strlen(*dest) + strlen(src)));
			strcpy(new_dest_string,*dest);
			free(*dest);

		}				
		
		*dest = new_dest_string; 
		strcat(*dest,src);
		//free(new_dest_string); // Doing this Will return an Empty String instead use free(dest) in the main function
	}

	else
	{
		strcat(*dest,src);
	}
	
	

	return(*dest);
}


		
		


	
						
