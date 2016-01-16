#include <stdio.h>
#include <stdlib.h>

/*-----Catalan Number Using Recursion-----
  ---Cn+1=add(i=0 to n)(Ci*Cn-i)
  ---Time Complexity: T(n)=Summation(i=0 to n-1)(T(i)*T(n-1-i))------*/



unsigned long int catalan(unsigned int );

void main ()
{
	unsigned int n;
	printf("\nFor Nth Catalan Number, Enter the value of N: ");
	scanf("%u",&n);
	printf("The Nth Catalan Number = %u",catalan(n));
}

unsigned long int catalan(unsigned int n)
{
	int i,rev=0;

	for(i=1;i<n;i++)
	{
		rev+=(catalan(i)*catalan(n-1-i));
	}

	return rev;
}