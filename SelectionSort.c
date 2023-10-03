#include<stdio.h>

int smallest(int[],int,int);
void selectionSort(int[],int);

void main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int array[n];
    printf("\nEnter the elements of array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&array[i]);

    selectionSort(array,n);
    printf("\nArray sorted in ascending order: ");
    for(int i=0;i<n;i++)
        printf("%d ",array[i]);
}

int smallest(int arr[],int size,int start)
{
    int smallindex=start, smallval=arr[start], i=start+1;
    while(i<size)
    {
        if(arr[i]<smallval)
        {
            smallval=arr[i];
            smallindex=i;
        }
        i++;
    }
    return smallindex;
}

void selectionSort(int arr[],int size)
{
    int start=0, smallindex,temp;
    while(start<size)
    {
        int smallindex=smallest(arr,size,start);
        temp=arr[start];
        arr[start]=arr[smallindex];
        arr[smallindex]=temp;
        start++;
    }
}