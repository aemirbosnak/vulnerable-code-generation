//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User-defined data structure for each fitness activity
typedef struct {
    char activity_type[20]; // Running, cycling, swimming etc.
    double distance; // In kilometers
    int duration; // In minutes
    double calories_burnt; // In Kcal
} fitness_activity;

// Function to display the details of a fitness activity
void display_activity(fitness_activity activity) {
    printf("%s\n", activity.activity_type);
    printf(" Distance: %.2f kms\n", activity.distance);
    printf(" Duration: %d minutes\n", activity.duration);
    printf(" Calories burnt: %.2f Kcal\n\n", activity.calories_burnt);
}

int main() {
    int max_activities = 10; // Maximum number of activities that can be recorded
    int num_activities = 0; // Number of activities recorded so far
    int option, i;

    // Allocate memory for an array of fitness_activity structures
    fitness_activity *activities = (fitness_activity*) malloc(max_activities * sizeof(fitness_activity));

    // Display the main menu and prompt the user to choose an option
    printf("Welcome to C Fitness Tracker\n");
    printf("1. Record a new activity\n");
    printf("2. Display all the recorded activities\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    while (option != 3) {
        switch (option) {
            case 1: // Record a new activity
                if (num_activities < max_activities) {
                    fitness_activity activity;
                    printf("Enter the type of activity (Running, Cycling, Swimming etc.): ");
                    scanf("%s", activity.activity_type);
                    printf("Enter the distance (in kms): ");
                    scanf("%lf", &activity.distance);
                    printf("Enter the duration (in minutes): ");
                    scanf("%d", &activity.duration);
                    printf("Enter the calories burnt (in Kcal): ");
                    scanf("%lf", &activity.calories_burnt);
                    activities[num_activities] = activity;
                    num_activities++;
                    printf("Activity successfully recorded!\n\n");
                } else {
                    printf("Maximum number of activities reached!\n\n");
                }
                break;

            case 2: // Display all the recorded activities
                printf("List of recorded activities:\n\n");
                for (i = 0; i < num_activities; i++) {
                    display_activity(activities[i]);
                }
                break;

            default: // Invalid option
                printf("Invalid option. Please try again!\n\n");
                break;
        }

        // Display the main menu and prompt the user to choose an option
        printf("1. Record a new activity\n");
        printf("2. Display all the recorded activities\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
    }

    printf("Thank you for using C Fitness Tracker! Stay fit and healthy!\n");

    // Free the dynamically allocated memory
    free(activities);

    return 0;
}