#include <stdio.h>
#include <stdlib.h>

int inversion(int *,int,int);
int merge(int *,int,int,int);

int inversion(int *A,int beg,int end)
{
    int mid,inv=0;
	if(beg<end)
	{
		mid = beg+(end-beg)/2;
		inv+=inversion(A,beg,mid)+inversion(A,mid+1,end);
		inv+=merge(A,beg,mid,end);	
	}
	return (inv);
}

int merge(int *A,int beg,int mid,int end)
{
	
	int i,j,k,total_inv=0;
    
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
    
	return (total_inv);

}


/* Driver program */

void main()
{
	int A[]={1,2,3,4,7,6,5};
	int size,i;
	size=sizeof(A)/sizeof(A[0]);
	printf("\nTotal Number of inversion = %d\n",inversion(A,0,size-1));
	for(i=0;i<size;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}