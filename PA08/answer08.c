#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"answer08.h"

List* Create_List(List* list,char* str); // Creates the List with all the nodes
List* List_Split(List** main,int half);


List * List_createNode(const char * str)
{

	List* list = malloc(sizeof(List)); // These Has to be freed Later using a Free Function
	
	if(list == NULL)
	{
		printf("\n\nList_createNode Malloc Failed\n\n");
		return(NULL);
	}
	
	list -> str = strdup(str); // Takes in the String as an Input , strdup allocates memory and puts the String in str 
	
	list -> next = NULL; // Has to be initialized to NULL else this will lead to Conditional Jumping which is a Valgrind Error.
	/* REMEMBER Here list -> str Has to be Free Later Or Else We will see a Valgrind Error */

	return(list);
}	

int List_length(List * list)
{
	int length = 0; // Length of the List

	while(list != NULL)
	{
		length += 1;
		list =  list -> next;
	}
	
	return(length);
}

List* Create_List(List* list,char* str)
{
	List* listdup = List_createNode(str); // This does malloc internally So Not Required to malloc again
	
	listdup -> next = list;
	
	return listdup;
}  

// Idea Taken from "Intermediate C Programming Book"
void List_destroy (List* head )
{
	while (head != NULL )
	{
		List* p = head -> next;
		free(head -> str); // Here it has to be done because we have used strdup in creating the Node.
		free (head);
		head = p;
	}
}	


/* This Function splits the List into 2 Halves */ 
List* List_Split(List** Main,int length)
{
	//List* head; // This points to the head node of the Linked List
	List* ptr; // This Stores the second half of the Linked List
	
	//head = *Main;
	ptr = *Main;

	length -= 1; 
	
	while(length > 0)
	{
		length -= 1;
		ptr = ptr -> next;
	}
	
	List* right =  ptr -> next;	
	ptr -> next = NULL;
	
	return(right);
	   
}

/*int compar(const void *a, const void *b)
{
	const char * const * str1 = (const char **) a;
	const char * const * str2 = (const char **) b;
	return strcmp(*str1,*str2);
}*/

List * List_merge(List * lhs, List * rhs, int (*compar)(const char *, const char*) )
{
	List* merge = NULL; // Has to be intialized to NULL 	

	// Base Case
	if(lhs == NULL) return(rhs);
	else if(rhs == NULL) return(lhs);
	
	if(compar(lhs -> str,rhs -> str) <= 0)
	{
		merge = lhs;
		merge -> next = List_merge(lhs -> next,rhs,compar);
	}
	
	else
	{
		merge = rhs;
		merge -> next = List_merge(lhs,rhs -> next,compar);	
	}
	
	return(merge);
}

List * List_sort(List * list, int (*compar)(const char *, const char*))
{

	//List* merged = NULL;

	if(list == NULL || list -> next == NULL)
	{
		return(list);	
	}
	
	List* rhs = List_Split( &list , List_length(list) / 2 );
	
	list = List_sort(list,compar);
	rhs = List_sort(rhs,compar);			
	
	list = List_merge(list,rhs,compar);	
	
	//List_destroy(rhs);
	
	return list;
	
}	

void List_print(List* list)
{
	int count = 0; // No.of nodes in the list
	 
	if(list == NULL)
	{
		printf("\n\nThe list has no Values\n\n");
		return;
	} 
	 
	while(list != NULL)
	{
		printf(" %d : %s \n",count,list -> str);
		list = list -> next;
		count += 1;
	}
	
	return;
}	

/*int main(int argc, char** argv)
{
	List* list = NULL;
	
	list = Create_List(list,"Ajay");
	list = Create_List(list,"Mahesh");
	list = Create_List(list,"Venu");
	list = Create_List(list,"Sarvani");
	list = Create_List(list,"Siva");
	list = Create_List(list,"Balakishore");
	list = Create_List(list,"Gangadhar");
	//list = Create_List(list,"Muralidhar");	
	
	printf("The Length of the Original list is %d\n\n", List_length(list));
	
	//List* lhs = NULL;
	List* rhs = NULL; // Has to be initialized to NULL
	
	//rhs = List_Split(&list,List_length(list) / 2);
	
	printf("The Length of the Left Half of the list is %d\n\n",List_length(list));
	printf("The Length of the Right Half of the list is %d\n\n",List_length(rhs));
	
	list = List_sort(list,compar);
	List_print(list);
	
	List_destroy(list); // This releases all the memory used by all the nodes in the List
	//List_destroy(rhs); // This has to be done because we are splitting 'list' into 2 halves and 'list' no more has 2nd Half.
	
	return (EXIT_SUCCESS);	
} */
	
