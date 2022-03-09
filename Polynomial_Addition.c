#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node *insert_node(struct node *H,int co,int ex);
struct node 
{
	int coeff;
	int exp;
	struct node *next;  
 };
 /*
 This code is replaced with line number 85;
 struct node *createnode()
 {
 	struct node *n=(struct node *)malloc(sizeof(struct node));
 	return(n);
 }
 */
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
	   e=h1->exp;
	   if(c!=0)
       {	   
	   H3=insert_node(H3,c,e);
	   }	
	   h1=h1->next;
	   h2=h2->next;	
	  }
	   else if(h1->exp>h2->exp)
	   {
	   	c=h1->coeff;
	   	e=h1->exp;
	    H3=insert_node(H3,c,e);  
		h1=h1->next; 	
	   }	
	   else if(h1->coeff<h2->coeff)
	   {
	   	c=h2->coeff;
	   	e=h2->exp;
	   	H3=insert_node(H3,c,e);
	   	h2=h2->next;
	   }	   
	}
	while(h1!=NULL)
	{
		H3=insert_node(H3,h1->coeff,h1->exp);
		h1=h1->next;
	}
	while(h2!=NULL)
	{
		H3=insert_node(H3,h2->coeff,h2->exp);
		h2=h2->next;
	}
	return(H3); 	
 }
struct node *create_poly(struct node *H1)
{
	int i,co,ex,n;
	printf("Enter the number of terms to be in polynomial\n");
	scanf("%d",&n);
	printf("Enter the polynomial in ascending order of their exponent\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnetr the coefficient of %d term\n",i+1);
		scanf("%d",&co);
		printf("\nEnetr the exponent of %d term\n",i+1);
		scanf("%d",&ex);
		H1=insert_node(H1,co,ex);
	}
	return H1;
}
struct node *insert_node(struct node *H,int coe,int ex)
{
	struct node *t,*n;
	n=(struct node *)malloc(sizeof(struct node));
	n->coeff=coe;
	n->exp=ex;
	n->next=NULL;
	if(H==NULL)
	{
		H=n;
	}
	else
	{
	 t=H;
	 while(t->next!=NULL)
	 {
	 	t=t->next;
	 }	
	 t->next=n;
	}
	return H;	
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
		while(t!=NULL)
		{
		printf("(%dx^%d)",t->coeff,t->exp);
		t=t->next;
		if(t!=NULL)
		printf("+");
		else
		printf("\n");
		}
		printf("\n");
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
    printf("Your first polynomial is: ");
    display(H1);
    printf("Your second polynomial is: ");
    display(H2);
    printf("List after addition is: ");
    display(H3);
}