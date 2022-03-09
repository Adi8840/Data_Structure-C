#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i,j;
	printf("Enter the number of bits to operate the operation\n");
	scanf("%d",&n);
	printf("The truth table of AND and OR gate is:\n");
	printf("\tA\t\tB\t\tAND(RESULT(A.B))\t\tOR(RESULT(A+B))\n");
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
	printf("\t%d\t\t%d\t\t\t%d\t\t\t\t%d\n",i,j,i&&j,i||j);
	}
	}
	printf("\nThe truth table of NOT gate is:\n");
    printf("\tA\t\tA`(RESULT)\n");
    for(i=0;i<n;i++)
    {
    	printf("\t%d\t\t%d\n",i,(!i));
	}
}