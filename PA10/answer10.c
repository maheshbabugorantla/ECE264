#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"answer10.h"
#include<inttypes.h>

char** explode(const char* str, const char* delims,int* arrLen)
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
	
	*arrLen = num_delim + 1; // No.of Strings that are Returned.

	return(strArr);
}	



typedef struct review
{
	int no_reviews;
	long int offset; // For the reviews.tsv
}ReviewNode;


typedef struct location
{	
	struct location* next;
	long int offset; // For the businesses.tsv
	ReviewNode reviews;
	
}LocationNode;	


typedef struct business
{
	//BusinessNode* Root = NULL;
	struct business* Left;
	struct business* Right;
	LocationNode* location;
//	LocationNode* tail; // Used to point at the last node in the linked list (And Will point at the first Node if there is only one Node.)
	char* BusinessName;
	
}BusinessNode;	 

BusinessNode* create_business(char* businessname)
{
	BusinessNode* busNode = malloc(sizeof(BusinessNode));
	
	busNode -> BusinessName = businessname; // strdup is done in another function 
	busNode -> Left = NULL;
	busNode -> Right = NULL;
	busNode -> location = NULL;
	
	return(busNode);
}

LocationNode* create_Location()
{
	LocationNode* locNode = malloc(sizeof(LocationNode));	
	locNode -> offset = 0;
	return locNode;
}

/* The Below Function is Used to insert the entering node at the Beginning. */

LocationNode* Location_list(LocationNode* head,LocationNode* locNode)
{
	locNode -> next = head;
	
	return(locNode);
}


// CREATING THE BUSINESS BINARY TREE
BusinessNode* create_BST(char* business, BusinessNode* root,long int offset)
{
	if(root == NULL)
	{
		BusinessNode* bus_node = create_business(business); // This Business Node has to created first.
		bus_node -> location = create_location(); // Location is created pointing from that Business Location.
		bus_node -> location -> offset = offset; // The Assign the Offset Calculated in the Previous Caller Function.
		
		return bus_node; // Creates and Inserts the Node at the NULL.
	}
	
	// Here We add the Address of the Business Location(Offset in businesses.tsv File) to the location linked list (Because We do not need to add the same business name)
	
	/*if(strcmp(business , root -> BusinessName) == 0)
	{
		// Here We have to add the new location of the same Business to the Linked List.
	} */
	
	if(strcmp(business , root -> BusinessName) < 0)
	{
		root -> Left = create_BST(business,root -> Left); // Inserts the Node in the Left Side of the Binary Tree.
	}
	
	if(strcmp(business , root -> BusinessName) > 0)
	{
		root -> Right = create_BST(business, root -> Right); // Inserts the Node in the Right Side of the Binary Tree.
	}
		
	return(root);	
}

void print_tree(BusinessNode* Root,const char* filename)
{
	if(Root == NULL)
	{
		return;
	}
	
	FILE* fp = fopen(filename,"r");
	
	print_tree(Root -> Left); // Prints the Left Side of the Tree
	printf("The Business Name is %s at ",Root -> BusinessName);
	fseek(fp,Root -> location -> offset,SEEK_SET); // makes the File Pointer Read at the offset from the beginning of the file.
	//printf( 
	print_tree(Root -> Right); // Print the Right Side of the Tree
	fclose(fp);	
}

BusinessNode* readfile(const char* filename1, const char* filename2)
{
	FILE* fp1 = fopen(filename1,"r");
	FILE* fp2 = fopen(filename2,"r");
	
	fclose(fp2); // Shift it to the Bottom Once Done Constructing the Whole BST and Location Nodes Pointing. 
	
	char* str = malloc(sizeof(char)*2048);
	//char* str1 = malloc(sizeof(char)* 100);
	//char* str2 = malloc(sizeof(char)
	
	BusinessNode* BST = NULL; // Initialize it to NULL.
	//BusinessNode* BNode = NULL; // Create a Business Node with its Name.
	int len = 0;
	
	long int posbus = ftell(fp1); // File Pointer Position for the Businesses.tsv
	 
	
	while(fgets(str, 2048, fp1)!= NULL)
	{
		 char** strArr = explode(str,"\t",&len);
		 
		 char* business = strArr[1]; // This gives the Business Name and Need not malloc the 'business' because malloc is done in explode.
		 
		 long int offset = posbus + strlen(strArr[0]) + strlen(strArr[1]) + 2; // Used to get the Offset of the Address Location in the File.
		 
		 /* The above method is done because the way 'fgets' is used points at the start of a new line and first 2 elements of the string are Business ID and Business Name..... Hence We have to add the lengths of the first two strings and a 2 (because of 2 Tab Spaces in between) to the present 'fppos' as Shown Above */  
		 
		 //BNode = create_business(business); // Has to be freed later. (Doubtful of this)
		 
		 BST = create_BST(business,BST,offset);
		 
		 free(strArr);
	}	
	
	free(str);
	fclose(fp1);
	
	return BST;
}
		 	
	
int main(int argc, char** argv)
{
		
	BusinessNode* Root = readfile("samplebus.tsv","samplerev.tsv");
	print_tree(Root,samplebus.tsv);

	return(EXIT_SUCCESS);
}
	
	
	
	
