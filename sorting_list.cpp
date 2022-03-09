#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insertnodeF();
void sort_List();
void displaylist();
struct node 
{
	int data;
	struct node *next;
};
struct node *H=NULL;
struct node *createnode()
{
	struct node *arr;
	arr=(struct node*)malloc(sizeof(struct node));
	return arr;
}
void count_List_ele()
{
	struct node *t;
	int c=0;
	if(H==NULL)
	{
		printf("List is empty");
	}
	else
	{
		t=H;
		while(t!=NULL)
		{
			t=t->next;
			c++;
		}
		printf("The number of nodes in the list is %d\n",c);
	}
}
void displaylist()
{
	struct node *t;
	if(H==NULL)
	{
	printf("List is empty nothing to display\n");
	}
	else
	{
	t=H;
	printf("Elements of list is:");
	while(t!=NULL)
	{
	printf("%d ",t->data);
    t=t->next;	
	}
	printf("\n");
	}
}
void sort_List()
{
	struct node *t,*i,*j;
	int temp;
	if(H==NULL)
	{
	printf("List is empty nothing to sort\n");
	}
	else
	{
		t=H;
		for(i=t;i!=NULL;i=i->next)
		{
		for(j=i->next;j!=NULL;j=j->next)
		{
		  if(i->data>j->data)
		 {
		  temp=i->data;
		  i->data=j->data;
		  j->data=temp;	
		 }		
		}
	}
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
	n->next=NULL;
	if(H==NULL)
    {
	H=n;
	}	
	else
	{
		n->next=H;
		H=n;
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("Press 1 to add elements to list\n");
		printf("Press 2 to sort the list elements\n");
		printf("Press 3 to display the list\n");
		printf("Press 4 to count number of nodes\n");
		printf("Press 5 to exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
			insertnodeF();
			break;
			}
			case 2:
			{
			sort_List();
			break;
			}
			case 3:
			{
			displaylist();
			break;
			}
			case 4:
			{
			count_List_ele();
			break;
			}
			case 5:
			{
			exit(0);
			}
		}
	}
}