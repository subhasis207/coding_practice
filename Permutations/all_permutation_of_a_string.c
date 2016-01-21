#include <stdio.h>
#include <string.h>

void permute(char *,int ,int );
void swap(char *,char *);
static int count=0;

main()
{
	char A[]="ABC";
	permute(A,0,2);
}

void swap(char *b,char *c)
{
	char temp;
	printf("\nIn swap block.....\n");
	printf("\nValue to be swapped === %c %c\n",*b,*c);
	temp=*c;
	*c=*b;
	*b=temp;
}

void permute(char *A,int beg,int end)
{
	int i;
	if(beg==end)
	{
		printf("\n%s ",A);
		printf("\n%d ",++count);
	}
	else
	{
		for(i=beg;i<=end;i++)
		{
			swap(A+beg,A+i);
			printf("\nHO HO....\n");
			permute(A,beg+1,end);
			printf("\nHA HAAAAA.........\n");
			swap(A+beg,A+i);
		}
	}
}
