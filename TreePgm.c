#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//void display(struct node *T);
//void Binary_search_Traverse(struct node **T,int val[],int n);
//void Inorder_Traverse(struct node *T);
//void Preorder_Traverse(struct node *T);
//void Postorder_Traverse(struct node *T);

struct node
{
	struct node *left;
	struct node *right;
	int info; 
};

struct node *create_node(int val)
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	n->info=val;
	n->left=NULL;
	n->right=NULL;
	return(n);
}
void Inorder_Traverse(struct node *T)
{   
	if(T!=NULL)
	{
	  Inorder_Traverse(T->left);
	  printf("%d ",(T->info));	
	  Inorder_Traverse(T->right);
	}
}

void Preorder_Traverse(struct node *T)
{    
   	if(T!=NULL)
	{
		printf("%d ",(T->info));
		Preorder_Traverse(T->left);
		Preorder_Traverse(T->right);
	}
}

void Postorder_Traverse(struct node *T)
{ 
	if(T!=NULL)
	{
		Postorder_Traverse(T->left);
		Postorder_Traverse(T->right);
		printf("%d ",(T->info));
	}
}

int IS_BST(struct node *T)
{
	struct node *prev=NULL;
	if(T!=NULL)
	{
		if((IS_BST(T->left)))
		return 0;
		if(prev!=NULL && T->info<=prev->info)
		return 0;
		prev=T;
		return(IS_BST(T->right));
	}
	else
	{
		return 1;
	}
}

struct node *Insertion_node(struct node *T,int val)
{
  int i;
  struct node *ptr,*loc1,*loc2;
  ptr=create_node(val);
  
  if((T)==NULL)
  {
  	(T)=ptr;
  }
  else
  {
  	loc1=NULL;
  	loc2=T;
  	
  	while(loc2!=NULL)
  	{
  	 loc1=loc2;
	 if(val>loc2->info)
	   loc2=loc2->right;
	 else
	 {
	   if(val<loc2->info)
	     loc2=loc2->left;
	   else
	     {
	     printf("No insertion allowed,Due to duplicasy of values\n");
	     return(T);
	     }
	 }
    }
    if(val>loc1->info)
      loc1->right=ptr;
    else
	  loc1->left=ptr;  	
  }
  return(T);
} 

int Ele_Search(struct node *T,int val)
{
	struct node *t;
	if(T==NULL)
	{
	   printf("Element not found in Tree as the Tree is empty\n");
	   return(0);
	}
	else
	{
		t=T;
		while(t!=NULL)
		{
			if(t->info==val)
			  return(t->info);
			else if(t->info<val)
			  t=t->right;
			else if(t->info>val)
			  t=t->left;
		    else
		      return(0);
		}
	}
}
 	                                                                   

int main()
{
	int i,choice;
	struct node *T=NULL;
	int n,val;
	
	while(1)
	{
	printf("\nPress 1 to sort the elements in Inorder form");
	printf("\nPress 2 to sort the elements in Preorder form");
	printf("\nPress 3 to sort the elements in Postorder form");
	printf("\nPress 4 to Insert of node in BST form");
	printf("\nPress 5 to check weather the tree is a BST or not");
	printf("\nPress 6 to search the element in the Tree");
	printf("\nPress 7 to exit from the program\n");
	printf("\nEnter your choice\n");
	scanf("%d",&choice);

		switch(choice)
		{
			case 1:
			{
				Inorder_Traverse(T);
				break;
			}
			case 2:
		    {
		    	Preorder_Traverse(T);
			break;
			}
			case 3:
			{
				Postorder_Traverse(T);
			break;
			}
			case 4:
			{
				printf("Enter the value to insert\n");
				scanf("%d",&val);
			    T=Insertion_node(T,val);
			break;
			}
			case 5:
			{
			    if(IS_BST(T))
	           {
		        printf("Tree is BST\n");
               }
	           else
	           {
		        printf("Tree is not a BST\n");
	           }
			   break;	
		    }
		    case 6:
		    {
		    	printf("Enter the element to search in the tree\n");
		    	scanf("%d",&val);
		    	n=Ele_Search(T,val);
		    	if(n)
		    	printf("Element Searched\n",val);
		    	else
		    	printf("Element not searched\n",val);
		    	break;
			}
			case 7:
			{
				exit(0);
		 	}	
			default:
			{
			    printf("Invalid Input\n");
			    break;
		    }		
		}
	}
}