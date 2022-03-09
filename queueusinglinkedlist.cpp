#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct queue 
{
	int data;
	struct queue *next;
};
 struct queue *H=NULL;
void pushelement(int val)
{
	struct queue *ptr,*t;
	ptr=(struct queue *)malloc(sizeof(struct queue));
	ptr->data=val;
	ptr->next=NULL;
	if(H==NULL)
	{
		H=ptr;
	}
	else
	{
		t=H;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=ptr;		
	}
}
void popelement()
{
	struct queue *t;
	if(H==NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		t=H;
		H=H->next;
		printf("Popped element is %d\n",t->data);
		free(t);
	}
}
void display(struct queue *H)
{
	struct queue *t;
	if(H==NULL)
	{
		printf("Queue is empty nothing to display\n");
	}
	else
	{
	t=H;
	printf("Elements of queue is:");
    do
	{
	printf("%d ",t->data);
	t=t->next;
	}
	while(t->next!=NULL);
	printf("%d",t->data);
	printf("\n");
	}
}
int main()
{
	int ch,ele;
	while(1)
	{
		printf("press 1 to insert element into queue\n");
		printf("press 2 to delete element from queue\n");
		printf("press 3 to display elements of queue\n");
		printf("press 4 to quit from program\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	{
	printf("Enter the element to insert\n");
	scanf("%d",&ele);
	pushelement(ele);
	break;
	}
	case 2:
	{
	popelement();
	break;
	}
	case 3:
	{
	display(H);
	break;
	}
	case 4:
	{
	exit(0);
	}
	default:
	{
	printf("invalid input\n");
	}
	}
	}
	
}