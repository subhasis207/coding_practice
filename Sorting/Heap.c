#include <stdio.h>
#include <string.h>
void printArray(int *,int );
void maxHeapify(int *,int ,int);
int parent(int *,int);
int leftChild(int *,int);
int rightChild(int *,int); 
void buildMaxHeap(int *,int ); 
void heapSort(int *,int );


int main(){

    int A[6]={1,2,6,89,4,92};
    heapSort(A,6);
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

int parent(int *A,int i){
	
	return (i/2);
}

int leftChild(int *A,int i){

	return (2*i);
}

int rightChild(int *A,int i){
	 	
	return ((2*i)+1);
}



void maxHeapify(int *A,int heapSize,int i){

	int l,r,largest,temp;
	l=leftChild(A,i);
	r=rightChild(A,i);
	
	if(l<heapSize && A[l]>A[i])
		largest=l;
	else 
		largest=i;
	if(r<heapSize && A[r]>A[largest])
		largest=r;
	if(largest != i){
		
		temp= A[largest];
		A[largest]= A[i];
		A[i]=temp;
		maxHeapify(A,heapSize,largest);
	}
}

void buildMaxHeap(int *A,int aLength){

	int i;
	for(i=(aLength/2);i>=0;i--){
		maxHeapify(A,aLength,i);
	}
}

void heapSort(int *A,int aLength){
    
    int i,temp,heapSize;
    heapSize=aLength;
    buildMaxHeap(A,aLength);
    for(i=aLength-1;i>=0;i--){
        temp=A[i];
        A[i]=A[0];
        A[0]=temp;
        heapSize--;
        maxHeapify(A,heapSize,0);
    }
}
