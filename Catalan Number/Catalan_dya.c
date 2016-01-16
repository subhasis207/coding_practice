#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----Catalan Number Using Dynamic Programming-----*/

void catalan(unsigned long int *,unsigned int);

void main ()
{
    unsigned int n=5;
    unsigned long int Catalan[6]={0,0,0,0,0,0};
	/*printf("\nFor Nth Catalan Number, Enter the value of N: ");
	scanf("%u",&n);*/
    catalan(Catalan,n);
	printf("\nThe Nth Catalan Number = %lu",Catalan[5]);
}





void catalan(unsigned long int *Catalan,unsigned int n)
{
	int i,j;
    Catalan[0]=1;
    Catalan[1]=1;
    for(i=2;i<=n;i++)
    {
        for(j=0;j<i;j++)
         {
             Catalan[i]+=(Catalan[j]*Catalan[i-j-1]);
         }
    }
}