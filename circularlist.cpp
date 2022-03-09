#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node *createnode();
struct node *createlist(struct node *last);
struct node *display(struct node *last);
struct node *addtobeg(struct node *last,int value);
struct node *addtolast(struct node *last,int value);
struct node *addtoempty(struct node *last,int value);
struct node *addtorandom(struct node *last,int value,int item);
struct node *deletee(struct node *last,int item);
struct node
{
	int data;
	struct node *next;
};
struct node *addtoempty(struct node *last,int value)
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	n->data=value;
	last=n;
	n->next=last;
	return(last);	
}
struct node *addtobeg(struct node *last,int value)
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	n->data=value;
	n->next=last->next;
	last->next=n;
	return(last);	
}
struct node *addtolast(struct node *last,int value)
{
	struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
	n->data=value;
	n->next=last->next;
	last->next=n;
	last=n;
	return(last);	
}
struct node *addtorandom(struct node *last,int value,int item)
{
	struct node *n,*t;
	n=(struct node *)malloc(sizeof(struct node));
	n->data=value;
	t=last->next;
	do
	{
		if(t->data==item)
		{
		   n->next=t->next;
		   t->next=n;	
		if(t==last)
		{
			last=n;
		}
     	}
		t=t->next;
	}
while(t!=last->next);
return(last);	
}
struct node *deletee(struct node *last,int item)
{
	struct node *n,*t;
	t=last->next;
	if(last==NULL)
	{
		printf("List is empty nothing to delete\n\n");
		return(last); 
	}
   if(last==last->next && last->data==item)
   {
   	n=last->next;
   	last=NULL;
   	free(n);
   	return(last);
   }
   if(last->next->data==item)
   {
   	 n=last->next;
   	 last->next=n->next;
   	 free(n);
   	 return(last);
   }
    do
   {
   	if(t->next->data==item)
   	{
   		n=t->next;
   		t->next=n->next;
   		free(n);
   		return(last);  		
	   }
	   	t=t->next;
   }
   while(t!=last->next);  
   if(last->data==item)
   {
   	  n=last;
   	  t->next=last->next;
   	  last=t;
   	  free(n);
   	  return(last);   	  
   }
   printf("Element not found\n\n");
   return(last);	
}
struct node *display(struct node *last)
{
	struct node *t;
	if(last==NULL)
	{
		printf("List is empty nothing to delete\n\n");
		return(last);
	}
	t=last->next;
	printf("The Elements of list is ");
	do
	{
		printf("%d ",t->data);
		t=t->next;
	}
	while(t!=last->next);
	printf("\n\n");
	return(last);
}
struct node *createlist(struct node *last)
{
	struct node *t;
	int i,n,ele;
	printf("Enter the limit of list to add elements\n");
	scanf("%d",&n);
	printf("Enter the first element of list\n");
	scanf("%d",&ele);
	last=addtoempty(last,ele);
	printf("Enter rest %d elements ",n-1);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&ele);
		last=addtolast(last,ele);
	}
	return(last);
}
int main()
{
	struct node *last=NULL;
	int choice,val,item;
    while(1)
    {
    	printf("Press 1 to create list\n");
    	printf("Press 2 to add element to begging\n");
    	printf("Press 3 to add element to last\n");
    	printf("Press 4 to add element to random place\n");
    	printf("Press 5 to add element to empty list if not created list yet\n");
    	printf("Press 6 to delete element from the list\n");
    	printf("Press 7 to display list\n");
    	printf("Press 8 to quit out the program\n\n");
    	printf("Enter your choice\n");
    	scanf("%d",&choice);
    	switch(choice)
		{
		case 1:
		{
		last=createlist(last);
		break;
		}
		case 2:
     	{
     	printf("Enter the value to add\n");
     	scanf("%d",&val);
        last=addtobeg(last,val);
		break;
		}
		case 3:
		{
		printf("Enter the value to add\n");
     	scanf("%d",&val);
     	last=addtolast(last,val);
     	break;
		}
		case 4:
		{
		printf("Enter the value to add\n");
     	scanf("%d",&val);	
     	printf("Enter the item after which to add element\n");
     	scanf("%d",&item);
     	last=addtorandom(last,val,item);
     	break;
		}
		case 5:
		{
		printf("Enter the value to add\n");
     	scanf("%d",&val);
		last=addtoempty(last,val);
		break;	
		}
		case 6:
		{
		printf("Enter the value to delete\n");
     	scanf("%d",&val);
     	last=deletee(last,val);
     	break;
		}
		case 7:
		{
		last=display(last);
	    break;
		}
		case 8:
		{
		exit(0);
		}
		default:
		{
		printf("Invalid input please try again later\n\n");
		break;
	    }
		}    
	}
	return 0;
}