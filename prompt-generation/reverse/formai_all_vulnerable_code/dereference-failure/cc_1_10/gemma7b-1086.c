//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store fitness tracker data
typedef struct FitnessTrackerData {
    int stepsTaken;
    int caloriesBurned;
    double distanceTraveled;
    char activityType;
} FitnessTrackerData;

// Function to calculate the number of steps taken
int calculateStepsTaken(int minutes) {
    return minutes * 20;
}

// Function to calculate the number of calories burned
int calculateCaloriesBurned(int minutes, char activityType) {
    switch (activityType) {
        case 'a':
            return minutes * 60;
        case 'c':
            return minutes * 80;
        case 'e':
            return minutes * 100;
        default:
            return 0;
    }
}

// Function to calculate the distance traveled
double calculateDistanceTraveled(int stepsTaken) {
    return (double) stepsTaken / 1000 * 2;
}

// Main function
int main() {
    // Create a fitness tracker data structure
    FitnessTrackerData fitnessTrackerData;

    // Get the user's input
    printf("Enter the number of minutes you spent exercising: ");
    int minutes = atoi(fgets(NULL, 20, stdin));

    // Get the user's activity type
    printf("Enter the type of activity you did (a, c, e): ");
    char activityType = fgets(NULL, 20, stdin)[0];

    // Calculate the number of steps taken, calories burned, and distance traveled
    fitnessTrackerData.stepsTaken = calculateStepsTaken(minutes);
    fitnessTrackerData.caloriesBurned = calculateCaloriesBurned(minutes, activityType);
    fitnessTrackerData.distanceTraveled = calculateDistanceTraveled(fitnessTrackerData.stepsTaken);

    // Print the fitness tracker data
    printf("Number of steps taken: %d\n", fitnessTrackerData.stepsTaken);
    printf("Number of calories burned: %d\n", fitnessTrackerData.caloriesBurned);
    printf("Distance traveled: %.2lf miles\n", fitnessTrackerData.distanceTraveled);

    return 0;
}