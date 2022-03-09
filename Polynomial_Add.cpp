#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node *insert_ele(struct node *H,int co,int ex);
struct node 
{
	int coeff;
	int exp;
	struct node *next;  
 };
 struct node *createnode()
 {
 	struct node *n=(struct node *)malloc(sizeof(struct node));
 	return(n);
 }
struct node *add_poly(struct node *H1,struct node *H2)
 {
 	int c,e;
 	struct node *h1,*h2,*H3,*t;
 	h1=H1;
 	h2=H2;
    H3=	NULL;	
 	while(h1!=NULL && h2!=NULL)
 	{
 	   if(h1->exp==h2->exp)
	   {
	   c=h1->coeff+h2->coeff;
	   e=h1->coeff;
	   if(c!=0)
       {	   
	   H3=insert_ele(H3,c,e);
	   }	
	   h1=h1->next;
	   h2=h2->next;	
	  }
	   else if(h1->exp>h2->exp)
	   {
	   	c=h1->coeff;
	   	e=h1->exp;
	    H3=insert_ele(H3,c,e);  
		h1=h1->next; 	
	   }	
	   else if(h1->coeff<h2->coeff)
	   {
	   	c=h2->coeff;
	   	e=h2->exp;
	   	H3=insert_ele(H3,c,e);
	   	h2=h2->next;
	   }	   
	}
	while(h1!=NULL)
	{
		H3=insert_ele(H3,h1->coeff,h1->exp);
		h1=h1->next;
	}
	while(h2!=NULL)
	{
		H3=insert_ele(H3,h2->coeff,h2->exp);
		h2=h2->next;
	}
	return(H3); 	
 }
struct node *create_poly(struct node *H)
{
	int i,n,co,ex;
    printf("Enter the number of coefficient to add in polynomial\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
  	printf("Enter the coefficient of %d term\n",i+1);
  	scanf("%d",&co);
  	printf("Enter the exponent of %d term\n",i+1);
  	scanf("%d",&ex);
	H=insert_ele(H,co,ex); 
    }
	return(H);	
}
struct node *insert_ele(struct node *H,int co,int ex)
{
	struct node *n,*t;
	n=createnode();
	n->coeff=co;
	n->exp=ex;
	n->next=NULL;
	if(H==NULL)
	{
		H=n;
	}
	else
	{
		t=H;
		while(t!=NULL)
		{
			t=t->next;
		}
		t->next=n;
	}
	return(H);
	
}
void display(struct node *H)
{
	struct node *t;
	if(H==NULL)
	{
		printf("Polynomial is empty nothing to add\n");
	}
	else
	{
		t=H;
		while(t->next!=NULL)
		{
		printf("%dx^%d ",t->coeff,t->exp);
		t=t->next;
		}
	}
}
int main()
{
	struct node *H1,*H2,*H3;
	H1=NULL;
	H2=NULL;
	H3=NULL;
	printf("Enter the first polynomial\n");
	H1=create_poly(H1);
	printf("Enter the second polynomial\n");
    H2=create_poly(H2);
    H3=add_poly(H1,H2);
    printf("Your first polynomial is:\n");
    display(H1);
    printf("Your second polynomial is:\n");
    display(H2);
    printf("List after addition is:");
    display(H3);
}