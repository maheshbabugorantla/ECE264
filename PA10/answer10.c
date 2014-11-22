#include<stdio.h>
#include<stdlib.h>
#include"answer10.h"
#include<string.h>
#include<inttypes.h>

typedef struct ReviewNode
{
	int no_reviews = 0;
	long int offset;
}

typedef struct LocationNode
{	
	LocationNode* left = NULL;
	int id; //  Business ID of the Business
	const char* Address; // The Address of the Business Location
	const char* city; // The City location of the Business
	const char* state; // The State in which the Business is located
	const char* zip_code; // The Zip-Code of the Business
	ReviewNode* reviews; // The Reviews of the Each Individual Business Location.
}	

typedef struct BusinessNode
{
	//BusinessNode* Root = NULL;
	BusinessNode* Left = NULL;
	BusinessNode* Right = NULL;
	LocationNode* location = NULL;
	const char* BusinessName;
}	 


LocationNode* create_location(LocationNode* loc,int id, const char* address,const char* city, const char* state,const char* zip_code)
{
	loc -> id = id;
	loc -> Address = strdup(address);
	loc -> city = strdup(city);
	loc -> state = strdup(state);
	loc -> zip_code = strdup(zip_code);
	/* Other Attributes ( Reviews will be passed from the main function */ 
	return(loc);
}

BusinessNode* create_Business(BusinessNode* business, const char* name, int id, const char* address,const char* city, const char* state,const char* zip_code)
{
	business -> name = strdup(name);
	
	LocationNode* loc;
	
	loc = create_location(loc,name,id,address,city,state,zip_code);

	business -> location = loc; // Entering the location details of the business
		
	/* The Reviews will passed from the main function */
}


int main(int argc, char* argv)
{
	char* filename1 = "/home/mahesh/Documents/ECE264/ECE264Assignments/GITHUB/ECE264/PA10/samplebus.tsv";
	char* filename2 = "/home/mahesh/Documents/ECE264/ECE264Assignments/GITHUB/ECE264/PA10/samplerev.tsv";

	FILE* file1ptr = fopen(filename1,"r");
	FILE* file2ptr = fopen(filename2,"r");
	
	long int offset = ftell(fileptr2);
	
	/* Write the explode
	
