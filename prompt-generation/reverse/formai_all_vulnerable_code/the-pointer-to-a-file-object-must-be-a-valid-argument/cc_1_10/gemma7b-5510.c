//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store fitness data
typedef struct FitnessData {
    int stepsTaken;
    int distanceTraveled;
    int caloriesBurned;
    int heartRate;
} FitnessData;

// Create a decentralized fitness tracker
FitnessData fitnessTracker;

// Function to store fitness data
void storeFitnessData() {
    FILE *fp = fopen("fitness_data.txt", "a");
    fprintf(fp, "%d, %d, %d, %d\n", fitnessTracker.stepsTaken, fitnessTracker.distanceTraveled, fitnessTracker.caloriesBurned, fitnessTracker.heartRate);
    fclose(fp);
}

// Function to read fitness data
void readFitnessData() {
    FILE *fp = fopen("fitness_data.txt", "r");
    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        char *data = line;
        fitnessTracker.stepsTaken = atoi(data);
        fitnessTracker.distanceTraveled = atoi(data + 1);
        fitnessTracker.caloriesBurned = atoi(data + 2);
        fitnessTracker.heartRate = atoi(data + 3);
    }
    fclose(fp);
}

int main() {
    // Initialize the fitness tracker
    fitnessTracker.stepsTaken = 0;
    fitnessTracker.distanceTraveled = 0;
    fitnessTracker.caloriesBurned = 0;
    fitnessTracker.heartRate = 0;

    // Read the fitness data from the file
    readFitnessData();

    // Update the fitness data
    fitnessTracker.stepsTaken++;
    fitnessTracker.distanceTraveled++;
    fitnessTracker.caloriesBurned++;
    fitnessTracker.heartRate++;

    // Store the fitness data in the file
    storeFitnessData();

    // Display the fitness data
    printf("Steps taken: %d\n", fitnessTracker.stepsTaken);
    printf("Distance traveled: %d miles\n", fitnessTracker.distanceTraveled);
    printf("Calories burned: %d\n", fitnessTracker.caloriesBurned);
    printf("Heart rate: %d\n", fitnessTracker.heartRate);

    return 0;
}