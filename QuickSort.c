#include<stdio.h>

void quickSort(int[],int,int);
int partition(int[],int,int);

void main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);

    int array[n];
    printf("\nEnter elements of array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&array[i]);

    quickSort(array,0,n-1);
    printf("\nArray sorted in ascending order: ");
    for(int i=0;i<n;i++)
        printf("%d ",array[i]);
}

void quickSort(int arr[],int begindex,int endindex)
{
    int location;
    while(begindex<endindex)
    {
        location=partition(arr,begindex,endindex);
        quickSort(arr,begindex,location-1);
        quickSort(arr,location+1,endindex);
    }
}
