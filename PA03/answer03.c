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
			new_dest_string[0] = '\0';
			*n = (1 + 2*(strlen(src)));
			 //strcpy(new_dest_string,*dest); // This doesn't work because *dest is not a string
			 // free(*dest); // Is freeing an Invalid Pointer
		}	
		
		else
		{		
			new_dest_string = malloc(sizeof(char)*(1 + 2*(strlen(*dest) + strlen(src))));
			new_dest_string[0] = '\0';	
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


	/*if(str == NULL)
	{
		return(str);
	} */

	while(str[str_index] != '\0')
	{
		if(strchr(delims,str[str_index]) != NULL)
		{
			num_delim += 1;
		}
		
		str_index++;
	}

	char** strArr = malloc((num_delim + 1) * sizeof(char*)); // This Allocates spaces to create (num_delim + 1) strings.

	int strArr_count = 0; // Flag for the no.of strings that can be accomodated in strArr
	
	int last_ind = 0; // Used to get the position where a character is last found.	
		
	int i = 0; // Index to check the strlen of str
	
	while(i <= strlen(str))	
	{
		if(strchr(delims,str[i]) == NULL) 
		{
			i++;
		}
		
		else
		{		
			if(i > last_ind)
			{
				 strArr[strArr_count] = malloc(sizeof(char)*(i - last_ind + 1));
				 memcpy(strArr[strArr_count],&str[last_ind],(i - last_ind)); 
       				 strArr[strArr_count][i - last_ind] = '\0';
	      			 strArr_count += 1; // Flag to exit the loop if all the memory is utilised

			}
			
			i++;	
			last_ind = i;	

		} 
	}

	
	*arrLen = num_delim + 1; // No.of Strings that are Returned.

	return(strArr);
}	
		
		

char* implode(char** strArr,int len,const char* glue)
{
	char* str;

	//char** strArr_dup = strArr;
	//int length = 0; // The Possible size of the output 


	// This loop is used to find the length of the resulting string after adding all the strings in strArr
	/*while(*strArr != '\0')
	{
		length = strlen(*strArr);
		strArr++;
	}



	strArr = strArr[0];

	str = malloc(sizeof(char)*(1 + 2*length));
	str[0] = '\0';
	strcpy(str,*strArr_dup);
	strcat(str,glue);	

	while(*strArr_dup != '\0')
	{
		strcpy(str,*strArr_dup + 1);
		strcat(str,glue);
		strArr_dup++;		
	}*/
		
	int i = 0;
	
	int length = 10;

	str = malloc(sizeof(char)*(length));
	
	for(i= 0; i < len;i++)
	{
		if(i == (len - 1))
		{
			strcat_ex(&str,&length,strArr[i]);
		}
		else
		{	
			strcat_ex(&str,&length,strArr[i]);			
			strcat_ex(&str,&length,glue);						
		}			
	}
	return(str);
} 



void sortStringArray(char ** arrString, int len)
{
	
}

void sortStringCharacters(char* str)
{

}

void destroyStringArray(char * * strArr, int len)
{

}




