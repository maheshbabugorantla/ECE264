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

	
 	/******************************************** EXPLODE FUNCTION *******************************************/	


	// TEST Case 1 

	int len1 = 0;

	char** strArr = explode("Mahesh\tBabu Gorantla"," \t\n\r\f\v",&len1);

	printf("String1 is %s\n\n",strArr[0]);			
	printf("String2 is %s\n\n",strArr[1]);			
	printf("String3 is %s\n\n",strArr[2]);		

	int i = 0; // No. Of Rows in strArr

	printf("Length : %d\n\n",len1);

	for(i = 0;i < len1;i++)
	{
		free(strArr[i]);
	}	

	free(strArr);		

	// Test Case2 
	
	int j = 0;
	
	int len2 = 0;

	char** strArr1 = explode("The\tTuring Test"," \t\n\r\f\v",&len2);

	printf("String1 is %s\n\n",strArr1[0]);			
	printf("String2 is %s\n\n",strArr1[1]);			
	printf("String3 is %s\n\n",strArr1[2]);		

	for(j = 0;j < len2;j++)
	{
		free(strArr1[j]);
	}	

	free(strArr1);		
	

	
 	/******************************************** IMPLODE FUNCTION *******************************************/	


	/*int length;
	char** strArr2 = explode("100 224 147 80", " ",&length);
	char * str = implode(strArr, length,", ");
	
	printf(" The Glued String is %s\n\n",str);

	int k = 0;
	
	for(k = 0; k < length; k++)
	{
		free(strArr2[k]);
	}
	
	free(strArr2); */
	
	
	/******************************************** sortStringArray FUNCTION *******************************************/

	int len;
	char * * strArr2 = explode("lady beatle brew", " ", &len);
	sortStringArray(strArr2, len);
	//char * str = implode(strArr, len, " ");
	printf("String1: %s\n",strArr2[0]); // beatle brew lady
	printf("String2: %s\n",strArr2[1]); // beatle brew lady
	printf("String3: %s\n",strArr2[2]); // beatle brew lady		

	destroyStringArray(strArr2,len);


	/******************************************** sortStringCharacters FUNCTION *******************************************/
	
	char * s1 = strdup("How did it get so late so soon?");
	sortStringCharacters(s1);	
	printf("The Sorted String is %s\n\n",s1);	
	free(s1);

	char * s2 = strdup("Mahesh Babu Gorantla is an Asshole");
	sortStringCharacters(s2);	
	printf("The Sorted String is %s\n\n",s2);	
	free(s2);			 

		
	return(EXIT_SUCCESS);
}







