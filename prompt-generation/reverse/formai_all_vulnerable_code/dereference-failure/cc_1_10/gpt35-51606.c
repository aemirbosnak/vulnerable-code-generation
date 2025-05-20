//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: invasive
#include <stdio.h>
#include <time.h>

int main() {
    int caloriesBurned = 0;
    int distance = 0;
    int steps = 0;
    int heartRate = 0;
    int timeElapsed = 0;
    int choice = 0;
    time_t startTime = 0;
    time_t endTime = 0;
    struct tm *start = NULL;
    struct tm *end = NULL;

    // Display welcome message
    printf("Welcome to the Fitness Tracker!\n");

    // Display menu options
    printf("Please select an option:\n");
    printf("1. Start Workout\n");
    printf("2. End Workout\n");
    printf("3. Display Workout Statistics\n");
    printf("4. Exit\n");

    // Continuous loop until user decides to exit program
    while (1) {
        // Read user's choice
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Start workout
                printf("\nWorkout started!\n");

                // Record start time
                startTime = time(NULL);
                start = localtime(&startTime);
                printf("Start time: %02d:%02d:%02d\n", start->tm_hour, start->tm_min, start->tm_sec);

                break;
            case 2:
                // End workout
                printf("\nWorkout ended!\n");

                // Record end time
                endTime = time(NULL);
                end = localtime(&endTime);
                printf("End time: %02d:%02d:%02d\n", end->tm_hour, end->tm_min, end->tm_sec);

                // Calculate time elapsed
                timeElapsed = (int) difftime(endTime, startTime);
                printf("Time elapsed: %d seconds\n", timeElapsed);

                // Calculate calories burned
                caloriesBurned = (int) (timeElapsed * 7.5); // Assuming the user burns 7.5 calories per minute
                printf("Calories burned: %d\n", caloriesBurned);

                // Calculate distance covered
                distance = (int) (timeElapsed * 1.4); // Assuming the user covers 1.4 meters per second
                printf("Distance covered: %d meters\n", distance);

                // Prompt user to input heart rate
                printf("Please enter your heart rate: ");
                scanf("%d", &heartRate);
                printf("Heart rate recorded: %d bpm\n", heartRate);

                break;
            case 3:
                // Display workout statistics
                printf("\nWorkout Statistics:");
                printf("\nCalories burned: %d", caloriesBurned);
                printf("\nDistance covered: %d meters", distance);
                printf("\nSteps taken: %d", steps);
                printf("\nHeart rate: %d bpm\n", heartRate);

                break;
            case 4:
                // Exit program
                printf("\nThank you for using the Fitness Tracker!\n");
                return 0;
            default:
                // Invalid input
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}