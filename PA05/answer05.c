#include<stdio.h>
#include<stdlib.h>
#include"answer05.h"


/******************* Idea taken from SOURCE: Prof. Yung Hsiang Lu - Course Notes Page No: 205   *********************************************************/

void printPartition(int*arr, int length)
{
	int ind;
	
	printf("=");

	for(ind = 0; ind <(length - 1); ind++)
	{
		printf(" %d + ",arr[ind]);
	} 
	
	printf(" %d\n",arr[length - 1]);
}


/********************************************** IDEA TAKEN FROM THE ABOVE PARTITION FUNCTION ********************************************************/
void printPartitionDec(int*arr, int length)
{
	int ind;

	for(ind = 0; ind < length - 1; ind++)
	{
		if(arr[ind] <= arr[ind + 1])
		{
			return;
		}
	
	}
	
	printf("=");
	
	for(ind = 0; ind <(length - 1); ind++)
	{
		printf(" %d + ",arr[ind]);
	} 
	
	printf(" %d\n",arr[length - 1]);
}


/******************* Idea taken from SOURCE Prof. Yung Hsiang Lu - Course Notes Page No: 205   *********************************************************/

void partitionall1(int* arr,int ind,int value)
{

	int val;
	
	if(value == 0)
	{
		printPartition(arr,ind);
		return;
	}
	
	for(val = 1; val <= value; val += 1)
	{
		arr[ind] = val;	
		partitionall1(arr,ind+1,value - val);
	}
}		
	

void partitionAll(int value)
{

	int ind = 0;
		
	int* arr;

	arr = malloc(sizeof(int) * value);	
	
	partitionall1(arr,ind,value);	

	free(arr);
} 


/******************* Idea taken from SOURCE Prof. Yung Hsiang Lu - Course Notes Page No: 216  *********************************************************/

void partitionInc1(int* arr,int ind, int value)
{

	int val;
	
	if(value == 0)
	{
		printPartition(arr,ind);
		return;
	}

	int min = 1;

	if(ind != 0)
	{
		min = arr[ind - 1] + 1;
	}

	for(val = min; val <= value; val++)
	{
		arr[ind] = val;
		partitionInc1(arr,ind + 1,value - val);
	}
}	

void partitionIncreasing(int value)
{
	int ind = 0;
		
	int* arr;

	arr = malloc(sizeof(int) * value);	
	
	partitionInc1(arr,ind,value);	

	free(arr);	
	
}

/******************* Idea taken from SOURCE Prof. Yung Hsiang Lu - Course Notes Page No: 205  *********************************************************/


void partitionDec1(int* arr,int ind,int value)
{
	
	int val;
	
	if(value == 0)
	{
		printPartitionDec(arr,ind);
		return;
	}
	
	for(val = 1; val <= value; val += 1)
	{
		arr[ind] = val;	
		partitionDec1(arr,ind + 1,value - val);
	}

}	
	

void partitionDecreasing(int value)
{
		
	int ind = 0;
		
	int* arr;

	arr = malloc(sizeof(int) * value);	
	
	partitionDec1(arr,ind,value);	

	free(arr);
	
}

/******************* Idea taken from SOURCE Prof. Yung Hsiang Lu - Course Notes Page No: 216   *********************************************************/	
	
void partitionOdd1(int* arr,int ind,int value)
{
	
	int val;

	if(value == 0)
	{
		printPartition(arr,ind);
		return;
	}

	for (val = 1; val <= value; val += 2) // Odd Numbers Only
	{
		arr[ind] = val;
		partitionOdd1(arr,ind + 1,value - val);
	}


}
		
void partitionOdd(int value)
{
	int ind = 0;
		
	int* arr;

	arr = malloc(sizeof(int) * value);	
	
	partitionOdd1(arr,ind,value);	

	free(arr);		
	
}

/******************* Idea taken from SOURCE Prof. Yung Hsiang Lu - Course Notes Page No: 216  *********************************************************/


void partitionEven1(int* arr,int ind, int value)
{
	int val;

	if(value == 0)
	{
		printPartition(arr,ind);
		return;
	}

	for (val = 2; val <= value; val += 2) // Even Numbers Only
	{
		arr[ind] = val;
		partitionEven1(arr,ind + 1,value - val);
	}
}


void partitionEven(int value)
{
	int ind = 0;
		
	int* arr;

	arr = malloc(sizeof(int) * value);	
	
	partitionEven1(arr,ind,value);	

	free(arr);
}

/******************************* Idea taken from SOURCE Prof. Yung Hsiang Lu - Course Notes Page No: 217 ***********************************************************/

void partitionOddAndEven1(int* arr,int ind, int value)
{
	int val;
	
	if(value == 0)
	{
		printPartition(arr,ind);
		return;
	}

	for(val = 1; val <= value; val++)
	{
		int valid = 0;
	
		if(ind == 0)
		{
			valid = 1;
		}
		
		else
		{
			valid = ((arr[ind - 1] % 2) != (val % 2));
		}

		if(valid == 1)
		{
			arr[ind] = val;
			partitionOddAndEven1(arr,ind + 1,value - val);
		}
	}
	
}	

void partitionOddAndEven(int value)
{
	int ind = 0;
		
	int* arr;

	arr = malloc(sizeof(int) * value);	
	
	partitionOddAndEven1(arr,ind,value);	

	free(arr);	
} 

/******************************** Idea taken from SOURCE Prof. Yung Hsiang Lu - Course Notes Page No: 205  *********************************************************/

void partitionPrime1(int* arr, int ind, int value)
{

	int val;
	
	if(value == 0)
	{
		printPartition(arr,ind);
		return;
	}	
	
	int flag = 0; // Notification if the number is a Composite
	
	int index = 2; // To Check if the Number is Prime
	
	for(val = 2; val<=value;val++)
	{
	
		// This For Loop is Used to Check if a Number is a Prime Number or not
		
		/* I chose with 2 Because the '1' is neither prime not composite And.. Most of the numbers will be divisible by 2 Like For an first 10 multiples of a given Number 5 numbers will be divisible by 2. Hence, Most of our loop checking stops at 2 or might go until 3. */
				 
		for( index = 2; index < val;index ++)
		{
			if((val % index) == 0)
			{	
				flag = 1; // Composite Number Found
				break;
			}
			
			else
			{
				flag = 0;
			}
		}
		
		if(!flag)
		{	
			arr[ind] = val;
			partitionPrime1(arr, ind + 1, value - val);
		}	
	}
	
}


void partitionPrime(int value)
{
	int ind = 0;
	
	int* arr;
	
	arr = malloc(sizeof(int) * value);
	
	partitionPrime1(arr,ind, value);
	
	free(arr);
	
	return;	
}	
	
 
 
