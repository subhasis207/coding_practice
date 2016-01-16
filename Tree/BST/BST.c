#include <stdio.h>
#include <stdlib.h>


typedef struct NodeType
{
	struct nodeType *left;
	int value;
	struct nodeType *right;

}Tree;

/* Functionality */
void createTree(Tree **)
void InorderTraversal(Tree *);
void PreorderTraversal(Tree *);
void PostorderTraversal(Tree *);
void LevelorderTraversal(Tree *);
void insertion(Tree **,int );
void deletion(Tree **,int );
int Height1(Tree *);
int Height2(Tree *) 
int internalNode(Tree *);
int leafNode(Tree *);
int totalNodes(Tree *);

/* Utility */
int max(int a,int b)

/*    0) Creating a new Tree   */
void createTree(Tree **root)
{
	*root=NULL;
}

/*  1.a) Inorder Traversal, Avg,Best & worst case T(n)=theta(n)  */
void InorderTraversal(Tree *root)
{
	while(root!=NULL)
	{
		InorderTraversal(root->left);
		printf("%d ",root->value);
		InorderTraversal(root->right);
	}
}

/*  1.b) Inorder Traversal Iterative Approach, Avg,Best & worst case T(n)=theta(n)  */
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


/*   2) Preorder Traversal, Avg, Best & worst case T()=theta(n) */
void PreorderTraversal(Tree *root)
{
	while(root!=NULL)
	{
		printf("%d ",root->value);
		PreorderTraversal(root->left);
		PreorderTraversal(root->right);
	}
}


/*    3) Postorder Traversal, Avg & Best case T(n)=theta(lg n);worst case T()=theta(n)  */
void PostorderTraversal(Tree *root)
{
	while(root!=NULL)		
	{
		PostorderTraversal(root->left);
		PostorderTraversal(root->right);
		printf("%d ",root->value);

	}	
}



/*     4) Level-order Traversal  */
void LevelorderTraversal(Tree *node)
{
	Queue *rear;
}


/*     5) Insertion into the Tree  */
void insertion(Tree **root,int info)
{
	
}



/*     6) Deletion fron the Tree  */
void deletion(Tree **root,int info)
{

}


/*     7.a) Finding the Height of the Tree, Best & Avg case T(n)=theta(lg n);worst case T(n)=theta(n) */
int Height1(Tree *root)
{	
	int value=0;
	if(root!=NULL)
	{
		if(root->left!=NULL)
			value=1+Height(root->left);
		if(root->right!=NULL)
			value=max(value,1+Height(root->right));
	}
	return(value);
}



/*     7.b) Finding the Height of the Tree, Best & Avg case T(n)=theta(lg n);worst case T(n)=theta(n) */
int Height2(Tree *node)
{
	int value=0,lDepth,rDepth;
	if(root!=NULL)
	{
		lDepth=Height2(root->left);
		rDepth=Height2(root->right);
		if(lDepth > rDepth)
			value=1+lDepth;
		else
			value=1+rDepth;			
	}
	return (value);
}



/*    Finding Maximum of two Number  */
int max(int a,int b)
{
	return(a>b?a:b);
}





/*     8) Finding the Number of Internal Nodes, Avg & Best & worst case T(n)=theta(n)  */
int internalNode(Tree *root)
{
	int value=0
	if(root!=NULL)
	{
		if(root->left && root->right !=NULL)
		{
			value=1+internalNode(root->left)+internalNode(root->right);
		}
	}
	return (value);
} 


/*     9) Finding the number of Leaf Nodes, */
int leafNode(Tree *root)
{
	int value=0;
	if(root!=NULL)
	{	
		if(root->left==NULL && root->right==NULL)
			value=1;
		else 
			value=leafNode(root->left)+leafNode(root->right);

	}
	return (value);
}

