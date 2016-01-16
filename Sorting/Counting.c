#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countingSort(int *,int *,int ,int );
int maximum(int *,int );

void main()
{
    int A[]={0,1,5,2,2,4,4,5,7,8,9};
	int i,n,k;
	n=sizeof(A)/sizeof(int);
	int B[n];
    for(i=0;i<n;i++)
    {
		B[i]=0;
	}
	k=maximum(A,n);
	countingSort(A,B,k,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",B[i]);
	} 
	printf("\n");
}

int maximum(int *A,int n)
{
	int i,max;
	max=A[0];
	for(i=1;i<n;i++)
	{
		if(A[i]>max)
		max=A[i];
	}
	return max;
	
}


void countingSort(int *A,int *B,int size,int sizeA)
{
	int i,j,k;
	int C[size+1];

	for(i=0;i<=size;i++)
		C[i]=0;
	for(j=0;j<sizeA;j++)
		C[A[j]]++;
	for(i=1;i<=size;i++)
		C[i]+=C[i-1];
	for(j=sizeA-1;j>=0;j--)
	{
		k=C[A[j]];
        B[k-1]=A[j];
		C[A[j]]--;
	}
	
}