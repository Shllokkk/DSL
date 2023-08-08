#include <stdio.h>

void main()
{
	int arr1[10], arr2[10];
	int counter=0;
	
	printf("Enter first array: ");
	
	for(int i=0;i<10;i++)
	{
		scanf("%d",&arr1[i]);
	}
	
	printf("\n\nEnter second array: ");
	
	for(int i=0;i<10;i++)
	{
		scanf("%d",&arr2[i]);
	}
	
	printf("\nFirst array: ");
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr1[i]);
	}
	
	printf("\nSecond array: ");
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr2[i]);
	}
	
	for(int i=0;i<10;i++)
	{
		if(arr1[i]!=arr2[i])
		{
			counter++;
			break;
		}
	}	
	
	if(counter)
	printf("\nThe arrays are not identical");
	
	else
	printf("\nThe arrays are identical");
}
