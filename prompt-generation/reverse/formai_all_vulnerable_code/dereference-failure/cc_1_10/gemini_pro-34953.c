//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: ultraprecise
// Fitness Tracker Example Program
// By: [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure to store fitness data
typedef struct FitnessData {
    char name[50];              // Name of the user
    char gender;                // Gender of the user (M/F)
    int age;                    // Age of the user
    float height;               // Height of the user (in meters)
    float weight;               // Weight of the user (in kilograms)
    int targetSteps;            // Target number of steps per day
    int actualSteps;            // Number of steps taken so far today
    float caloriesBurned;       // Number of calories burned so far today
    float distanceTraveled;      // Distance traveled so far today (in kilometers)
} FitnessData;

// Function to create a new fitness data structure
FitnessData* createFitnessData(char* name, char gender, int age, float height, float weight, int targetSteps) {
    FitnessData* fitnessData = malloc(sizeof(FitnessData));
    strcpy(fitnessData->name, name);
    fitnessData->gender = gender;
    fitnessData->age = age;
    fitnessData->height = height;
    fitnessData->weight = weight;
    fitnessData->targetSteps = targetSteps;
    fitnessData->actualSteps = 0;
    fitnessData->caloriesBurned = 0.0f;
    fitnessData->distanceTraveled = 0.0f;
    return fitnessData;
}

// Function to update the fitness data with new steps taken
void updateSteps(FitnessData* fitnessData, int steps) {
    fitnessData->actualSteps += steps;
    // Calculate calories burned based on steps taken
    fitnessData->caloriesBurned += (0.02 * fitnessData->weight * steps);
    // Calculate distance traveled based on steps taken
    fitnessData->distanceTraveled += (0.00065 * steps);
}

// Function to print the fitness data
void printFitnessData(FitnessData* fitnessData) {
    printf("Name: %s\n", fitnessData->name);
    printf("Gender: %c\n", fitnessData->gender);
    printf("Age: %d\n", fitnessData->age);
    printf("Height: %.2f m\n", fitnessData->height);
    printf("Weight: %.2f kg\n", fitnessData->weight);
    printf("Target Steps: %d\n", fitnessData->targetSteps);
    printf("Actual Steps: %d\n", fitnessData->actualSteps);
    printf("Calories Burned: %.2f\n", fitnessData->caloriesBurned);
    printf("Distance Traveled: %.2f km\n", fitnessData->distanceTraveled);
}

// Main function
int main() {
    // Create a fitness data structure for the user
    FitnessData* fitnessData = createFitnessData("John Doe", 'M', 30, 1.80, 80.0, 10000);

    // Simulate steps taken throughout the day
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        // Generate a random number of steps taken between 100 and 1000
        int steps = rand() % 1000 + 100;
        // Update the fitness data with the new steps taken
        updateSteps(fitnessData, steps);
    }

    // Print the fitness data
    printFitnessData(fitnessData);

    // Free the allocated memory
    free(fitnessData);

    return 0;
}