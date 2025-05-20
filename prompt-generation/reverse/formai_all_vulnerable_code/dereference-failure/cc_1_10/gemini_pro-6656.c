//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of steps and heart rate values to store
#define MAX_STEPS 1000
#define MAX_HEARTRATE 1000

// Define the structure to store the fitness data
typedef struct FitnessData {
    int steps[MAX_STEPS];
    int heartRate[MAX_HEARTRATE];
    int numSteps;
    int numHeartRate;
} FitnessData;

// Create a new fitness data structure
FitnessData* createFitnessData() {
    FitnessData* data = malloc(sizeof(FitnessData));
    data->numSteps = 0;
    data->numHeartRate = 0;
    return data;
}

// Add a new step to the fitness data
void addStep(FitnessData* data, int steps) {
    if (data->numSteps < MAX_STEPS) {
        data->steps[data->numSteps++] = steps;
    }
}

// Add a new heart rate value to the fitness data
void addHeartRate(FitnessData* data, int heartRate) {
    if (data->numHeartRate < MAX_HEARTRATE) {
        data->heartRate[data->numHeartRate++] = heartRate;
    }
}

// Print the fitness data
void printFitnessData(FitnessData* data) {
    printf("Steps:\n");
    for (int i = 0; i < data->numSteps; i++) {
        printf("%d\n", data->steps[i]);
    }

    printf("Heart Rate:\n");
    for (int i = 0; i < data->numHeartRate; i++) {
        printf("%d\n", data->heartRate[i]);
    }
}

// Free the memory allocated for the fitness data
void freeFitnessData(FitnessData* data) {
    free(data);
}

// Main function
int main() {
    // Create a new fitness data structure
    FitnessData* data = createFitnessData();

    // Add some sample data to the fitness data structure
    addStep(data, 1000);
    addStep(data, 2000);
    addStep(data, 3000);
    addHeartRate(data, 70);
    addHeartRate(data, 80);
    addHeartRate(data, 90);

    // Print the fitness data
    printFitnessData(data);

    // Free the memory allocated for the fitness data
    freeFitnessData(data);

    return 0;
}