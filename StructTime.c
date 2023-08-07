#include <stdio.h>

struct time
{
    int sec;
    int min;
    int hour;
};

// function prototypes
struct time input();
void display1(struct time);
void display2(struct time);
struct time increment(struct time);

void main()
{
    struct time t1,t2;

    t1=input();
    display1(t1);
    t2=increment(t1);
    display2(t2);

}// end of main

struct time input()
{
    struct time obj;

    printf("Enter time (24hr format)\n");
    printf("Hour: ");
    scanf("%d",&obj.hour);
    printf("Minutes: ");
    scanf("%d",&obj.min);
    printf("Seconds: ");
    scanf("%d",&obj.sec);

    return obj;
}// end of input

void display1(struct time obj1)
{
    printf("\nThe Entered time is: ");
    printf("\n%d hrs %d mins %d secs",obj1.hour,obj1.min,obj1.sec);
}// end of display1

struct time increment(struct time obj3)
{
    obj3.sec++;

    if(obj3.sec==60)
    {
        obj3.min++;
        obj3.sec=0;

        if(obj3.min==60)
        {
            obj3.hour++;
            obj3.min=0;

            if(obj3.hour==24)
            {
                obj3.hour=0;
            }
        }
    }
    return obj3;
}// end of increment

void display2(struct time obj2)
{
    printf("\n\nThe incremented time is:");
    printf("\n%d hrs %d mins %d secs",obj2.hour,obj2.min,obj2.sec);
}// end of display2