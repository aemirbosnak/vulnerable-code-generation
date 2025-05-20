//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int steps[7];
    int totalSteps = 0;
    double distance = 0;
    int i;
    char userInput;

    srand(time(NULL)); //seed random number generator
    
    printf("Welcome to the Fitness Tracker!\n\n");

    //get number of steps for each day of the week
    for(i = 0; i < 7; i++) {
        steps[i] = rand() % 5000 + 1000;
        totalSteps += steps[i];
    }

    distance = totalSteps * 0.0005; //calculate distance in kilometers

    //display weekly stats to user
    printf("Weekly Stats:\n");
    printf("--------------\n");
    printf("Monday: %d steps\n", steps[0]);
    printf("Tuesday: %d steps\n", steps[1]);
    printf("Wednesday: %d steps\n", steps[2]);
    printf("Thursday: %d steps\n", steps[3]);
    printf("Friday: %d steps\n", steps[4]);
    printf("Saturday: %d steps\n", steps[5]);
    printf("Sunday: %d steps\n", steps[6]);
    printf("\n");

    printf("Total steps for the week: %d\n", totalSteps);
    printf("Distance walked for the week: %.2f km\n", distance);
    printf("\n");

    //ask user if they want to set a new goal
    printf("Would you like to set a new goal for the upcoming week? (y/n) ");
    scanf("%c", &userInput);
    
    if(userInput == 'y') {
        int newGoal;
        printf("\nEnter your new step goal for the upcoming week: ");
        scanf("%d", &newGoal);
        printf("\n");
        
        int daysLeft = 7 - i; //calculate number of days left in week
        int dailyGoal = (newGoal - totalSteps) / daysLeft; //calculate daily step goal needed to meet weekly goal

        printf("Daily step goal for the remaining %d days: %d\n", daysLeft, dailyGoal);
    }

    printf("Thank you for using the Fitness Tracker!\n");
    return 0;
}