#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *,int);
void printArray(int *,int);


void insertionSort(int *A,int size)
{
    int i,j,key;
	for(i=1;i<size;i++)
	{
		key=A[i];
		for(j=i-1;j>=0 && A[j]>key;j--)
		{
			A[j+1]=A[j];
		}
	    A[j+1]=key;
	}

}

void printArray(int *A,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",A[i]);	
	}
	printf("\n");
}

void main()
{
	int A[]={8,4,1,3,10.2,82,100,23};
	int size=sizeof(A)/sizeof(A[0]);
	printArray(A,size);
	insertionSort(A,size);
	printArray(A,size);

}