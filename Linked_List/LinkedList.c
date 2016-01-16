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

void insertAtEnd(node **, int);

void insertInBetween(node **,int,int);

void reverseTraversal(node *);

void reverseList(node **);

void deleteEnd(node **);

void deleteBeginning(node **);

void deleteAfter(node **,int);

void deleteList(node **);

/*1. Get the last node  */
node *getTail(node *head)
{
    node *ptr;
    for(ptr=head->next;ptr!=NULL && head!=NULL;head=head->next,ptr=ptr->next);
    return head;

}
/*2 Creating an empty Linked List  */
void createList(node **head)
{
   *head=NULL;
} 

/*3 Insert a node at the end of the list */
void insertAtEnd(node **head,int value)
{
    node *ptr,*loc;
    ptr=(node *)malloc(sizeof(node));
    //printf("\n%u-->",ptr);
    ptr->info=value;
    ptr->next=NULL;
    if(*head==NULL)
       *head=ptr;
    else
    {
       loc=getTail(*head);
       loc->next=ptr;
    }
}

/*4 Insert a node at the beginning */
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

/*5  Insert a node after some node  */
void insertInBetween(node **head,int value,int after)
{
    node *loc,*ptr,*pre;
    ptr=(node *)malloc(sizeof(node));
    ptr->info=value;
    printf("##%d ",(*head)->next->info);
    for(pre=*head,loc=pre->next;pre->info!=after && loc!=NULL;pre=pre->next,loc=loc->next);
        if(loc!=NULL)
        {
            ptr->next=loc;
            pre->next=ptr;
        }
        else
        {
            printf("The node not found !!!");
        }
}

/*6  Forward Traversal of the Linked List  */
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

/*7  Reverse Traversal of the List */
void reverseTraversal(node *head)
{
    if(head!=NULL)
        {
            reverseTraversal(head->next);
            printf("|%d|   ",head->info);
        }
}


/*8 List Reversing */

void reverseList(node **head)
{
    node *preNode,*currNode,*nextNode;
    preNode=NULL;
    currNode=*head;
    nextNode=currNode->next;
    currNode->next=NULL;
    while(nextNode!=NULL)
    {
        preNode=currNode;
        currNode=nextNode;
        nextNode=currNode->next;
        currNode->next=preNode;
    }
    *head=currNode;
        
}

/*9 Deletion of node from the end */

void deleteEnd(node **head)

{

    node *prev,*loc,*nextN;

    prev=NULL;

    loc=*head;

    if(*head ==NULL)

        return;

    else if((*head)->next==NULL)

        {

            *head=NULL;

        }

    else

    {

        nextN=loc->next;

        while(nextN!=NULL)

        {

            prev=loc;

            loc=nextN;

            nextN=loc->next;

        }

        prev->next=NULL;

    }

    free(loc);

}




/*10 Delete from the Beginning*/

void deleteBeginning(node **head)

{

    node *ptr;

    if(*head == NULL)

        return;

    else

    {

        ptr=*head;

        *head=ptr->next;

        free(ptr);

    }

}




/*11 Delete After a certain node */

void deleteAfter(node **head,int after)

{

    node *prev,*loc;

    prev=NULL;

    loc=*head;

    if(*head ==NULL)

        return;
    
    else
    
	{

           while(loc->next!=NULL)
        
		{

            
            prev=loc;

            		loc=loc->next;
   
            		if(prev->info==after)
                
			{

                    		prev->next=loc->next;

                    		loc->next=NULL;

                    		free(loc);

                    		return;

                	}

                
}

       }

}




/*12 Delete the entire list */

void deleteList(node **head)

{

    
    node *currN,*nextN;

    if(*head==NULL)

        return;

    while((*head) != NULL)
    
	{


	        currN=*head;

        	nextN=currN->next;

      		currN->next=NULL;

        	*head=nextN;

        	free(currN);

        
}
    
    

}








/*  Driver Program  */

void main()

{

	node *head,*tail;

	createList(&head);

	insertAtBeginning(&head,4);

	insertAtBeginning(&head,3);

	insertAtBeginning(&head,2);

	insertAtBeginning(&head,5);

	insertAtBeginning(&head,6);

	insertAtBeginning(&head,10);

	insertAtEnd(&head,1);

    insertInBetween(&head,9,2);

    traverseList(head);

    printf("\n");

    reverseTraversal(head);

    reverseList(&head);

    traverseList(head);

    deleteEnd(&head);

    traverseList(head);

    deleteBeginning(&head);

    traverseList(head);

    deleteAfter(&head,2);

    traverseList(head);

    deleteList(&head);

    traverseList(head);

//	tail= getTail(head);

//	printf("\nTail= %d",tail->info);

}
