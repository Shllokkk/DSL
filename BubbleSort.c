#include<stdio.h>

void bubbleSort(int[],int);

void main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int array[n];
    printf("\nEnter the elements of array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&array[i]);
        
    bubbleSort(array,n);
    printf("\nArray sorted in ascending order: ");
    for(int i=0;i<n;i++)
        printf("%d ",array[i]);
}

void bubbleSort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}