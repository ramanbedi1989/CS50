#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void 
sort(int values[], int n);
void 
bubble(int values[], int n);
void mergesort(int a[], int low, int high);
void main(void)
{
	int element,kind;	
	printf("Enter the number of elements in the array:");
	scanf("%d",&element);
	//key=element;
	printf("Enter the data in the array:\n");
	int i;
	int array[element];	
	for(i=0;i<element;i++)	
	{	
	scanf("%d",&array[i]);
	}
	printf("Enter the number of the kind of sorting you want : \n1.Selection Sort\n2.Bubble Sort\n3.Merge Sort\n");
	scanf("%d",&kind);
	int size1; 
	int r[element];
	int valuescopy[element];
	switch(kind)
	{	
		case 1:
		sort(array,element);
		break;
		case 2:
		bubble(array,element);
		break;
		case 3:
		mergesort(array, 0, element - 1);
		printf("After Mergesort:");
 		for(i = 0; i < element; i++)
		{  		
			printf("\t%d", array[i]);
		}
		printf("\n");
		break;
		default:
		printf("You didn't enter the correct value!!!");
		break;
	}
}
void 
sort(int values[], int n)
{
	int k,size,size1;
	k=n;
	for (size1 = 0; size1 < n-1; size1++)
	{	
		for (size = 0; size < k-1; size++)
		{
        		if(values[size]>values[size+1])
			{	
				int temp;	
				temp=values[size];
				values[size]=values[size+1];
				values[size+1]=temp;
			}	
		}
		k--;
	}  
	printf("sorted values are:\n");
  	for (size1 = 0; size1 < n; size1++)
	{
		printf("\t%d",values[size1]);
	//return;
	}
	printf("\n");
}
void 
bubble(int values[], int n)
{

	int k,size,size1;
	int a;
	int temp;
	int g;
	a=0;
	g=0;
	//temp=values[a];
	k=n;
	for (size1 = 0; size1 < n; size1++)
	{	
		temp=values[a];
		for (size = a; size < n; size++)
		{
        		if(values[size]<values[size+1])
			{	
				if(values[size]<=temp)	
				{
					temp=values[size];
					g=size;
				}
			}	
		}
		values[g]=values[a];		
		values[a]=temp;		
		a++;
	}  
	printf("sorted values are:\n");
  	for (size1 = 0; size1 < n; size1++)
	{
		printf("\t%d",values[size1]);
	//return;
	}
	printf("\n");


}
void mergesort(int a[], int low, int high) {
 int i = 0;
 int length = high - low + 1;
 int pivot  = 0;
 int merge1 = 0;
 int merge2 = 0;
 int working[length];

 if(low == high)
  return;

 pivot  = (low + high) / 2;

 mergesort(a, low, pivot);
 mergesort(a, pivot + 1, high);
 
 for(i = 0; i < length; i++)
  working[i] = a[low + i];

 merge1 = 0;
 merge2 = pivot - low + 1;

 for(i = 0; i < length; i++) {
  if(merge2 <= high - low)
   if(merge1 <= pivot - low)
    if(working[merge1] > working[merge2])
     a[i + low] = working[merge2++];
    else
     a[i + low] = working[merge1++];
   else
    a[i + low] = working[merge2++];
  else
   a[i + low] = working[merge1++];
 }
}
