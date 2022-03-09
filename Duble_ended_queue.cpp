#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void pushF(struct DQ *q,int value);
void pushR(struct DQ *q,int value);
void popF(struct DQ *q);
void popR(struct DQ *q);
void display();
struct DQ
{
	int *arr;
	int f,r,size;
};
void createDQ(struct DQ *q)
{
	q->f=-1;
	q->r=-1;
}
void pushF(struct DQ *q,int value)
{
	if(q->f==0)
	printf("DQ is full from front end first delete element from front end then add:\n\n"); 
	else
	{
	 if(q->f==-1)
	 {
	  q->f=q->size-1;
	  q->r=q->size-1;
	 }	
	 else
	 {
	 	q->f=q->f-1;
	 }
	 q->arr[q->f]=value;	                
	}
}
void pushR(struct DQ *q,int value)
{
	if(q->r==q->size-1)
	printf("DQ is full from rear end first delete element from rear and then push element:\n\n");
	else
	{
		if(q->r==-1)
		{
		q->f=0;
		q->r=0;
		}
		else
		{
		 q->r=q->r+1;	
		}
		q->arr[q->r]=value;	
	}
}
void popF(struct DQ *q)
{
  int ele;
    if(q->f==-1 || q->r==-1)
	printf("DQ is empty nothing to delete\n");
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
	  	q->f=q->f+1;
	  }
	printf("Popped element from front end of DQ is %d\n",ele);
	printf("\n");	  
	}	
}
void popR(struct DQ *q)
{
  int ele;
    if(q->f==-1 || q->r==-1)
	printf("DQ is empty nothing to delete\n");
	else
	{
    ele=q->arr[q->r];
	  if(q->f==q->r)
	  {
	  	q->f=-1;
	  	q->r=-1;
	  }	
	  else
	  {
	  	q->r=q->r-1;
	  }
	printf("Popped element from rear end of DQ is %d",ele); 
	printf("\n");
	}	
}
void display(struct DQ *q)
{
	int i;
	struct DQ *t=q;
	if(q->f==-1 || q->r==-1)
	printf("DQ is empty nothing to display\n\n");
	else
	{
		printf("Elements of Doube Ended Queue is:");
		for(i=t->f;i<=t->r;i++)
		{
		printf("%d ",q->arr[i]);
		}
		printf("\n");
	}
}

int main()
{
	int ch,ele,n;
	struct DQ *q=(struct DQ *)malloc(sizeof(struct DQ));
	createDQ(q);
	printf("Enter the size of DQ\n");
	scanf("%d",&n);
	q->size=n;
	q->arr=(int *)malloc(q->size*sizeof(int));	
	while(1)
	{
	printf("Press  1 to insert element from front\n");
	printf("Press  2 to insert element from rear\n");
	printf("Press  3 to delete element from front\n");
	printf("Press  4 to delete element fron rear\n");
	printf("Press  5 to diplsy elements of double ended queue\n");
	printf("Press  6 to quit from the program\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
	    case 1:
	    {
	    printf("Enter the element to insert from front end\n");
	    scanf("%d",&ele);
	    pushF(q,ele);	    
	    break;
	    }
	    case 2:
	    {
	    printf("Enter the element to insert from rear end\n");
	    scanf("%d",&ele);
	    pushR(q,ele);	    
	    break;
	    }
	    case 3:
	    {
	    popF(q);	
	    break;
	    }
	    case 4:
	    {
	    popR(q);
	    break;
	    }
	    case 5:
	    {
	    display(q);
	    break;
	    }
	    case 6:
	    {
	    exit(0);
	    }		
	}
	}
}