#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*   --------Min-Max Problem--------
 

   Number of Comparisons is of the order
         
             3[n/2]

*/

void min_max(int *,int,int *,int *);
static int count=0;

void main()
{
    int *min,*max,n,a=0;
    int A[6]={6,1,5,2,4,3};
    n=sizeof(A)/sizeof(A[0]);
    min=&a;
    max=&a;
	min_max(A,n,min,max);
	printf("\nSmallest =%d",*min);
	printf("\nLargest  =%d",*max);

}

void min_max(int *A,int n,int *pmin,int *pmax)
{
	int i,nby2,lmin,lmax;
    int *temp;
	printf("\n--------- The Sub-arrays---------\n");
    temp=A;
    for(i=0;i<n;i++,A++)
	{
		printf("%d ",*A);				
	}
    A=temp;
	if(n==1)
	  {
          *pmin=*pmax=A[0];
          printf("\n%d %d",*pmin,*pmax);
	  }
	else if(n==2)
	{
		if(A[0]<A[1])
		 {
			*pmin=A[0];
			*pmax=A[1];
			count++;	
		 }
		else
		 {
			*pmin=A[1];
			*pmax=A[0];
			count++;
		 }
	}
	else if(n>0)
	{
		nby2=n/2;
        min_max(A,nby2,pmin,pmax);
        printf("\nHEllloooo!!!!\n");
		min_max(A+nby2,n-nby2,&lmin,&lmax);
		if(lmin<*pmin)
		  {
			pmin=&lmin;
			count++;
		  }
		if(lmax>*pmax)
		  {
			pmax=&lmax;
			count++;
		  }
	}
}

