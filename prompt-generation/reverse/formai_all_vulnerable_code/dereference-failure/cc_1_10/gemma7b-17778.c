//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a fitness tracker
typedef struct FitnessTracker {
    char name[20];
    int age;
    double weight;
    int stepsTaken;
    double distanceTraveled;
} FitnessTracker;

// Create a function to calculate the total number of steps taken
int calculateTotalSteps(FitnessTracker* tracker) {
    return tracker->stepsTaken + 2 * tracker->distanceTraveled;
}

// Create a function to calculate the average number of steps taken per day
double calculateAverageStepsPerDay(FitnessTracker* tracker) {
    return (double)tracker->stepsTaken / 7;
}

// Create a function to print the fitness tracker information
void printFitnessTrackerInfo(FitnessTracker* tracker) {
    printf("Name: %s\n", tracker->name);
    printf("Age: %d\n", tracker->age);
    printf("Weight: %.2lf\n", tracker->weight);
    printf("Steps Taken: %d\n", tracker->stepsTaken);
    printf("Distance Traveled: %.2lf miles\n", tracker->distanceTraveled);
    printf("Total Steps Taken: %d\n", calculateTotalSteps(tracker));
    printf("Average Steps Per Day: %.2lf\n", calculateAverageStepsPerDay(tracker));
}

int main() {
    // Create a fitness tracker
    FitnessTracker* tracker = malloc(sizeof(FitnessTracker));

    // Initialize the fitness tracker information
    strcpy(tracker->name, "John Doe");
    tracker->age = 25;
    tracker->weight = 180.0;
    tracker->stepsTaken = 10000;
    tracker->distanceTraveled = 2.5;

    // Print the fitness tracker information
    printFitnessTrackerInfo(tracker);

    // Free the fitness tracker memory
    free(tracker);

    return 0;
}