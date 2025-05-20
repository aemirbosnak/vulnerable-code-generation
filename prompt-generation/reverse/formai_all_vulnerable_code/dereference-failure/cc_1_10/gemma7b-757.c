//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 1000
#define MAX_DISTANCE 10.0

int main()
{
    int stepsTaken = 0;
    double distanceTraveled = 0.0;
    char timeTaken[20];

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    printf("Welcome to the C Fitness Tracker!\n");
    printf("Let's track your steps and distance today!\n");

    // Loop to track steps and distance
    while (stepsTaken < MAX_STEPS && distanceTraveled < MAX_DISTANCE)
    {
        printf("Enter the number of steps you took: ");
        scanf("%d", &stepsTaken);

        printf("Enter the distance you traveled (in miles): ");
        scanf("%lf", &distanceTraveled);

        // Calculate the time taken
        int hours = tm->tm_hour;
        int minutes = tm->tm_min;

        sprintf(timeTaken, "Time taken: %02d:%02d", hours, minutes);

        // Display the results
        printf("Steps taken: %d\n", stepsTaken);
        printf("Distance traveled: %.2f miles\n", distanceTraveled);
        printf("Time taken: %s\n", timeTaken);

        // Reset the steps and distance
        stepsTaken = 0;
        distanceTraveled = 0.0;
    }

    // End of the loop

    // Final message
    printf("Thank you for using the C Fitness Tracker! Have a healthy day!\n");

    return 0;
}