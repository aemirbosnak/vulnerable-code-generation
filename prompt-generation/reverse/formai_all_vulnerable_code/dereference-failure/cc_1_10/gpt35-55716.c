//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //initializing variables
    int pushups, situps, squats, day;
    float weight;
    char name[20];

    //taking user inputs
    printf("Welcome to your Fitness Tracker!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("What is your starting weight?\n");
    scanf("%f", &weight);

    //setting up the start date
    time_t t = time(NULL);
    struct tm *start = localtime(&t);

    //displaying the start date to the user
    printf("Today is %d/%d/%d\n", start->tm_mon + 1, start->tm_mday, start->tm_year + 1900);

    //start of the loop
    for (day = 1; day <= 30; day++)
    {
        //taking user inputs for each day
        printf("\nDay %d\n", day);
        printf("How many pushups did you do?\n");
        scanf("%d", &pushups);
        printf("How many situps did you do?\n");
        scanf("%d", &situps);
        printf("How many squats did you do?\n");
        scanf("%d", &squats);

        //calculating the total reps and displaying it to the user
        int total = pushups + situps + squats;
        printf("Total number of reps: %d\n", total);

        //updating the user's weight
        printf("What is your weight for today?\n");
        scanf("%f", &weight);

        //calculating the BMI and displaying it to the user
        float bmi = (weight * 703) / ((start->tm_mon + 1) * (start->tm_mday * start->tm_mday));
        printf("Your current BMI is: %0.2f\n", bmi);
    }

    printf("\nCongratulations %s! You have completed the 30 Day Fitness Challenge!\n", name);

    return 0;
}