
#include<stdio.h>
#include<stdlib.h>
 
/*  Tranforrmation of a BST into a Sum Tree   
    Such that every node of the BST is to be 
    replaced with the sum of nodes greater than 
    that node
*/


typedef struct nodeType 
{
    struct nodeType *left;
	int info;
	struct nodeType *right;
 
}BST;


void transformUtil(BST *root,int  *sum)
{
	if(root==NULL)
		return ;
	transformUtil(root->right,sum);
	*sum+=root->info;
    root->info=*sum-root->info;
	transformUtil(root->left,sum);
	

}



void transformTree(BST *root)
{
	int sum=0;
	transformUtil(root,&sum);
}



BST *newNode(int value)
{
	BST *temp;
	temp=(BST *)malloc(sizeof(BST));
	temp->info=value;
	temp->left=NULL;
    temp->right=NULL;
	return (temp);
}



void traversalIterative(BST *root)
{
	BST *curr,*pre;
    if(root==NULL)
    return;
    
	curr=root;
	while(curr!=NULL)
	{
		if(curr->left == NULL)
		{
			printf("%d ",curr->info);
			curr=curr->right;
		}
		else
		{
			pre=curr->left;
			while(pre->right!=NULL && pre->right!=curr)
				pre=pre->right;
			if(pre->right==NULL)	
			{
				pre->right=curr;
				curr=curr->left;		
			}
			else
			{
				pre->right=NULL;
				printf("%d ",curr->info);
				curr=curr->right;
			}
		}
	}
    printf("\n");
}


void main()
{
	BST *root;
	root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->right->right = newNode(8);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);
	traversalIterative(root);
	transformTree(root);
	traversalIterative(root);

}