//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the C Fitness Tracker structure
typedef struct CFitnessTracker {
    int stepsTaken;
    float distanceTraveled;
    char activityType;
    double caloriesBurned;
} CFitnessTracker;

// Function to create a new CFitnessTracker object
CFitnessTracker* createCFitnessTracker() {
    CFitnessTracker* tracker = (CFitnessTracker*)malloc(sizeof(CFitnessTracker));
    tracker->stepsTaken = 0;
    tracker->distanceTraveled = 0.0f;
    tracker->activityType = ' ';
    tracker->caloriesBurned = 0.0;
    return tracker;
}

// Function to update the CFitnessTracker object
void updateCFitnessTracker(CFitnessTracker* tracker, int stepsTaken, float distanceTraveled, char activityType, double caloriesBurned) {
    tracker->stepsTaken += stepsTaken;
    tracker->distanceTraveled += distanceTraveled;
    tracker->activityType = activityType;
    tracker->caloriesBurned += caloriesBurned;
}

// Function to display the CFitnessTracker object
void displayCFitnessTracker(CFitnessTracker* tracker) {
    printf("Steps taken: %d\n", tracker->stepsTaken);
    printf("Distance traveled: %.2f miles\n", tracker->distanceTraveled);
    printf("Activity type: %c\n", tracker->activityType);
    printf("Calories burned: %.2f\n", tracker->caloriesBurned);
}

int main() {
    // Create a new CFitnessTracker object
    CFitnessTracker* tracker = createCFitnessTracker();

    // Update the CFitnessTracker object
    updateCFitnessTracker(tracker, 1000, 2.5f, 'B', 500.0);

    // Display the CFitnessTracker object
    displayCFitnessTracker(tracker);

    return 0;
}