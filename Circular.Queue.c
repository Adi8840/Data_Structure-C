//Circular QUEUE
//ADITYA RAJPOOT
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//void createCQ(struct CQ *q);
//void pushelement(struct CQ *q,int value);
//void popelement(struct CQ *q);
//void display(struct CQ *q);
struct CQ
{
	int *arr;
	int f,r,size;
};

void createCQ(struct CQ *q)
{
	q->f=-1;
	q->r=-1;
}

int emptyCQ(struct CQ *q)
{
	if(q->f==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int fullCQ(struct CQ *q)
{
	if(q->f==(q->r+1)%q->size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void pushelement(struct CQ *q,int value)
{
   if(fullCQ(q))
   {
   	printf("CQ is full\n\n");
   }
   else
   {
   	if(q->r==-1)
   	{
   		q->f=0;
   		q->r=0;
	}
	else
	{
	  q->r=(q->r+1)%q->size;
	}
	  q->arr[q->r]=value;
   }
}

void popelement(struct CQ *q)
{
	int ele;
	if(emptyCQ(q))
	{
	  printf("CQ is empty nothing to delete\n\n");
	}
	
	else
	{
		ele=q->arr[q->f];
		if(q->f==q->r)
		{
		  q->f=-1;
		  q->r=-1;	
		}
		else
		{
		  q->f=(q->f+1)%q->size;	
		}
		printf("Popped element is %d\n",ele);
	}
}
void display(struct CQ *q)
{
	int i=0;
	struct CQ *t;
	t->f=q->f;
  if(emptyCQ(t))
  {
  	printf("CQ is empty nothing to display\n\n");
  }
  else
  {
  	printf("Elements of CQ is :");
  	while(t->f!=q->r)
  	{  
  	 printf("%d ",q->arr[t->f]);
	 t->f=(t->f+1)%q->size; 	
	}
		printf("%d",q->arr[t->f]);
			printf("\n");
  }		
}
int main()
{
	int n,ch,ele;
  struct CQ *q=(struct CQ *)malloc(sizeof(struct CQ));
  createCQ(q);
  printf("Enter the size of CQ\n");
  scanf("%d",&n);
  q->size=n;
  q->arr=(int *)malloc(q->size*sizeof(int));
  while(1)
  {
  	printf("Press 1 to insert element into CQ\n");
  	printf("Press 2 to delete element from CQ\n");
  	printf("Press 3 to to display the elemnts of CQ\n");
  	printf("Press 4 to to quit from program\n");
  	printf("\nEnter your choice\n");
  	scanf("%d",&ch);
  	switch(ch)
  	{
  	 case 1:
	   {
	   	printf("Enter the element to insert into CQ\n");
	   	scanf("%d",&ele);
	   	pushelement(q,ele);
	   	break;
	   }
	   case 2:
	   {
	   	popelement(q);
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
	   default:
	   {
	   	printf("Invalid input\n");
	   }		
	}
  }
}