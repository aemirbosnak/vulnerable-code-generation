//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the data structures
typedef struct {
    int steps;
    int distance;
    int calories;
    int heartRate;
} FitnessData;

typedef struct {
    FitnessData data[100];
    int size;
} FitnessTracker;

// Create a new fitness tracker
FitnessTracker* createFitnessTracker() {
    FitnessTracker* tracker = (FitnessTracker*)malloc(sizeof(FitnessTracker));
    tracker->size = 0;
    return tracker;
}

// Add a new fitness data to the tracker
void addFitnessData(FitnessTracker* tracker, FitnessData data) {
    tracker->data[tracker->size++] = data;
}

// Get the total steps taken today
int getTotalSteps(FitnessTracker* tracker) {
    int totalSteps = 0;
    for (int i = 0; i < tracker->size; i++) {
        totalSteps += tracker->data[i].steps;
    }
    return totalSteps;
}

// Get the total distance traveled today
int getTotalDistance(FitnessTracker* tracker) {
    int totalDistance = 0;
    for (int i = 0; i < tracker->size; i++) {
        totalDistance += tracker->data[i].distance;
    }
    return totalDistance;
}

// Get the total calories burned today
int getTotalCalories(FitnessTracker* tracker) {
    int totalCalories = 0;
    for (int i = 0; i < tracker->size; i++) {
        totalCalories += tracker->data[i].calories;
    }
    return totalCalories;
}

// Get the average heart rate today
int getAverageHeartRate(FitnessTracker* tracker) {
    int totalHeartRate = 0;
    for (int i = 0; i < tracker->size; i++) {
        totalHeartRate += tracker->data[i].heartRate;
    }
    return totalHeartRate / tracker->size;
}

// Print the fitness data for today
void printFitnessData(FitnessTracker* tracker) {
    printf("Total steps taken today: %d\n", getTotalSteps(tracker));
    printf("Total distance traveled today: %d\n", getTotalDistance(tracker));
    printf("Total calories burned today: %d\n", getTotalCalories(tracker));
    printf("Average heart rate today: %d\n", getAverageHeartRate(tracker));
}

// Main function
int main() {
    // Create a new fitness tracker
    FitnessTracker* tracker = createFitnessTracker();

    // Add some fitness data to the tracker
    FitnessData data1 = {1000, 10, 100, 70};
    FitnessData data2 = {2000, 20, 200, 80};
    FitnessData data3 = {3000, 30, 300, 90};
    addFitnessData(tracker, data1);
    addFitnessData(tracker, data2);
    addFitnessData(tracker, data3);

    // Print the fitness data for today
    printFitnessData(tracker);

    return 0;
}