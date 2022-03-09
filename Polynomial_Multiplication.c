#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node *insert_node(struct node *H,int coe,int ex);
struct node
{
	int coeff;
	int exp;
	struct node *next;
};
struct node *create_poly(struct node *H1)
{
	int i,co,ex,n;
	printf("Enter the number of terms to be in polynomial\n");
	scanf("%d",&n);
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

struct node *mul_poly(struct node *H1,struct node *H2)
{
	int co,ex;
	struct node *h1,*h2,*H3;
	h1=H1;
	h2=H2;
	H3=NULL;
	while(h1!=NULL)
	{
		while(h2!=NULL)
		{
			co=h1->coeff*h2->coeff;
			ex=h1->exp+h2->exp;
			H3=insert_node(H3,co,ex);
			h2=h2->next;
		}
		h1=h1->next;
		h2=H2;
	}
	return(H3);
}

void display(struct node *H)
{
	struct node *h;
	if(H==NULL)
	{
		printf("Nothing to dispaly\n");
	}
	else
	{
		h=H;
		while(h!=NULL)
		{
			printf("(%dx^%d)",h->coeff,h->exp);
			h=h->next;
			if(h!=NULL)
			{
				printf("+");
			}
			else
			{
				printf("\n");
			}
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
	printf("Enter your first polynomial\n");
	H1=create_poly(H1);
	printf("Enter your second polynomial\n");
	H2=create_poly(H2);
	printf("First polynomial is:");
	display(H1);
	printf("First polynomial is:");
	display(H2);
	printf("Multiplication of two polynomials is:");
	H3=mul_poly(H1,H2);
	display(H3);	
}