#include <stdio.h>
#include <string.h>
void subsets(int *,int ,int ,int *,int ,int);
void printCombination(int *,int ,int );

void printCombination(int *A,int n ,int r)
{
	int data[r];
	subsets(A,n,0,data,r,0);
}

void subsets(int *A,int n,int i,int *data,int r,int index)
{
	int j;
	if (index==r)
	{
		for(j=0;j<r;j++)
			printf("%d ",data[j]);
		printf("n");
		return;
	}
	if (i>=n)
	{
		return;
	}

	data[index]=A[i];
	subsets(A,n,i+1,data,r,index+1);
	// printf("o ya ya ya...n");
	subsets(A,n,i+1,data,r,index);

}

int main()
{
	int arr[] = {1, 2, 3,4};
	int i;
	int n = sizeof(arr)/sizeof(arr[0]);
	for(i=1;i<=n;i++)
	{
		printf("Subsets of size %d ...n",i);
		printCombination(arr, n, i);
	}

	return 0;
}
