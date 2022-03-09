#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void display(struct queue *q);
void queuepop(struct queue *q);
void queuepush(struct queue *q,int value);
struct queue
{
	int size,r,f;	
	int *arr;
};
void createqueue(struct queue *q)
{
	q->f=-1;
	q->r=-1;
}
int queueempty(struct queue *q)
{
	if(q->f==-1 || q->r==-1)
	return 1;
	return 0;
}
int queuefull(struct queue *q)
{
	if(q->r==q->size-1)
	return 1;
	return 0;
}
void queuepush(struct queue *q,int value)
{
	if(queuefull(q))
	{
		printf("Queue is full\n\n");
	}
	else
	{
	if(q->r==-1)
	{
		q->f=0;
		q->r=0;
		q->arr[q->r]=value;
	}
	else
	{
		q->r=q->r+1;
		q->arr[q->r]=value;
	}
}
}
void queuepop(struct queue *q)
{
	int n;
	if(queueempty(q))
	{
		printf("Queue is empty nothing to delete\n\n");
	}
	else
	{
	n=q->arr[q->f];
	if(q->f==q->r)
	{ 
	 q->f=-1;
	 q->r=-1;
	}
	else
	{
	 q->f=q->f+1;	
	}
	printf("Popped element is %d \n",n);
}
}
void display(struct queue *q)
{
	int i;
	if(queueempty(q))
	{
	 printf("Queue is empty nothing to display\n\n");	
	}
	else
	{
	printf("Elements of queue is:");
	for(i=q->f;i<=q->r;i++)
	{
	printf("%d ",q->arr[i]);
	}
	printf("\n");
}
}
int main()
{
	struct queue *q=(struct queue *)malloc(sizeof(struct queue));
	int choice,n,i,ele;
	createqueue(q);
	printf("Enter the size of queue\n");
    scanf("%d",&n);
	q->size=n;
	q->arr=(int *)malloc(q->size*sizeof(int));
	while(1)
	{
	printf("Press 1 to push the element in queue\n");
	printf("Press 2 to pop element from the queue\n");
	printf("Press 3 to display the queue elements\n");
	printf(" ::Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
		 printf("Enter the element to insert into queue\n");
		 scanf("%d",&ele);
		 queuepush(q,ele);		
		break;
		}
		case 2:
		{
		queuepop(q);	
		break;
		}
		case 3:
		{
		display(q);		
		break;
		}
		case 4:
		{
		exit(0);		
		}
	}
}
}
