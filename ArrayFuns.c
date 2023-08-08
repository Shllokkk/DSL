#include <stdio.h>
#include <stdlib.h>

//Function prototypes
void insert(int,int);
void delete(int);
void search (int);
void display();

int array[10]; //declaring array as global

void main() //main function
{
	
	int choice, index, input,e;
	//char e;
	//const char no='n';
	
	printf("The length of the array is 10\n");
	
	
	LABEL:
	while(1)
	{
		printf("\n1. Insert an element into the array.");
		printf("\n2. Delete an element from the array.");
		printf("\n3. Traverse to an elememt of the array.");
		printf("\n4. Search whether an element is present in the array.");
		
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);
		
		if(choice>4)
		{
			printf("Error choice.\n\n");
			continue;
		}
		
		printf("You have selected option no. %d.",choice);	
		break;
		
	} //End of while
	
	switch(choice)
	{
		case 1:
		printf("\n\nEnter the index number: ");
		scanf("%d",&index);
		printf("\nEnter the element: ");
		scanf("%d",&input);
		insert(input,index);
		break;
		
		case 2:
		printf("\n\nEnter the index number: ");
		scanf("%d",&index);
		delete(index);
		break;
		
		case 3:
		display(); //traversing is same as displaying an array
		break;
		
		case 4:
		printf("\n\nEnter the index number: ");
		scanf("%d",&index);
		search(index);
		break;
		
	} //End of switch
	
	printf("\nDo you want to exit(1/0): ");
	scanf("%d",&e);
	
	if (e)
	{
		printf("Exiting the program....");
	}
	else
	{
		goto LABEL;
	}
} //End of main

void insert(int a, int b)
{
	array[b]=a; //assigining the value at array index location.
	display();
}

void delete(int a)
{
	array[a]=0;
	display();
}


void search(int a)
{
	if(a>9)
	{
		printf("\n\nERROR:Array index out of bounds.");
	}
	
	else
		printf("\n\nThe value at array index %d: %d",a,array[a]);
}

void display()
{
	printf("\n\nArray: ");
	for(int i=0;i<10;i++)
	{
		printf("%d  ",array[i]);
	}
	
}

























