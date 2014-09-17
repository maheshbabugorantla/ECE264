#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"answer03.h"

int main(int argc, char** argv)
{
    // Test Case 1 for strcat_ex
	int n = 10;
	char* dest;
	dest = malloc(sizeof(char)*n);
	strcpy(dest,"Mahesh");
	const char* src = " Babu";	
	printf("The String1 is %s\n\n",strcat_ex(&dest,&n,src));

	free(dest);

    // Test Case 2 for strcat_ex

    	n = 0; // Because of NULL Pointer
	dest = NULL;
	src = "Mahesh Babu Gorantla";

	printf("The String2 is %s\n\n",strcat_ex(&dest,&n,src));
	free(dest); // Memory is allocated in the Function in this Case. :)

    // Test Case 3 for strcat_ex

	n = 12;

	dest = malloc(sizeof(char)*n);
	strcpy(dest,"Mahesh Babu");

	src = " Gorantla";

	printf("The String3 is %s\n\n",strcat_ex(&dest,&n,src));
	free(dest); // Memory is allocated in the Function in this Case. :)


     /*// Test Case 4 for strcat_ex

	n = 0;
	dest = NULL;
	src = NULL;

	printf("The String4 is %s\n\n",strcat_ex(&dest,&n,src));
	//free(dest); // Memory is allocated in the Function in this Case. :)
	*/			
				
	return(EXIT_SUCCESS);
}







