//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Curious names for our fitness tracker metrics
typedef enum {
    STEPS_TAKEN = 1,
    HEART_RATE = 2,
    DISTANCE_TRAVELED = 3,
    CALORIES_BURNED = 4
} MetricType;

typedef enum {
    KILOMETERS,
    MILES
} DistanceUnit;

// Our fitness tracker's data structure
typedef struct FitnessTracker {
    int stepsTaken;
    int heartRate;
    float distanceTraveled;
    DistanceUnit distanceUnit;
    int caloriesBurned;
    time_t lastUpdateTime;
} FitnessTracker;

// Initialize a fitness tracker with default values
FitnessTracker* initializeFitnessTracker() {
    FitnessTracker* tracker = (FitnessTracker*)malloc(sizeof(FitnessTracker));
    tracker->stepsTaken = 0;
    tracker->heartRate = 0;
    tracker->distanceTraveled = 0.0;
    tracker->distanceUnit = KILOMETERS;
    tracker->caloriesBurned = 0;
    tracker->lastUpdateTime = time(NULL);
    return tracker;
}

// Increment the number of steps taken by the user
void incrementStepsTaken(FitnessTracker* tracker, int steps) {
    tracker->stepsTaken += steps;
    tracker->lastUpdateTime = time(NULL);
}

// Record the user's heart rate
void recordHeartRate(FitnessTracker* tracker, int heartRate) {
    tracker->heartRate = heartRate;
    tracker->lastUpdateTime = time(NULL);
}

// Calculate the distance traveled by the user based on their steps taken and stride length
void calculateDistanceTraveled(FitnessTracker* tracker, float strideLength) {
    tracker->distanceTraveled = (float)tracker->stepsTaken * strideLength;
    tracker->lastUpdateTime = time(NULL);
}

// Set the distance unit used by the tracker
void setDistanceUnit(FitnessTracker* tracker, DistanceUnit unit) {
    tracker->distanceUnit = unit;
}

// Calculate the calories burned by the user based on their weight, heart rate, and activity level
void calculateCaloriesBurned(FitnessTracker* tracker, float weight, int activityLevel) {
    // METs (Metabolic Equivalents of Task) are a measure of the energy cost of an activity
    float METs = 0.0;
    switch (activityLevel) {
        case 1: // Sedentary
            METs = 1.0;
            break;
        case 2: // Light activity
            METs = 2.0;
            break;
        case 3: // Moderate activity
            METs = 3.0;
            break;
        case 4: // Vigorous activity
            METs = 4.0;
            break;
    }

    // Calories burned per hour = METs * body weight (kg) * 3.5
    float caloriesPerHour = METs * weight * 3.5;
    tracker->caloriesBurned = (int)(caloriesPerHour * ((float)(time(NULL) - tracker->lastUpdateTime) / 3600.0));
    tracker->lastUpdateTime = time(NULL);
}

// Print the fitness tracker's data
void printFitnessTrackerData(FitnessTracker* tracker) {
    printf("Steps taken: %d\n", tracker->stepsTaken);
    printf("Heart rate: %d bpm\n", tracker->heartRate);
    switch (tracker->distanceUnit) {
        case KILOMETERS:
            printf("Distance traveled: %.2f km\n", tracker->distanceTraveled);
            break;
        case MILES:
            printf("Distance traveled: %.2f miles\n", tracker->distanceTraveled);
            break;
    }
    printf("Calories burned: %d\n", tracker->caloriesBurned);
}

// Generate a random fitness tracker data point
FitnessTracker* generateRandomFitnessTrackerData() {
    FitnessTracker* tracker = initializeFitnessTracker();
    srand(time(NULL));
    tracker->stepsTaken = rand() % 10000 + 1;
    tracker->heartRate = rand() % 150 + 1;
    tracker->distanceTraveled = (float)(rand() % 1000) / 100.0;
    tracker->distanceUnit = rand() % 2 == 0 ? KILOMETERS : MILES;
    tracker->caloriesBurned = rand() % 1000 + 1;
    return tracker;
}

int main() {
    // Create a fitness tracker
    FitnessTracker* tracker = initializeFitnessTracker();

    // Increment the number of steps taken
    incrementStepsTaken(tracker, 1000);

    // Record the user's heart rate
    recordHeartRate(tracker, 75);

    // Calculate the distance traveled by the user
    calculateDistanceTraveled(tracker, 0.75);

    // Set the distance unit used by the tracker
    setDistanceUnit(tracker, MILES);

    // Calculate the calories burned by the user
    calculateCaloriesBurned(tracker, 70.0, 3);

    // Print the fitness tracker's data
    printFitnessTrackerData(tracker);

    return 0;
}