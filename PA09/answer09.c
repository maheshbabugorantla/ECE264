#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"answer09.h"

BusinessNode* create_node(char * stars, char * name, char * address)
{
	BusinessNode* BNode = malloc(sizeof(BusinessNode)); // Allocating the Size First
	
	if(BNode == NULL)
	{
		printf("\n\nMalloc for Creating the Node Failed\n\n");
		return(NULL);
	}
	
	BNode -> stars = stars;
	BNode -> name =  name;
	BNode -> address = address;
	BNode -> left = NULL;
	BNode -> right = NULL;
	
	return(BNode);
}


void print_tree(BusinessNode * tree)
{
	if(tree == NULL)
	{
		return;
	}
	
	// Printing in Order.
	print_tree(tree -> left);
	printf("\n\nRating: %s , Name: %s , Address: %s\n\n", tree -> stars, tree -> name, tree -> address);
	print_tree(tree -> right); 

}


void destroy_tree(BusinessNode * root)
{
	if(root == NULL)
	{
		return;
	}
	
	destroy_tree(root -> left);
	destroy_tree(root -> right);
	free(root -> stars);
	free(root -> name);
	free(root -> address);
	free(root); 
}


// Idea Taken from Prof. Yung Lu's Text Book.
BusinessNode* tree_insert(BusinessNode * node, BusinessNode * root)
{
	if(root	== NULL)
	{
		return node;
	}
		
	if(strcmp(node -> name,root -> name) == 0)
	{
		return(root);
	}
	
	if(strcmp(node -> name, root -> name) < 0)
	{
		root -> left = tree_insert(node, root -> left);
	}
	
	else
	{
		root -> right = tree_insert(node,root -> right);
	}
	
	return root;
} 
	
BusinessNode* load_tree_from_file(char* filename)
{
	FILE* fp = fopen(filename,"r"); // Open the File and Create a Buffer to Read 

	if(fp == NULL)
	{
		printf("\n\n FILE OPENING FAILED \n\n");
		return(EXIT_FAILURE);
	}
		
	BusinessNode* BNode = NULL;
	BusinessNode* root = NULL;
	
	char* str = malloc(sizeof(char)*2000);
	
	char** strArr
	
	while(fgets(str,2000,fp) != NULL)
	{
		strArr = explode(&str,'\t');
		BNode = create_node(strArr[0],strArr[1],strArr[2]);
		root = tree_insert(BNode,root);
		free(strArr);
	}
	
	free(str); // This has to be freed only outside the While loop because this its memory has to be used again for further fgets.
	
	fclose(fp);
		
	return root;
	
} 

	
int main(int argc, char** argv)
{
	char* str = strdup("5.0");
	char* str0 = strdup("Random Name");
	char* str_0 = strdup("Root Address");
	 
	BusinessNode* root = create_node(str,str0,str_0);
	
	BusinessNode* node1;
	BusinessNode* node2;
	BusinessNode* node3;
	BusinessNode* node4;
	
	char* str1 = strdup("4.0");
	char* str2 = strdup("Another Name");
	char* str3 = strdup("Left Address");
	char* str4 = strdup("3.0");
	char* str5 = strdup("Other Name");
	char* str6 = strdup("Right Address");
	char* str7 = strdup("2.0");
	char* str8 = strdup("Another Left");
	char* str9 = strdup("Left Left");
	char* str10 = strdup("1.0");
	char* str11 = strdup("Other Right");
	char* str12 = strdup("Left Right");
	  
	node1 = create_node(str1,str2,str3);
	node2 = create_node(str4,str5,str6);
	node3 = create_node(str7,str8,str9);
	node4 = create_node(str10,str11,str12);
	
	//  Inserting all into the Binary Tree
	root = tree_insert(node1,root);
	root = tree_insert(node2,root);
	root = tree_insert(node3,root);
	root = tree_insert(node4,root);
	
	print_tree(root);
	destroy_tree(root);
	
	return(EXIT_SUCCESS);
}
	
	
