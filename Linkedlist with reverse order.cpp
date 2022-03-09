#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insertnodeL();
void insertnodeF();
int deletenode();
void displaylist();
void Reverse();
struct node *display();
struct node 
{
	int data;
	struct node *link;
};
struct node *START=NULL;
struct node *createnode()
{
	struct node *arr;
	arr=(struct node*)malloc(sizeof(struct node));
	return arr;
}
void Reverse()
{
	struct node *t,*n;
	if(START==NULL)
	{
		printf("List is empty\n");
	}
	else
	{		
	while(START!=NULL)
	{
	t=START;
	START=START->link;
	t->link=n;
	n=t;
	}
	START=n;      		
	}
	//return(START->link);
}
void insertnodeL()
{
	int val;
	struct node *n;
	printf("Enter the value to insert\n");
	scanf("%d",&val);
	n=createnode();
	n->data=val;
	n->link=NULL;
	if(START==NULL)
    {
	START=n;
	}	
	else
	{
	struct node *temp;
	temp=START;
	while(temp->link!=NULL)
	{
	temp=temp->link;
    } 
	temp->link=n;	
}
}
void insertnodeF()
{
	int val;
	struct node *n;
	printf("Enter the value to insert\n");
	scanf("%d",&val);
	n=createnode();
	n->data=val;
	n->link=NULL;
	if(START==NULL)
    {
	START=n;
	}	
	else
	{
		n->link=START;
		START=n;
	}
}
void insertnodeR()
{
	int ele,val;
	struct node *ptr,*t;
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("Enter the element to insert\n");
	scanf("%d",&ele);
	printf("Enter the element after which to add element\n");
	scanf("%d",&val);
	ptr->data=ele;
	ptr->link=NULL;
	t=START;
	while(t->data!=val && t->link!=NULL)
	{
		t=t->link;
	}
	if(t->data==val)
	{
		ptr->link=t->link;
		t->link=ptr;
	}
	else
	{
		printf("Element not found to insert into list\n");
	}	
}
int deletenode()
{
	struct node *n;
	if(START==NULL)
	{
		printf("List is empty nothing to delete\n");
		return 0;
	}
	else
	{
	n=START;
	START=START->link;
	printf("The deleted element from the list is %d\n\n",n->data);
	free(n);
    }
}
void deleterandom()
{
	struct node *n,*t;
	int ele;
	printf("Enter the value to delete\n");
	scanf("%d",&ele);
	if(START==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
	  n=START;
	  while(n->link->data!=ele)
	  {
	  	n=n->link;
	  }
	  t=n->link;
	  n->link=t->link;
	  printf("Popped element is %d",t->data);
	  free(t);	  
	}
}
void displaylist()
{
	struct node *temp;
	if(START==NULL)
	{
		printf("List is empty nothing to display\n\n");
	}
	else
	{
		temp=START;
		printf("The elements of list is ");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}
		printf("\n\n");
	}
}
int main()
{
	int choice;
	///struct node *x;
	while(1)
	{
	printf("Press 1 to insert element into list at last\n");
	printf("Press 2 to insert element into list at beggning\n");
	printf("Press 3 to insert element into list at random\n");
	printf("Press 4 to delete element from list\n");
	printf("Press 5 to display list elements\n");
	printf("Prtess 6 to printf list in reverse order\n");
	printf("Press 7 to delete insert element into list at random\n");
	printf("Press 8 quit from program\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
     	insertnodeL();
	    break;
        }
        case 2:
       	{
       	insertnodeF();
        break;		
		}
		case 3:
		{
		insertnodeR();
		break;
	    }
        case 4:
       	{
        deletenode();
		 break;	
		}
		case 5:
		{
		displaylist();
		break;
		}	
	   	case 6:
	   	{
	   	Reverse();
	   	displaylist();
	  	break;
	   	}
	   	 case 7:
	   	{
	   	deleterandom();
	   	break;
	   	}
	   	case 8:
		{
		exit(0);
	    }	   
   }
}
return 0;
}
