#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"answer11.h"

HuffNode * HuffNode_create(int value)
{
	HuffNode* HNode = malloc(sizeof(HuffNode));
	
	HNode -> value = value;
	HNode -> left = NULL;
	HNode -> right = NULL;
	
	return(HNode);
}

void HuffNode_destroy(HuffNode* tree)
{
	if(tree == NULL)
	{
		return;
	}

	HuffNode* LHF = tree -> left;
	HuffNode* RHF = tree -> right;
	
	HuffNode_destroy(LHF);
	HuffNode_destroy(RHF);
	
	free(tree);
}

Stack* Stack_create()
{
	Stack* stack = malloc(sizeof(Stack));
	stack -> head = NULL;
	
	return(stack);
}   

int Stack_isEmpty(Stack* stack)
{
	if(stack == NULL)
	{
		return(1);
	}
	
	return(0);
}

void Stack_destroy(Stack* stack)
{
	if(Stack_isEmpty(stack))
	{
		return;
	}
	
	if(stack -> head == NULL)
	{
		free(stack);
		return;
	}
		
	StackNode* Head = stack -> head;		
		
	while(Head != NULL)
	{
		StackNode* SNode = Head -> next;
		HuffNode_destroy(Head -> tree);
		free(Head);
		Head = SNode;
	}
	
	free(stack);
	
	return;
}   		
	
HuffNode * Stack_popFront(Stack * stack)
{
	if(stack == NULL)
	{
		printf("\n\nERROR! Cannot Pop an Empty Stack\n\n");
		return(NULL);
	}
	
	HuffNode* Tree = stack -> head -> tree;
	StackNode* temp = stack -> head -> next;
	free(stack -> head);
	stack -> head = temp;
	
	return(Tree);
}	

Stack* Stack_push(Stack* stack,HuffNode* tree)
{
	
	StackNode* temp = malloc(sizeof(StackNode)); 		
	temp -> tree = tree; // Assigining the tree

	if(stack == NULL)
	{
		stack = Stack_create();
	}
	
	StackNode* temp_main = stack -> head; // This makes 'temp_main' point to the stack's head.
	stack -> head = temp; // Makes the stack's head point to the 'temp'
	temp -> next = temp_main; // And point 'temp -> next' to the 'stack -> head'. 		
	
	return(stack);
}

void Stack_pushFront(Stack* stack,HuffNode* tree)
{	 
	stack = Stack_push(stack,tree);		
}	

void Stack_popPopCombinePush(Stack * stack)
{
	HuffNode* right = Stack_popFront(stack);
	HuffNode* left = Stack_popFront(stack);
	
	HuffNode* new = malloc(sizeof(HuffNode));

	new -> value = 0; // Don't Care Not Required.
	new -> left = left; // Sending in the last popped node into the left node of the Huffman Tree
	new -> right = right; // Sending in the first popped node into the right node of the Huffman Tree
	
	Stack_pushFront(stack,new); // Pushing the Newly made tree.
}

HuffNode* HuffTree_readTextHeader(FILE* fp)
{
	if(fp == NULL)
	{
		printf("\nInput File Pointer cannot be NULL\n\n");
		return(NULL);
	}
	
	Stack* st = Stack_create();
	
	int flag = 0;
	
	while(flag != 1)
	{
		char ch = fgetc(fp);
					
		if(ch == '1')
		{
		
			char val = fgetc(fp);
		
			if(!isascii(val))
			{
				printf("\n\n Cannot add ASCII please check the Header of your Compressed File\n\n");
				flag = 1;	
				break;
			}
			
			
			HuffNode* HFN = HuffNode_create(val);			
	
			Stack_pushFront(st,HFN);
		}
		
		else 
		{
			if(st -> head -> next == NULL) // Means the Stack has only one Node
			{
				flag = 1;				
			}
				
			else
			{
				Stack_popPopCombinePush(st);
			}
		}

	}

	HuffNode* FinalTree = st -> head -> tree;
	
	free(st -> head);
	free(st);
			
	return(FinalTree);				
}

HuffNode* HuffTree_readBinaryHeader(FILE* fp)
{
	if(fp == NULL)
	{
		printf("\nInput File Pointer cannot be NULL\n\n");
		return(NULL);
	}
	
	Stack* st = Stack_create();
	
	int flag = 0;
	
	int whichbit = 0;
	
	while(flag != 1)
	{
		if(whichbit == 7)
		{
			whichbit = 0;
		}	
		
		char ch = fgetc(fp);
		
		unsigned char mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
		
		unsigned char masked = ch & mask[whichbit]; 
					
		if(masked != 0)
		{
		
			whichbit += 1;
			
			char val = fgetc(fp);
		
			if(!isascii(val))
			{
				printf("\n\n Cannot add ASCII please check the Header of your Compressed File\n\n");
				flag = 1;	
				break;
			}
			
			
			HuffNode* HFN = HuffNode_create(val);			
	
			Stack_pushFront(st,HFN);
		}
		
		else 
		{
		
			whichbit += 1;
		
			if(st -> head -> next == NULL) // Means the Stack has only one Node
			{
				flag = 1;				
			}
				
			else
			{
				Stack_popPopCombinePush(st);
			}
		}

	}

	HuffNode* FinalTree = st -> head -> tree;
	
	free(st -> head);
	free(st);
			
	return(FinalTree);				
}



