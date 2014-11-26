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
	int bus_id; // Id of a Business's different Location
	ReviewNode reviews;
	
}LocationNode;	


typedef struct business
{
	//BusinessNode* Root = NULL;
	struct business* Left; 
	struct business* Right;
	LocationNode* location;
	char* BusinessName;
	
}BusinessNode;	 

BusinessNode* create_business(char* businessname)
{
	BusinessNode* busNode = malloc(sizeof(BusinessNode)); // Have to allocate memory for the Business Node 
	
	busNode -> BusinessName = strdup(businessname); // strdup is done in another function 
	busNode -> Left = NULL; // Left Branch of the Binary Tree.
	busNode -> Right = NULL; // Right Branch of the Binary Tree.
	busNode -> location = NULL; // Used for storing the Address of different locations of a single business.
	
	return(busNode);
}

LocationNode* create_Location(long int bus_offset, long int rev_offset int count,int business_id)
{
	LocationNode* locNode = malloc(sizeof(LocationNode));	
	locNode -> offset = offset;
	locNode -> next = NULL;
	locNode -> bus_id = business_id;
	(locNode -> reviews).offset = rev_offset;
	(locNode -> reviews).no_reviews = count
	
	return locNode;
}

/* The Below Function is Used to insert the entering node at the Beginning. */

LocationNode* Location_list(LocationNode* head,long int bus_offset, long int rev_offset, int count,int business_id)
{
	if(head == NULL)
	{
		return(create_Location(bus_offset,rev_offset,count,business_id));
	}
	
	head -> next = Location_list(head -> next, bus_offset,rev_offset,count,business_id);	
		
	return(head);
}


// Change this to print the Reviews of the Each Independent Business location.
void print_Locations(LocationNode* head, const char* filename)
{
	FILE* fp = fopen(filename,"r");

	char* str = malloc(sizeof(char)* 2048); // Used to read and Print the address of the business Location.
	
	while(head != NULL)
	{
		fseek(fp,head -> offset,SEEK_SET); // makes the File Pointer Read at the offset from the beginning of the file.
 	
 		if(fgets(str,2048,fp) != NULL)
 		{
 			printf(" %s \n\n",str);
 		}
 		
 	//	printf("Offset is %ld",head -> offset);
 		
 		head = head -> next;
	}

	free(str);
	fclose(fp);
}

// CREATING THE BUSINESS BINARY TREE
BusinessNode* create_BST(char* business, BusinessNode* root,long int bus_offset,long int rev_offset, int count,int business_id)
{
	if(root == NULL)
	{
		BusinessNode* bus_node = create_business(business); // This Business Node has to created first.
		bus_node -> location = Location_list(bus_node -> location,bus_offset,rev_offset,count,business_id); // Location is created pointing from that Business Location.
		return bus_node; // Creates and Inserts the Node at the NULL.
	}
	
	// Here We add the Address of the Business Location(Offset in businesses.tsv File) to the location linked list (Because We do not need to add the same business name)
	
	if(strcmp(business , root -> BusinessName) == 0) 
	{ 
		root -> location = Location_list(root -> location,bus_offset,rev_offset,count,business_id);	
	} 
	
	if(strcmp(business , root -> BusinessName) < 0)
	{
		root -> Left = create_BST(business,root -> Left,bus_offset,rev_offset,count,business_id); // Inserts the Node in the Left Side of the Binary Tree.
	}
	
	if(strcmp(business , root -> BusinessName) > 0)
	{
		root -> Right = create_BST(business, root -> Right,bus_offset,rev_offset,count,business_id); // Inserts the Node in the Right Side of the Binary Tree.
	}
		
	return(root);	
}

void print_tree(BusinessNode* Root,const char* filename)
{
	if(Root == NULL)
	{
		return;
	}
	

	print_tree(Root -> Left,filename); // Prints the Left Side of the Tree

	printf("\n\nThe Business Name is %s at ",Root -> BusinessName);

	print_Locations(Root -> location,filename);

	print_tree(Root -> Right,filename); // Print the Right Side of the Tree

	//fclose(fp);	

}

// Destroying the Location List

void destroy_Loclist(LocationNode* location)
{
	while(location != NULL)
	{
		LocationNode* locpointer = location -> next;
		free(location);
		location = locpointer;
	}
}

void destroy_BST(BusinessNode* Root)
{
	if(Root == NULL)
	{
		return;
	}
	
	// Destroys the Left Part of the Tree
	destroy_BST(Root -> Left);
	
	// Destroys the Right part of the Tree
	destroy_BST(Root -> Right); 
	
	destroy_Loclist(Root -> location);
	free(Root -> BusinessName);
	free(Root);

	return;
}

BusinessNode* readfile(const char* filename1, const char* filename2)
{
	FILE* fp1 = fopen(filename1,"r");
	FILE* fp2 = fopen(filename2,"r");
	
	//fclose(fp2); // Shift it to the Bottom Once Done Constructing the Whole BST and Location Nodes Pointing. 
	
	char* str1 = malloc(sizeof(char)*2048);
	char* str2 = malloc(sizeof(char)*2048); // For Reviews.tsv
	
	BusinessNode* BST = NULL; // Initialize it to NULL.

	int len1 = 0;
	int len2 = 0;
	
	long int posbus = ftell(fp1); // File Pointer Position for the Businesses.tsv
	long int posrev = ftell(fp2); // File Pointer Position for the Reviews.tsv
		 
	int ind1 = 0; // For Business
	int ind2 = 0; // For Reviews
	int count = 0; // No.of Reviews
	
	while(fgets(str1, 2048, fp1)!= NULL)
	{
		 char** strArr1 = explode(str1,"\t",&len1);
		 
		 		 
		 //char* business = strArr[1]; // This gives the Business Name and Need not malloc the 'business' because malloc is done in explode.
		 
		 int business_id = atoi(strArr1[0]); // To get the business ID
		 long int bus_offset = posbus + strlen(strArr1[0]) + strlen(strArr1[1]) + 2; // Used to get the Offset of the Address Location in the File.
		
		// This Below Loop is used to get the offset the review and the no.of reviews.
		 while(fgets(str2,2048,fp2)!= NULL)
		 { 	
		 	char** strArr2 = explode(str2,"\t",&len2);
		 	long int rev_offset = posrev + strlen(strArr2[0]) + 1;
		 	
		 	/*if(atoi(strArr1[0]) > atoi(strArr2[0])) // If the businessID is less than the required businessID
		 	{
		 		posrev = ftell(fp2);
		 		// rev_offset = posrev  + strlen(strArr2[0]) + 1;
		 		
		 		for(ind2 = 0; ind2 < len2; ind2++)
			 	{
			 		free(strArr2[ind2]);
			 	} 
			 	free(strArr2);
		 	}*/		
		 		
		 	if(strcmp(strArr2[0],strArr1[0]) == 0)
		 	{
				count += 1;				 
		 
			 	for(ind2 = 0; ind2 < len2; ind2++)
			 	{
			 		free(strArr2[ind2]);
			 	}
			 	
			 	free(strArr2);
			 }
			 
			 // This is used to break if the Business ID is greater than the Required BusinessID 
			 else
			 {
			 	fseek(fp2,-strlen(str2),SEEK_CUR); // This Brings the File Pointer to the beginning of the Reviews of a Business Location.
				posrev = ftell(fp2);
				
				for(ind2 = 0; ind2 < len2; ind2++)
			 	{
			 		free(strArr2[ind2]);
			 	}
			 	
			 	free(strArr2);	
			 	
			 	break; 	
			 } 	
			 	
		}
		
		BST = create_BST(strArr1[1],BST,bus_offset,rev_offset,count,business_id);
		
		count = 0;
		 
		for(ind1 = 0; ind1 < len1; ind1++)
		{
			free(strArr1[ind1]);
		}
			 
			 
		// Updating the Position of the File Pointer
		posbus = ftell(fp1); 
			  
		free(strArr1);
			
	}
	
	free(str1);
	free(str2);
	fclose(fp1);
	fclose(fp2);
	
	return BST;
}
		 	
	
int main(int argc, char** argv)
{
		
	BusinessNode* Root = readfile("samplebus.tsv","samplerev.tsv");
	print_tree(Root,"samplebus.tsv");

	destroy_BST(Root);

	return(EXIT_SUCCESS);
}
	
	
	
	
