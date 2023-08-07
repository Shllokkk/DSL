#include <stdio.h>
#include <stdlib.h>
#include <math.h>

fibocheck(int);

void main()
{
    int num;
    
    printf("Enter a number: ");
    scanf("%d",&num);
    
    fibocheck(num);
} //end of main

fibocheck(int num1) 
{
    int a=(5*num1*num1-4); 
    int b=(5*num1*num1+4);
    int sr1,sr2; 
    sr1=sqrt(a); //to store the square root of a
    sr2=sqrt(b); ///to store the square root of b
    
    //for a number to be fibonacci, atleast one has to be a perfect square
    
    if(sr1*sr1==a||sr2*sr2==b) //method to check perfect square
    {
        printf("\nis the entered number a fibonacci member?: YES");
    }
    else
    printf("\nis the number a fibonacci member?: NO");
    
} //end of fibocheck