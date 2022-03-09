#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int display_srack(struct stack *top);
struct stack *pop_element(struct stack *top,int value);
struct stack *push_element(struct stack *top,int value);
struct stack
{
	int data;
	struct stack *next;
};
struct stack *createnode()
{
	struct stack *n;
	n=(struct stack *)malloc(sizeof(struct stack));
	return n;
}
int is_empty(struct stack *top)
{
	if(top==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int  is_full(struct stack *top)
{
	struct stack *n;
	n=createnode();
	if(n==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
struct stack *push_element(struct stack *top,int value)
{
	struct stack *n;
	if(is_full(top))
	{
		printf("Stack is full\n\n");
	}
	else
    {
	n=createnode();
	n->data=value;
	n->next=top;
	top=n;
	return(top);	
    }
}
struct stack *pop_element(struct stack *top)
{
	struct stack *n;
	int x;
	if(is_empty(top))
	{
		printf("Stack is empty\n\n");
	}
	else
	{
		n=top;
		top=top->next;
		x=n->data;
		free(n);
		printf("The popped element is %d\n\n",x);
		return(top);	
	}
}
int top_element(struct stack *top)
{
	int n;
	if(is_empty(top))
	{
		printf("Stack is empty\n");
	}
	else
	{
		n=top->data;
		printf("The topmost element is %d\n\n",n);
	}
}
int display_stack(struct stack *top)
{
	if(is_empty(top))
	{
	printf("Stack is empty nothing to display\n\n");
	}
	else
	{
	printf("Elements of stack is :");
	while(top!=NULL)
	{
	printf("%d ",top->data);
	top=top->next;
	}
	printf("\n\n");	
	}
}
int main()
{
	struct stack *top=NULL;
	int choice,ele;
	while(1)
	{
	printf("Press 1 to insert element into stack\n");
	printf("Press 2 to delete element from the stack\n");
	printf("Press 3 to display the stack elements\n");
	printf("Press 4 to display the topmost element of stack\n");
	printf("Press 5 to quit the program\n\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
	{
	printf("Enter the value to push into stack\n");
	scanf("%d",&ele);
     top=push_element(top,ele);
	break;
	}
	case 2:
	{
    top=pop_element(top);
	break;
	}
	case 3:
	{
    display_stack(top);
	break;
	}
	case 4:
	{
    top_element(top);
	break;
	}
	case 5:
	{
    exit(0);
	}
	default:
	{
	printf("Invalid input press any another key\n");
	break;
	}
	}
}	
}