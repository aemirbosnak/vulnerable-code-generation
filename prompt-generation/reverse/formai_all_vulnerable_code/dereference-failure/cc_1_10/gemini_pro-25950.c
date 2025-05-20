//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store fitness data
typedef struct FitnessData {
    int steps;
    int calories;
    int distance;
    time_t timestamp;
} FitnessData;

// Function to create a new fitness data struct
FitnessData* createFitnessData() {
    FitnessData* data = malloc(sizeof(FitnessData));
    data->steps = 0;
    data->calories = 0;
    data->distance = 0;
    data->timestamp = time(NULL);
    return data;
}

// Function to add steps to the fitness data
void addSteps(FitnessData* data, int steps) {
    data->steps += steps;
}

// Function to add calories to the fitness data
void addCalories(FitnessData* data, int calories) {
    data->calories += calories;
}

// Function to add distance to the fitness data
void addDistance(FitnessData* data, int distance) {
    data->distance += distance;
}

// Function to get the total steps taken
int getTotalSteps(FitnessData* data) {
    return data->steps;
}

// Function to get the total calories burned
int getTotalCalories(FitnessData* data) {
    return data->calories;
}

// Function to get the total distance traveled
int getTotalDistance(FitnessData* data) {
    return data->distance;
}

// Function to get the timestamp of the data
time_t getTimestamp(FitnessData* data) {
    return data->timestamp;
}

// Function to print the fitness data
void printFitnessData(FitnessData* data) {
    printf("Steps taken: %d\n", data->steps);
    printf("Calories burned: %d\n", data->calories);
    printf("Distance traveled: %d\n", data->distance);
    printf("Timestamp: %s\n", ctime(&data->timestamp));
}

// Main function
int main() {
    // Create a new fitness data struct
    FitnessData* data = createFitnessData();

    // Add some steps, calories, and distance to the data
    addSteps(data, 10000);
    addCalories(data, 500);
    addDistance(data, 10);

    // Print the fitness data
    printFitnessData(data);

    // Free the allocated memory
    free(data);

    return 0;
}