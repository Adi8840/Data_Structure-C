#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void display(struct list *H);
struct list *merge_lists();
void push_ele2(int val);
void push_ele1(int val);
struct list *create_list();
struct list
{
	int data;
	struct list *next;
};
 struct list *H1=NULL;
 struct list *H2=NULL;
 struct list *H3=NULL;
struct list *create_list()
{
  struct list *ptr;
  ptr=(struct list *)malloc(sizeof(struct list));
  return(ptr);
}
void push_ele1(int val)
 {
 	struct list *node,*t;
 	node=create_list();
 	node->data=val;
 	node->next=NULL;
 	if(H1==NULL)
 	{
 	  H1=node;	
	}
	else
	{
	  t=H1;
	  while(t->next!=NULL)
	  {
	  	t=t->next;
	  }	
	  t->next=node;
	}
 }
void push_ele2(int val)
 {
 	struct list *node,*t;
 	node=create_list();
 	node->data=val;
 	node->next=NULL;
 	if(H2==NULL)
 	{
 		H2=node;
	 }
	 else
	 {
	 	t=H2;
	 	while(t->next!=NULL)
	 	{
	 		t=t->next;
	    }
		 t->next=node;
	 }
 }
 struct list *merge_lists()
 {
 	struct list *h1,*h2,*h3;
 	h1=H1;
 	h2=H2;
 	h3=H3;
 	while(h1!=NULL && h2!=NULL)
 	{
 		if(h1->data<h2->data)
 		{
 	     h3->next=h1;
 	     h1=h1->next;
		}
		else
		{
		  h3->next=h2;
		  h2=h2->next;	
		}
		h3=h3->next;
	 }
	 while(h1!=NULL)
	 {
	 	h3->next=h1;
	 	h1=h1->next;
	 	h3=h3->next;
	 }
	 while(h2!=NULL)
	 {
	 	h3->next=h2;
	 	h2=h2->next;
	 	h3=h3->next;
	 }
	return(H3->next);

}

void display(struct list *H)
{
	struct list *t;
	t=H;
	printf("List after merging two lists is:");
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}
	printf("\n");
}

int main()
{
	struct list *x;
  int i,ele,merge,merg;
  int ch,n1,n2;
  printf("Welcome to merging of two linked list\n");
  printf("Enter the size of first list\n");
  scanf("%d",&n1);
  printf("Enter the elements of first list\n");
  for(i=0;i<n1;i++)
  {  
  scanf("%d",&ele);
  push_ele1(ele);
  }
   printf("Enter the size of second list\n");
  scanf("%d",&n2);
   printf("Enter the elements of second list\n");
  for(i=0;i<n2;i++)
  {
  scanf("%d",&ele);
  push_ele2(ele);
  }
  printf("Press 1 to merge both the lists\n");
  scanf("%d",&merge);
  if(merge==1)
  {
   x=merge_lists();
   //printf("Press 1 to display\n");
   //scanf("%d",&merg);
   //if(merg==1)
   //{
  	display(x);
   //} 	
  }
  return 1; 
 
}