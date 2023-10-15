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

int partition(int arr[],int begindex,int endindex) 
{
    int left,right,location,temp,flag;
    left=location=begindex;
    right=endindex;
    flag=0;

    while(flag!=1)
    {
        while(arr[location]<=arr[right] && location!=right)
            right--;

        if(location==right)
            flag=1;
        else if(arr[location]>arr[right])
        {   
            temp=arr[location];
            arr[location]=arr[right];
            arr[right]=temp;
            location=right;
        }

        if(flag!=0)
        {
            while(arr[location]>=arr[left] && location!=left)
                left++;

            if(location==left)
                flag=1;
            else if(arr[location]<arr[left])
            {   
                temp=arr[location];
                arr[location]=arr[left];
                arr[left]=temp;
                location=left;
            }
        }
    }
    return location;
}