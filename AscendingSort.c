#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int roll;
    char name[50];
    float perc;
}s[5]; //Array of structure variable

void main()
{
    int a; //for roll swap
    char str[50]; //for name swap
    float c; //for percentage swap
    
    //to input structure variables
    for(int i=0;i<5;i++) 
    {
        printf("\nEnter name of student %d: ",i+1);
        scanf("%s",s[i].name);
        printf("\nEnter roll no. of student %d: ",i+1);
        scanf("%d",&s[i].roll);
        printf("\nEnter percentage of student %d: ",i+1);
        scanf("%f",&s[i].perc);
        printf("\n");
    } //end of for
    
    //loop to sort structure array in any order
    for(int i=0;i<5;i++)
    {
        for (int j=i+1;j<5;j++)
        {
            if(s[i].roll>s[j].roll) //condition 
            {
                a=s[i].roll;
                s[i].roll=s[j].roll;
                s[j].roll=a;
                
                strcpy (str,s[i].name);
                strcpy(s[i].name,s[j].name);
                strcpy(s[j].name,str);
                
                c=s[i].perc;
                s[i].perc=s[j].perc;
                s[j].perc=c;
            } //end of if
        } //end of inner for
    } //end of outer for
    
    //loop to display sorted structure array
    for(int i=0;i<5;i++)
    {
        printf("\n\nStudent %d",i+1);
        printf("\nName: %s",s[i].name);
        printf("\nRoll no: %d",s[i].roll);
        printf("\nPercentage: %f",s[i].perc);
        
    } //end of for
} //end of main