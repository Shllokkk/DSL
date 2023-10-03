#include<stdio.h>

void insertionSort(int[],int);

void main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int array[n];
    printf("\nEnter the elements of array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&array[i]);
        
    insertionSort(array,n);
    printf("\nArray sorted in ascending order: ");
    for(int i=0;i<n;i++)
        printf("%d ",array[i]);
}

void insertionSort(int arr[],int size)
{
    int temp;
    int i=1,j;
    temp=arr[i];

    for(int i;i<size;i++)
    {
        temp=arr[i];
        j=i-1;
        while(temp<arr[j]&&j>=0)
        {
           arr[j+1]=arr[j];
           j--; 
        }
        arr[j+1]=temp;
    }
}