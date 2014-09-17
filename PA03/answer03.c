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


char** explode(const char* str, const char* delims,int* arrLen)
{
	int num_delim = 0; // No. of delimiters in the string 'delims'
	int str_index = 0; // String Index

	// This Below loop is used find out how many delimiters are in the string 'delims'

	while(str[str_index] != '\0' && (str_index < *arrLen))
	{
		if(strchr(delims,str[str_index]) != NULL)
		{
			num_delim += 1;
		}
		
		str_index++;
	}

	str_index = 0;  // Reinitializing the Main String Index

	char** strArr = malloc((num_delim + 1) * sizeof(char*)); // This Allocates spaces to create (num_delim + 1) strings.

	int strArr_count = 0;
	
	int last_ind = 0;	
		
	while(strArr_count < (num_delim + 1) && (str_index < *arrLen))
	{
		if(strchr(delims,str[str_index]) != NULL)
		{
			if(str_index > last_ind)
			{
				*strArr = malloc(sizeof(char)*(str_index - last_ind + 2));
				memcpy(*strArr,&str[last_ind],(str_index - last_ind + 1)); 
       
	      			strArr_count += 1; // Flag to exit the loop of all the memory is utilised
	 			strArr += 1; // Increments to the Next Row
			}

			last_ind = str_index;	
			str_index++;
			last_ind++;
		}

		else
		{
			str_index += 1;
		} 	
	
	}


	return(strArr);
}	
		
		

/*char* implode(char** strArr,int len,char* glue)
{
	char* str;

	char** strArr_dup = strArr;
	int length = 0; // The Possible size of the output 

	while(*strArr != '\0')
	{
		length = strlen(*strlen);
		*strArr++;
	}

	str = malloc(sizeof(char)*(1 + 2*length));

	strcpy(str,*strArr_dup)
	strcat(str,glue);	

	while(*strArr_dup != '\0')
	{
		strcpy(str,*strArr_dup + 1);
		strcat(str,glue);
		*strArr_dup++;		
	}
					
	return(str);
}*/




