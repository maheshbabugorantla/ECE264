#include<stdio.h>
#include<stdlib.h>
#include"answer11.h"


int main(int argc, char** argv)
{
	//Stack* st = Stack_create();
	
	//char array[4] = "asdf";
	
	//int ind = 0;
	
	//HuffNode* * HFNArray[4];
	
	//for(ind = 0;ind < 4;ind ++)
	//{
	
	/*HuffNode* HFN1 = HuffNode_create('a');
	HuffNode* HFN2 = HuffNode_create('s');
	HuffNode* HFN3 = HuffNode_create('d');
	HuffNode* HFN4 = HuffNode_create('f');
						
	//}		
	
	Stack_pushFront(st,HFN1);
	Stack_pushFront(st,HFN2);	
	Stack_pushFront(st,HFN3);
	Stack_pushFront(st,HFN4);  
	
	//for(ind = 0; ind < 4; ind++)
	//{
	//	HuffNode* sample = Stack_popFront(st);
	//	printf("\n\nThe value in the Node %d is %c\n",ind + 1,sample -> value);
	//}
	
	//Stack_popPopCombinePush(st);
	
	Stack_destroy(st); */
	
	FILE* fptr = fopen("sample.txt","r");
	
	HuffNode* HNode = HuffTree_readTextHeader(fptr);
	
	HuffNode_destroy(HNode);
	
	fclose(fptr); 
	
	return(1);
}			
