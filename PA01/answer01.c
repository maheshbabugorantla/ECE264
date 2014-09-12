#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
  int sum = 0; // Used to0 Store the sum of the values
  int index = 0; // Loop Variable

  for(index = 0;index < len;index ++)
  {
    sum += array[index];
  }  
  return(sum);
}

int arrayCountNegative(int * array, int len)
{
  int index = 0; // Looping Variable
  int negCount = 0; // No.of negative numbers in an array
  
  for(index = 0; index<len;index++)
    {
      if(array[index]<0)
	{
	 negCount+=1;
	}
    }
  return(negCount);
}

int arrayIsIncreasing(int * array, int len)
{ 
  int incStatus = 0;
  int index = 0;

  if(len == 0|| len == 1)
    {
      return(1);
    }
  else
    {
      for(index=0;index< len -1;index++)
	{
	  if(array[index]>array[index + 1])
	    {
	      return(0);
	    }
	  else
	    {
	      incStatus = 1;
	    }
	}
    }
  
  return(incStatus);
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
  int index = 0; // Loop Variable
  int IndexR = -1; // Right most index of the needle element

  for(index = 0; index<len;index++)
    {
      if( haystack[index] == needle )
	{
	  IndexR = index;
	}
    }  
  return(IndexR);
}

int arrayFindSmallest(int * array, int len)
{
  int index = 0; // Loop Variable
  int smallest = array[0]; // Smallest element in the Array
  int LIndex = 0; // Left-most Index of the Smallest element in the Array

  for(index = 1;index<len;index++)
    {
      if(array[index]<smallest)
	{
	  smallest = array[index];
	  LIndex  = index;
	}
    }
 
  return(LIndex);
}
