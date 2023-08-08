#include <stdio.h>

void main()
{
	int array[10]={12,24,56,41,78,63,95,02,23,14};
	int largest;
	
	largest=array[0];
	
	for(int i=1;i<10;i++)                // loop to traverse the array
	{
		if(largest<array[i])         //condition for largest number
		{
			largest=array[i];
		}
	}
	
	printf("The largest element in the array is: %d",largest);
	
}// end of main
