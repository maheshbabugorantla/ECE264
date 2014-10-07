#include<stdio.h>
#include<stdlib.h>
#include"answer05.h"

void printPartition(int*arr, int length)
{
	int ind;
		
/*	for(ind = 0;ind < length ; ind++)
	{
		if((arr[ind] % 2) != 0)
		{
			return;
		}
	}*/
	
	for(ind = 0; ind <(length - 1); ind++)
	{
		printf("%d + ",arr[ind]);
	} 
	
	printf("%d\n",arr[length - 1]);
}

void printPartitionDec(int*arr, int length)
{
	int ind;
	
/*	for(ind = 0;ind < length ; ind++)
	{
		if((arr[ind] % 2) != 0)
		{
			return;
		}
	}*/

	for(ind = 0; ind < length - 1; ind++)
	{
		if(arr[ind] <= arr[ind + 1])
		{
			return;
		}
	
	}
	
	for(ind = 0; ind <(length - 1); ind++)
	{
		printf("%d + ",arr[ind]);
	} 
	
	printf("%d\n",arr[length - 1]);
}


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
	/*int val;
	
	if(left == 0)
	{
		printPartitionDec(arr,ind);
		return;
	}

	int min = 1;

	if(ind != 0)
	{
		min = arr[ind - 1] + 1;
	}

	for(val = min; val <= left; val++)
	{
		arr[ind] = val;
		partitionDec(arr,ind + 1,left - val);
	} */
	
	int ind = 0;
		
	int* arr;

	arr = malloc(sizeof(int) * value);	
	
	partitionDec1(arr,ind,value);	

	free(arr);
	
}

	
	
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
		
	
// SOURCE: Prof. Yung Hsiang Lu Material , Chap: 14 , PageNo: 216

void partitionOdd(int value)
{
	int ind = 0;
		
	int* arr;

	arr = malloc(sizeof(int) * value);	
	
	partitionOdd1(arr,ind,value);	

	free(arr);		
	
}

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


// Idea Taken from the partitionOdd Function
void partitionEven(int value)
{
	int ind = 0;
		
	int* arr;

	arr = malloc(sizeof(int) * value);	
	
	partitionEven1(arr,ind,value);	

	free(arr);
}

//  For partitionEven Change the Print Partition (This is an Another Method)
	


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

void partitionPrime1(int* arr, int ind, int value)
{

	int val;

	/*if( value == 2)
	{
		return;
	}
	
	if(value == 3)
	{
		return;
	}*/
	
	if(value == 0)
	{
		printPartition(arr,ind);
		return;
	}	
	
	int flag; // Notification if the number is a Composite
	
	int index; // To Check if the Number is Prime
	
	for(val = 2; val<=value;val++)
	{
		for( index = 2; index < val;index ++)
		{
			if((val % index) == 0)
			{	
				flag = 1; // Composite Number Found
			}
			
			else
			{
				flag = 0;
			}
		}
		
		if(!flag)
		{	
			arr[ind] = val;
			partitionPrime1(arr, ind + 1,value - val);
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
	
 
 
