#include <stdio.h>

#include <string.h>

#include <stdlib.h>


void mergesort(int *,int,int);

void merge(int *,int,int,int);

int total_inv=0;

void main()

{

    int *A;

    int beg=0,end,mid,i,size,net_inver;

    printf("\nEnter the size of the array:");

    scanf("%d",&size);

    end=size-1;

    A=(int *)calloc(size,sizeof(int));

    printf("\nEnter %d element into the array::\n");

    for(i=beg;i<=end;i++)

    {

        scanf("%d",&A[i]);
    }
    
    printf("\nThe array before sorting:\n ");

    for(i=beg;i<=end;i++)

    {

        printf("%d ",A[i]);
    }

    mid=(beg+end)/2;

   mergesort(A,beg,end);
//	printf("\n######In Main Block######\n");

	printf("\nThe array after sorting:\n ");

    for(i=beg;i<=end;i++)

	{

		printf("%d ",A[i]);
	
    }
     net_inver=total_inv;
    printf("\nNumber of inversions = %d",net_inver);

}




/*Merge Sort */


void mergesort(int *A,int beg,int end)

{

	int i,mid;
    
	if(beg<end)
    {

		mid=(beg+end)/2;

		mergesort(A,beg,mid);
        
		mergesort(A,mid+1,end);
        
		merge(A,beg,mid,end);
    }
  
} 






/*Merging the sub-array */



void merge(int *A,int beg,int mid,int end)

{

	int i,j,k;
    
    int n1,n2;

	n1=mid-beg+1;

	n2=end-mid;

	int B[n1],C[n2];

	for(i=0;i<n1;i++)

		B[i]=A[beg+i];

	for(i=0;i<n2;i++)

		C[i]=A[mid+1+i];

    for(i=beg,j=0,k=0;j<n1 && k<n2;i++)

	{

		if(B[j]<=C[k])

		 {

			A[i]=B[j];

			j++;

		 }

		else
 
		 {

			A[i]=C[k];

			k++;
            
            total_inv+=(n1-j);  /*since the left & right array is sorted,so if B[j]>C[k],then all A[i+1],A[i+2],..A[mid] is also be greater*/
	
         }


	}

    
    while(k<n2)

     	{

         	A[i]=C[k];

         	i++;

         	k++;

        }

    
    while(j<n1)

        {

                A[i]=B[j];
 
               i++;

                j++;
                
        }
    
 }