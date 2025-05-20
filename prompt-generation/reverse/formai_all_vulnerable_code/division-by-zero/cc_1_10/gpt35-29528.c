//FormAI DATASET v1.0 Category: Robot movement control ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    int distance, speed, time_taken, choice;
    
    printf("Welcome to Robot control program!\n");
    printf("Please enter the distance(in meters) to be covered by the robot: ");
    scanf("%d", &distance);
    printf("Please enter the desired speed(in m/s) of the robot: ");
    scanf("%d", &speed);
    
    time_taken = distance/speed;
    
    printf("The robot will take %d seconds to cover the given distance at the desired speed.\n", time_taken);
    
    printf("To start the robot, please press 1: ");
    scanf("%d", &choice);
    
    if(choice==1)
    {
        printf("Robot started!\n");
        printf("Please wait while the robot covers the distance...\n");
        int i;
        for(i=1; i<=time_taken; i++)
        {
            int rand_num = rand()%100 + 1;
            if(rand_num>=1 && rand_num<=30)
            {
                printf("The robot is moving forward.\n");
            }
            else if(rand_num>=31 && rand_num<=60)
            {
                printf("The robot is turning left.\n");
            }
            else if(rand_num>=61 && rand_num<=90)
            {
                printf("The robot is turning right.\n");
            }
            else
            {
                printf("The robot is taking a break.\n");
            }
        }
        printf("Robot journey completed!\n");
    }
    else
    {
        printf("Invalid input. Please enter 1 to start the robot.\n");
    }
    
    return 0;
}