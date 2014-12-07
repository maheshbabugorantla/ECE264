#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"answer10.h"
#include<strings.h>
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


typedef struct YelpDataBST
{	
	char* BusFile;
	char* RevFile; 
	BusinessNode* BNode;			

}YelpData;


BusinessNode* create_business(char* businessname)
{
	BusinessNode* busNode = malloc(sizeof(BusinessNode)); // Have to allocate memory for the Business Node 
	
	busNode -> BusinessName = strdup(businessname); // strdup is done in another function 
	busNode -> Left = NULL; // Left Branch of the Binary Tree.
	busNode -> Right = NULL; // Right Branch of the Binary Tree.
	busNode -> location = NULL; // Used for storing the Address of different locations of a single business.
	
	return(busNode);
}

LocationNode* create_Location(long int bus_offset, long int rev_offset, int count,int business_id)
{
	LocationNode* locNode = malloc(sizeof(LocationNode));	
	locNode -> offset = bus_offset;
	locNode -> next = NULL;
	locNode -> bus_id = business_id;
	(locNode -> reviews).offset = rev_offset;
	(locNode -> reviews).no_reviews = count;
	
	return locNode;
}

/* The Below Function is Used to insert the entering node at the End. */

LocationNode* Location_list(LocationNode* head,long int bus_offset,long int rev_offset,int count,int business_id)
{
	if(head == NULL)
	{
		return(create_Location(bus_offset,rev_offset,count,business_id));
	}
	
	head -> next = Location_list(head -> next, bus_offset,rev_offset,count,business_id);	
		
	return(head);
}

uint32_t Loclist_length(LocationNode* loclist)
{
	uint32_t length = 0;
	
	LocationNode* list = loclist;
	
	while(list != NULL)
	{
		length += 1;
		list = list -> next;
	}
	
	return(length);
} 

// This is to print the Reviews of the Each Independent Business location.
/*void print_Locations(LocationNode* head, const char* filename_bus,const char* filename_rev)
{
	FILE* fp_bus = fopen(filename_bus,"r"); // for Businesses.tsv
	FILE* fp_rev = fopen(filename_rev,"r"); // For Reviews.tsv 

	char* str_bus = malloc(sizeof(char)* 6000); // Used to read and Print the address of the business Location.
	char* str_rev = malloc(sizeof(char)* 6000); // Used to read and print the review of the business Location.
	int count_rev = 0; // For printing all the reviews.
	//long int offset_rev = 
	
	while(head != NULL)
	{
		fseek(fp_bus,head -> offset,SEEK_SET); // makes the File Pointer Read at the offset from the beginning of the file.
 	
 		if(fgets(str_bus,6000,fp_bus) != NULL)
 		{
 			printf(" %.80s\n",str_bus); // Prints the Business Name and Address
 			
 			count_rev = (head -> reviews).no_reviews; // Gets the no.of reviews. 				
 		
 			fseek(fp_rev,(head -> reviews).offset,SEEK_SET);
 			
 			if(fgets(str_rev,6000,fp_rev) != NULL)
 			{
 			
 				// This Below loop is used to print the reviews of a business Location.
 				while(count_rev > 0)
 				{
 					printf("      %.70s\n",str_rev); // Prints review from a specific Customer.
 					fseek(fp_rev,1 + (int)(floor(log10(head -> bus_id)) + 1),SEEK_CUR); 
 					fgets(str_rev,6000,fp_rev);
 					count_rev -= 1;
 				}	 
 			}
 		
 	//	printf("Offset is %ld",head -> offset);
 		}
 		
 		head = head -> next;
	}

	free(str_bus); // Have to free this
	free(str_rev); // Have to free this...
	fclose(fp_bus);
	fclose(fp_rev);
} */

// CREATING THE BUSINESS BINARY TREE
BusinessNode* create_BST(char* business, BusinessNode* root,long int bus_offset,long int rev_offset, int count,int business_id)
{
	if(root == NULL)
	{
		BusinessNode* bus_node = create_business(business); // This Business Node has to created first.
		bus_node -> location = create_Location(bus_offset,rev_offset,count,business_id); // Location is created pointing from that Business Location.
		return bus_node; // Creates and Inserts the Node at the NULL.
	}
	
	// Here We add the Address of the Business Location(Offset in businesses.tsv File) to the location linked list (Because We do not need to add the same business name)
	
	if(strcasecmp(business , root -> BusinessName) == 0) 
	{ 
		root -> location = Location_list(root -> location,bus_offset,rev_offset,count,business_id);	
	} 
	
	if(strcasecmp(business , root -> BusinessName) < 0)
	{
		root -> Left = create_BST(business,root -> Left,bus_offset,rev_offset,count,business_id); // Inserts the Node in the Left Side of the Binary Tree.
	}
	
	if(strcasecmp(business , root -> BusinessName) > 0)
	{
		root -> Right = create_BST(business, root -> Right,bus_offset,rev_offset,count,business_id); // Inserts the Node in the Right Side of the Binary Tree.
	}
		
	return(root);	
}

/*void print_tree(BusinessNode* Root,const char* filename1,const char* filename2)
{
	if(Root == NULL)
	{
		return;
	}
	

	print_tree(Root -> Left,filename1,filename2); // Prints the Left Side of the Tree

	printf("\n\nThe Business Name is %s at ",Root -> BusinessName);

	print_Locations(Root -> location,filename1,filename2);

	print_tree(Root -> Right,filename1,filename2); // Print the Right Side of the Tree

	//fclose(fp);	

} */

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

YelpData* readfile(const char* busfilename, const char* revfilename)
{
	FILE* fp1 = fopen(busfilename,"r");
	FILE* fp2 = fopen(revfilename,"r");
	
	if(fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "Failed to open %s, or %s, or both\n", busfilename, revfilename);
		return NULL;
	}
	
	YelpData* BusinessData = malloc(sizeof(YelpData));
	
	BusinessData -> BusFile = strdup(busfilename);
	BusinessData -> RevFile = strdup(revfilename);
	
	//fclose(fp2); // Shift it to the Bottom Once Done Constructing the Whole BST and Location Nodes Pointing. 
	
	char* str1 = malloc(sizeof(char)*6000);
	char* str2 = malloc(sizeof(char)*6000); // For Reviews.tsv
	
	BusinessNode* BST = NULL; // Initialize it to NULL.

	int len1 = 0;
	int len2 = 0;
	
	long int posbus = ftell(fp1); // File Pointer Position for the Businesses.tsv
	long int posrev = ftell(fp2); // File Pointer Position for the Reviews.tsv
		 
	int ind1 = 0; // For Business
	int ind2 = 0; // For Reviews
	int count = 0; // No.of Reviews
	
	while(!feof(fp1))
	{	
			
		 if(feof(fp1))
		 {
		 	break;
		 }
		 
		 fgets(str1,6000,fp1);
		 
		 char** strArr1 = explode(str1,"\t",&len1);
		 		 
		 //char* business = strArr[1]; // This gives the Business Name and Need not malloc the 'business' because malloc is done in explode. 
		 int business_id = atoi(strArr1[0]); // To get the business ID
		 long int bus_offset = posbus + strlen(strArr1[0]) + strlen(strArr1[1]) + 2; // Used to get the Offset of the Address Location in the File.
		 long int rev_offset = 0;	
		
		// This Below Loop is used to get the offset the review and the no.of reviews.
		 while(fgets(str2,6000,fp2)!= NULL)
		 { 	
		 	char** strArr2 = explode(str2,"\t",&len2);
		 	rev_offset = posrev + strlen(strArr2[0]) + 1;
		 			 		
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
			 
			 	//if(strlen(str2) > 0)
			 	//{
			 	fseek(fp2,-strlen(str2),SEEK_CUR); // This Brings the File Pointer to the beginning of the Reviews of a Business Location.
				//}
				
				/*else
				{
					break;
				}*/
				
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
	
	BusinessData -> BNode = BST;
	
	return BusinessData;
}

// CREATING YELP DATA BUSINESS TREE		 	
struct YelpDataBST* create_business_bst(const char* businesses_path,const char* reviews_path)
{
	return(readfile(businesses_path,reviews_path));
}

int comparfunc_rev(const void* arg1,const void* arg2)
{
	const struct Review* ptr1 = (const struct Review *)arg1;
	const struct Review* ptr2 = (const struct Review *)arg2;
	
	uint8_t val1 = (*ptr1).stars;
	uint8_t val2 = (*ptr2).stars;
	
	if(val1 < val2) { return 1; }
	if(val1 == val2) 
	{ 
		if(strlen((*ptr1).text) > strlen((*ptr2).text))
		{
			return(-1);
		}
		
		if(strlen((*ptr1).text) < strlen((*ptr2).text))
		{
			return(1);
		}
		
		return 0; 
	}
	
	return(-1);
} 

int comparfunc_loc(const void* arg1,const void* arg2)
{
	const struct Location* ptr1 = (const struct Location *)arg1;
	const struct Location* ptr2 = (const struct Location *)arg2;
	
	// Comparing the States
	if(strcasecmp((*ptr1).state,(*ptr2).state) < 0)
	{
		return(-1);
	}
	
	if(strcasecmp((*ptr1).state,(*ptr2).state) > 0)
	{
		return(1);
	}
	
	// Same State
	else
	{
		if(strcasecmp((*ptr1).city,(*ptr2).city) < 0)
		{
			return(-1);
		}
		
		if(strcasecmp((*ptr1).city,(*ptr2).city) > 0)
		{
			return(1);
		}
		
		// Same City
		else
		{
			// Comparing the Addresses
			if(strcasecmp((*ptr1).address,(*ptr2).address) < 0)
			{
				return(-1);
			}
			
			if(strcasecmp((*ptr1).address,(*ptr2).address) > 0)
			{
				return(1);
			}
			
			else
			{
				return(0);
			}
		}
	}	
}


// A DUPLICATE FUNCTION TO GET THE REVIEWS OF A BUSINESS FUNCTION.
struct Business* Get_Reviews(FILE* bus_file, FILE* rev_file, BusinessNode* bst,char* name,char* state,char* zip_code)
{			
	
	//This is the Case where we haven't found any BusinessName
	if(bst == NULL)
	{
		//printf("\n\nCannot find the Business Name U asked for...??? Please try an another Business Name\n\n"); 
		return(NULL);
	} 

	if(strcasecmp(name,bst -> BusinessName) < 0)
	{
		return(Get_Reviews(bus_file,rev_file,bst -> Left,name,state,zip_code));
	} 	
	
	if(strcasecmp(name,bst -> BusinessName) > 0)
	{
		return(Get_Reviews(bus_file,rev_file,bst -> Right,name,state,zip_code));
	}

	//Here I need to create the business Reviews and return the Business 
	else
	{
		struct Business* bus_loc = malloc(sizeof(struct Business)); // Have to Allocate Memory. ( DO NOT DO IT Outside this 'if' Statement )
	
		char* str_bus = malloc(sizeof(char)*6000); // For the Business Address and related Data
		char* str_rev = malloc(sizeof(char)*6000); // For the Reviews of a specific Location.
	
		bus_loc -> name = strdup(bst -> BusinessName);
			
		// Checking with Location Nodes for the required state and zip_code
		LocationNode* new_loc = bst -> location;	
	
		int len = 0; // For the "explode" Function on str_bus.
	
		uint32_t length_list = Loclist_length(new_loc); // Used for allocating the Memory for storing all the details of the Locations of a Business.
	
		bus_loc -> num_locations = length_list;
		
		// HERE WE CREATE ENOUGH MEMORY for an Array of type "Location" to STORE ALL THE LOCATIONS of a Business.
		bus_loc -> locations = malloc(sizeof(struct Location)*length_list);  
		
		int ind_null = 0; 
	
		for(ind_null = 0;ind_null<length_list;ind_null++)
		{
			bus_loc -> locations[ind_null].address = NULL;
		}	
	
		int count = 0; // For 'Location' array index
	
		while(new_loc != NULL) // || length_list != 0)
		{
			fseek(bus_file,new_loc -> offset,SEEK_SET); // Takes the File Pointer to the offset of a Specified Address Location of a Business in the file. 	
			
			fgets(str_bus,6000,bus_file); // Getting all the details of a Business (Business Location).
			
			char** Arr_Bus = explode(str_bus,"\t",&len);
						 
			//printf("\n\n State: %s\n Zip_Code: %s \n %d \nZip_Code_File: %s\n",state,zip_code,(state == NULL && strcasecmp(Arr_Bus[3],zip_code) == 0),Arr_Bus[3]);
			if(((state == NULL) && (zip_code == NULL)) || (state == NULL && strcasecmp(Arr_Bus[3],zip_code) == 0) || (zip_code == NULL && strcasecmp(Arr_Bus[2],state) == 0) || (state != NULL && zip_code != NULL && ((strcasecmp(Arr_Bus[2],state) == 0) && (strcasecmp(Arr_Bus[3],zip_code) == 0))))
			{
				bus_loc -> locations[count].address = strdup(Arr_Bus[0]); // Address Location.
				bus_loc -> locations[count].city = strdup(Arr_Bus[1]); // City
				bus_loc -> locations[count].state = strdup(Arr_Bus[2]); // State
				bus_loc -> locations[count].zip_code = strdup(Arr_Bus[3]); // Zip_Code
				bus_loc -> locations[count].num_reviews = (new_loc -> reviews).no_reviews;
				bus_loc -> locations[count].reviews = malloc(sizeof(struct Review)*(bus_loc -> locations[count].num_reviews));
			
				// Now input all the reviews into the Reviews list.
			
				int reviews_count = 0; // Have to Create a Duplicate Variable.
			
				fseek(rev_file,(new_loc -> reviews).offset,SEEK_SET); // To Move Reviews File Pointer into specified business Reviews Location.
			
				while(reviews_count < (bus_loc -> locations[count].num_reviews))
				{
					fgets(str_rev,6000,rev_file);
				
					int len_rev = 0; // for 'explode' on rev string
				
					char** Arr_Rev = explode(str_rev,"\t",&len_rev);
				
					if(len_rev == 5)
					{
						((bus_loc -> locations[count].reviews)[reviews_count]).stars = atoi(Arr_Rev[0]); // Input the Star Rating.
						((bus_loc -> locations[count].reviews)[reviews_count]).text = strdup(Arr_Rev[4]); // Input the Review text.
				        }
				        
				        else
				        {
				        	((bus_loc -> locations[count].reviews)[reviews_count]).stars = atoi(Arr_Rev[1]); // Input the Star Rating.
						((bus_loc -> locations[count].reviews)[reviews_count]).text = strdup(Arr_Rev[5]); // Input the Review text.
				        }	
				        
					//fseek(rev_file,1 + (int)(floor(log10(new_loc -> bus_id)) + 1),SEEK_CUR); // Put the File Pointer pointing from the Star Rating in the line.
					int ind_rev = 0; // Index to free Arr_rev		
				
					// Freeing the Arr_Rev
					for(ind_rev = 0; ind_rev < len_rev;ind_rev++)
					{
						free(Arr_Rev[ind_rev]);
					}
					free(Arr_Rev);
						
					reviews_count += 1;					
		 		}		 	
		 		
		 			 	
		 		// SORT THE REVIEWS ARRAY ACCORDING TO THE STAR RATING IN DESCENDING ORDER.
				qsort(&(bus_loc -> locations[count]).reviews[0],bus_loc -> locations[count].num_reviews,sizeof(struct Review),comparfunc_rev); 
				
				count += 1;
							
			}
				
				int ind_bus = 0;
					
				for(ind_bus = 0; ind_bus < len;ind_bus++)
				{
					free(Arr_Bus[ind_bus]);
				}					
				free(Arr_Bus);				
				
				new_loc = new_loc -> next;
					 	
		}	
		
		//printf("\nNo_Locations: %d\n",bus_loc -> num_locations);
		bus_loc -> num_locations = count;
		//printf("\nCount: %d\n",count);
		
		qsort(&(bus_loc -> locations[0]),bus_loc -> num_locations,sizeof(struct Location),comparfunc_loc);
		
		free(str_bus);
		free(str_rev);
		
		return(bus_loc);
		
	}
}

// GET THE REVIEWS OF A GIVEN BUSINESS LOCATION (By Giving a Business Name, State and ZipCode)
struct Business* get_business_reviews(struct YelpDataBST* bst,char* name, char* state, char* zip_code) 
{	
	FILE* bus_file = fopen(bst -> BusFile,"r");
	FILE* rev_file = fopen(bst -> RevFile,"r");

	struct Business* bus_struct = Get_Reviews(bus_file,rev_file,bst -> BNode,name,state,zip_code);
	
	fclose(bus_file);
	fclose(rev_file);
	
	return(bus_struct);
}

void destroy_business_result(struct Business* b)
{
	free(b -> name); // Freeing the Business Name
	int ind_loc = 0;

	// This Loop is used to free the locations Array
	for(ind_loc = 0;ind_loc < (b -> num_locations);ind_loc++)
	{
		if(b -> locations[ind_loc].address == NULL)
		{
			break;
		}

		free((b -> locations[ind_loc]).address);	
		free((b -> locations[ind_loc]).city);
		free((b -> locations[ind_loc]).state);
		free((b -> locations[ind_loc]).zip_code);
		
		// Now Free the Reviews Array
		int ind_rev = 0;
		
		for(ind_rev = 0; ind_rev < (b -> locations[ind_loc]).num_reviews; ind_rev++)
		{
			free(((b -> locations[ind_loc]).reviews[ind_rev]).text);
		}
		
		free((b -> locations[ind_loc]).reviews);
		
		//free(b -> locations[ind_loc]);
	}	
	 
	//Finally Free the Memory of the Location struct
	free(b -> locations);
	
	//Free Business
	free(b);	 
}	

void destroy_business_bst(struct YelpDataBST* bst)
{
	destroy_BST(bst -> BNode);
	
	free(bst -> BusFile); // Freeing the Businesses File Name 
	free(bst -> RevFile); // Freeing the Reviews File Name
	free(bst); // Freeing the YelpData
	
	return;
}
	
/*int main(int argc, char** argv)
{
		
	YelpData* Root = create_business_bst("samplebus.tsv","samplerev.tsv");
	//print_tree(Root -> BNode,"bus.tsv","rev.tsv");
	
	struct Business* business_rev = get_business_reviews(Root,"Starbucks",NULL,"12345");
	
	destroy_business_result(business_rev);
	
	destroy_business_bst(Root);

	return(EXIT_SUCCESS);
}*/
	
	
	
	

