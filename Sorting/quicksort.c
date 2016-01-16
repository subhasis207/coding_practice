#include <stdio.h>
#include <string.h>
void printArray(int *,int );
void quickSort(int *,int,int );
int partition(int *,int,int); 


int main(){

    int A[6]={6,5,4,3,2,1};
	quickSort(A,0,5);
	printArray(A,6);
	return 0;
}


void printArray(int *A,int n){
	
	int i;
	printf("The sorted array ::\n\n");
	for(i=0;i<n-1;i++){
		printf("%d-->",A[i]);
	}
    printf("%d",A[i]);
}


void quickSort(int *A,int beg,int end){
    
	int q;
	if(beg<end){
		q=partition(A,beg,end);
		quickSort(A,beg,q-1);
		quickSort(A,q+1,end);
	}

}

int partition(int *A,int p,int r){

    int i,j,pivot,temp;
	pivot=A[r];
	i=p-1;
	for(j=p;j<r;j++){
		if(A[j]<pivot){
			i++;
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	temp=A[i+1];
	A[i+1]=A[r];
	A[r]=temp;
	return (i+1);
}


