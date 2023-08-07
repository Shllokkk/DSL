#include <stdio.h>  
 
void displayPascalsTriangle(int n) 
{  
    int triangle[100][100];  
  
    for (int i = 0; i< n; i++)    // Initialize first row to 1's  
    {  
        triangle[0][i] = 1;  
    }  
  
    for (int i = 1; i< n; i++)       // Compute subsequent rows  
    {  
        for (int j = 0; j <= i; j++) 
        {  
            if (j == 0 || j == i) 
            {  
                triangle[i][j] = 1;  
            } 
            else 
            {  
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];  
            }  
        }  
    }  
   
printf("Pascal's Triangle (up to row %d):\n", n);  // Display triangle with proper formatting 

    for (int i = 0; i< n; i++) 
    {  
        for (int j = 0; j < n-i-1; j++) 
        {  
            printf("  "); // Add two spaces for each missing number  
        }  
        for (int j = 0; j <= i; j++) 
        {  
            printf("%4d", triangle[i][j]);  // Print each number with 4 digits of spacing  
        }  

        printf("\n");  
    }  
}  
  
void main() 
{  
    int n = 10; // Number of rows to generate  
displayPascalsTriangle(n); // Call the function to display Pascal's Triangle  
}  