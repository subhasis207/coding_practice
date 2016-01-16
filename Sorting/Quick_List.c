#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int info;
    struct nodetype *next; 
}node;

node *getTail(node *);

void traverseList(node *);

void createList(node **);

void insertAtBeginning(node **, int);

void quicksort(node **);

node *quickSortRecur(node *,node *);

node *partition(node *,node *,node **,node **);


/*1. Get the last node  */
node *getTail(node *head)
{
    node *ptr;
    for(ptr=head->next;ptr!=NULL && head!=NULL;head=head->next,ptr=ptr->next);
    return head;

}


/*2.  Forward Traversal of the Linked List  */
void traverseList(node *head)
{
	node *ptr;
    printf("\n%u-->",head);
    if(head !=NULL)
    {
	    for(ptr=head->next;ptr!=NULL && head!=NULL;head=head->next,ptr=ptr->next)
	        printf("|%d| %u |-->",head->info,head->next);
        printf("|%d|",head->info);
    }
    else
        printf("NULL");
}


/*3. Creating an empty Linked List  */
void createList(node **head)
{
   *head=NULL;
} 

*4. Insert a node at the beginning */
void insertAtBeginning(node **head, int value)
{
    node *ptr;
    ptr=(node *)malloc(sizeof(node));
	ptr->info=value;
    if(*head==NULL)
        ptr->next=NULL;
    else
	    ptr->next=*head;
	*head=ptr;	
}



void quicksort(node **head)
{
	*head = quickSortRecur(*head,getTail(*head) );
}


node *quickSortRecur(node *head, node *end)
{
	node *newHead,*newEnd,*pivot,*temp ;
		
	if(head !=NULL || head == end)
		return head;


	newHead=newEnd=NULL;
	pivot = partition(head,end,&newHead,&newEnd);

	if(newHead!=pivot)
	{
		temp=newHead;
		while(temp->next != pivot)
		{
			temp=temp->next;
		}		
		temp->next=NULL;
		newHead=quickSortRecur(newHead,temp);
		
		temp=getTail(newHead);
		temp->next=pivot;
		
	}

	pivot->next=quickSortRecur(pivot->next,newEnd);
	
	return newHead;		
	

}


node *partition(node *head,node *end, node **newHead,node **newEnd)'
{
	node *prevN,*currN,*tail,*pivot,*temp;
	prevN=NULL;
	currN=head;
	pivot=end;
	tail=pivot;
	while (currN != pivot)
	{
		if(currN->next<pivot->next)
		{	
			if((*newHead) ==NULL)
			  (*newHead)=currN;
			
			prevN=currN;
			currN=currN->next;
		}
		else
		{
			if(prevN)
			  prevN->next=currN->next;
			
			temp=currN->next;
			currN->next=NULL;
			tail->next=currN;
			tail=currN;
			currN=temp;		

		}
	}		
	
	if((*newHead)==NULL)
	    (*newHead)=pivot;
	
	(*newEnd)=tail;

	return pivot;
}



int main()
{  
    	
	node *head;	

	createList(&head);

	insertAtBeginning(&head,4);

	insertAtBeginning(&head,3);

	insertAtBeginning(&head,2);

	insertAtBeginning(&head,5);

	insertAtBeginning(&head,6);

	insertAtBeginning(&head,10);
 
    printf("Linked List before sorting \n");
    traverseList(head);
 
    quicksort(&head);
 
    printf("Linked List after sorting \n");
    traverseList(head);
 
    return 0;
}