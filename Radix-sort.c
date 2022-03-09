#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int max_element(int *arr,int n);
void display(int *arr,int n);
void radix_sort(int *arr,int n);
void count_sort(int *arr,int n,int pos);
int main()
{
	int n,i,*arr;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("Enter the elements of array\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]); 
	printf("Array before sorting is:");
	display(arr,n);
	radix_sort(arr,n);
	printf("Array after sorting is:");
	display(arr,n);
}
void radix_sort(int *arr,int n)
{
	int max,pos;
	max=max_element(arr,n);
	for(pos=1;max/pos>0;pos*=10)
	{
		count_sort(arr,n,pos);
	}
}
void count_sort(int *arr,int n,int pos)
{
	int *count,*arr1,i,j;
	count=(int *)malloc(10*sizeof(int));//If number is in decimal;
	arr1=(int *)malloc(n*sizeof(int));
	
	for(i=0;i<10;i++)
	count[i]=0;
	
	for(i=0;i<n;i++)
	count[(arr[i]/pos)%10]++;
	
	for(i=1;i<=10;i++)
	count[i]=count[i]+count[i-1];
	
	for(i=n-1;i>=0;i--)
	arr1[count[(arr[i]/pos)%10]-1]=arr[i];
	
	for(i=0;i<n;i++)
	arr[i]=arr1[i];	
}
int max_element(int *arr,int n)
{
	int i,ele=arr[0];
	for(i=1;i<n;i++)
	{
		if(ele<arr[i])
		ele=arr[i];
	}
	return(ele);
}
void display(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
}