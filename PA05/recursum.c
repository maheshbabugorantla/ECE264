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


void partitionall(int* arr,int ind,int left)
{
	int val;
	
	if(left == 0)
	{
		printPartition(arr,ind);
		return;
	}
	
	for(val = 1; val <= left; val += 1)
	{
		arr[ind] = val;	
		partitionall(arr,ind + 1,left - val);
	}
	
} 

void partitionInc(int* arr,int ind , int left)
{
	int val;
	
	if(left == 0)
	{
		printPartition(arr,ind);
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
		partitionInc(arr,ind + 1,left - val);
	}
}

void partitionDec(int* arr,int ind , int left)
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


	
	int val;
	
	if(left == 0)
	{
		printPartitionDec(arr,ind);
		return;
	}
	
	for(val = 1; val <= left; val += 1)
	{
		arr[ind] = val;	
		partitionDec(arr,ind + 1,left - val);
	}

}
	
// SOURCE: Prof. Yung Hsiang Lu Material , Chap: 14 , PageNo: 216
void partitionOdd(int* arr,int ind,int left)
{
	int val;

	if(left == 0)
	{
		printPartition(arr,ind);
		return;
	}

	for ( val = 1; val <= left; val += 2) // Odd Numbers Only
	{
		arr[ind] = val;
		partitionOdd(arr,ind + 1,left - val);
	}
}

// Idea Taken from the above Function
void partitionEven(int* arr,int ind,int left)
{
	int val;

	if(left == 0)
	{
		printPartition(arr,ind);
		return;
	}

	for ( val = 2; val <= left; val += 2) // Odd Numbers Only
	{
		arr[ind] = val;
		partitionEven(arr,ind + 1,left - val);
	}
}

/* For partitionEven Change the Print Partition (This is an Another Method)*/
	

void partitionOddAndEven(int* arr,int ind,int left)
{
	int val;
	if(left == 0)
	{
		printPartition(arr,ind);
		return;
	}

	for(val = 1; val <= left; val++)
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
			partitionOddAndEven(arr,ind + 1,left - val);
		}
	}
}

/*int main(int argc , char ** argv)
{
	

	if(argc != 2)
	{
		return(EXIT_FAILURE);
	}
		
	int n = (int) strtol(argv[1], NULL, 10);
	
	if(n <= 0)
	{
		return EXIT_FAILURE;
	} 

	int* arr;

	arr = malloc(sizeof(int) * 4);
	partitionall(arr,0,4);

	free(arr);

	arr = malloc(sizeof(int) * 15);

	printf("\n\n In Decreasing Order....\n\n");

	partitionDec(arr,0,15);
	
	free(arr);

	arr = malloc(sizeof(int) * 8);

	printf("\n\n In Even Order....\n\n");

	partitionEven(arr,0,8);
	
	free(arr);
	
	arr = malloc(sizeof(int) * 8);

	printf("\n\n Alternate Even and Odd Order....\n\n");

	partitionOddAndEven(arr,0,8);
	
	free(arr);


	return(EXIT_SUCCESS);

}*/
	
 
