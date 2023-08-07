#include <stdio.h>

void main()

{
    int array[10];
    int i,j;

    printf("Enter 10 elements for an array: ");

    for(i=0;i<10;i++)
    {
        scanf("%d",array+i);      //this is another syntax to input an array &array[0]==array, &array[1]==array+1
    }   

    for(i=0;i<10;i++)
    {
        for (j=1+i;j<10;j++)
        {
            if (array[i]==array[j])
            {
                printf("\nDuplicate elements: %d",array[i]);
            }   
        }
      
    }
} // end of main