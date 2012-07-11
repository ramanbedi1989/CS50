/**************************************************************************** 
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/
       
#include <cs50.h>

#include "helpers.h"


/*
 * Returns true if value is in array of n values, else false.
 */

bool 
search(int value, int array[], int n)
{
    // TODO: re-implement as binary search
    for (int i = 0; i < n; i++)
        if (array[i] == value)
            return true;
    return false;
}


/*
 * Sorts array of n values.
 */

void 
sort(int values[], int n)
{
	int size,size1;
	k=n;
	for (size1 = 0; size1 < n-1; size1++)
	{	
		for (size = 0; size < k-1; size++)
		{
        		if(values[i]>values[i+1])
			{	
				int temp;	
				temp=values[i];
				values[i]=values[i+1];
				values[i+1]=temp;
			}	
		}
		k--;
	}    	
	return;
}
