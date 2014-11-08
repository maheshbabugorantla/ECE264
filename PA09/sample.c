#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"answer09.h"


char** explode(const char* str, const char* delims)
{
	int num_delim = 0; // No. of delimiters in the string 'delims'
	int str_index = 0; // String Index

	// This Below loop is used find out how many delimiters are in the string 'delims'

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
			//if(i > last_ind)
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

	
	//*arrLen = num_delim + 1; // No.of Strings that are Returned.
	
	return(strArr);
}	

int main(int argc, char** argv)
{
	FILE* fp = fopen("yelp_businesses.tsv","r");
	//FILE* fp = fopen("shortfile.tsv","r");
	
	
	if(fp == NULL)
	{
		printf("\nERROR\n\n");
		return(EXIT_FAILURE);
	}
	
	char* str = malloc(sizeof(char)*2048);
	char** strArr = NULL;
	int count = 0;
	
	BusinessNode* root = NULL; // The Root Node for the Binary Search Tree
	BusinessNode* node = NULL; // The Nodes that will be inserted later on.
	
	while(fgets(str,2048,fp)!= NULL)
	{
		//printf("\n\n %s \n\n",str);
		
		strArr = explode((const char*)str,"\t");
		
		/*printf("**************************************\n\nStars: %s\n",strArr[0]);
		printf("\nName: %s\n",strArr[1]);
		printf("\nAddress: %s**************************************\n\n",strArr[2]); */
		
		count += 1; 
		node = create_node(strArr[0],strArr[1],strArr[2]);
		root = tree_insert(node,root);
	
		//free(strArr[0]);
		//free(strArr[1]);
		//free(strArr[2]);
		free(strArr);
	}
	
	//printf("The Line Count is %d\n\n",count);
	
	free(str);
	fclose(fp);
	
	//print_tree(root);
	
	destroy_tree(root);
	
	return(EXIT_SUCCESS);
}

