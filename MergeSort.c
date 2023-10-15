#include<stdio.h>

void merge(int[],int,int,int,int);
void mergeSort(int[],int,int,int);

void main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);

    int array[n];
    printf("\nEnter elements of array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&array[i]);

    mergeSort(array,0,n-1,n);
    printf("\nArray sorted in ascending order: ");
    for(int i=0;i<n;i++)
        printf("%d ",array[i]);
}

void mergeSort(int arr[],int startindex,int endindex,int size) 
{
    if(startindex<endindex) 
    {
        int midindex=(startindex+endindex)/2;
        mergeSort(arr,startindex,midindex,size);
        mergeSort(arr,midindex+1,endindex,size);

        merge(arr,startindex,midindex,endindex,size);
    }
}

void merge(int arr[],int startindex,int midindex,int endindex,int size)
{
    int i=startindex, j=midindex+1,index=startindex;
    int temp[size];

    while(i<=midindex && j<=endindex)
    {
        if(arr[i]<arr[j])
        {
            temp[index]=arr[i];
            i++;
        }
        else
        {
            temp[index]=arr[j];
            j++;
        }
        index++;
    }
 
    if(i>midindex)
    {
        while(j<=endindex)
        {
            temp[index]=arr[j];
            j++;
            index++;
        }
    }
    else
    {
        while(i<=midindex)
        {
            temp[index]=arr[i];
            i++;
            index++;
        }
    }
    
    for(int k=0;k<size;k++)
        arr[k]=temp[k];
}