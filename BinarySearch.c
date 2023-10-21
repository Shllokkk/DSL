#include<stdio.h>

void bubbleSort(int[],int);
int binarySearch(int[],int,int,int);

void main()
{
    int num, size, flag;
    
    printf("\nEnter the size of array: ");
    scanf("%d",&size);

    int array[size];

    printf("\nEnter the elements of array: ");
    for(int i=0;i<size;i++)
        scanf("%d",&array[i]);
    
    bubbleSort(array,size);

    printf("\nEnter the number to be searched: ");
    scanf("%d",&num);

    flag=binarySearch(array,0,size-1,num);

    if(flag==0)
        printf("\nNumber not present in array.");
    else
        printf("\nNumebr present in array.");
}

void bubbleSort(int arr[],int size)
{
    int temp;

    for(int i=0;i<size;i++)
        for(int j=0;j<size-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
}

int binarySearch(int arr[],int startindex,int endindex,int num)
{
    int midindex=(startindex+endindex)/2;

    while(startindex<=endindex)
    {
        if(num==arr[midindex])
            return midindex;
        else if(num>arr[midindex])
            return binarySearch(arr,midindex+1,endindex,num);
        else 
            return binarySearch(arr,startindex,midindex-1,num);
    }
    return 0;
}