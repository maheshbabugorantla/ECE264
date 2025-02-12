void print_tree(BusinessNode* Root,const char* filename1,const char* filename2)
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

}

void print_Locations(LocationNode* head, const char* filename_bus,const char* filename_rev)
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
}


