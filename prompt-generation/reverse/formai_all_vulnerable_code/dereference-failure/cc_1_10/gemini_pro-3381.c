//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Data structure to store fitness data
typedef struct FitnessData {
    int steps;
    int caloriesBurned;
    int distanceTraveled;
    time_t timestamp;
} FitnessData;

// Function to create a new fitness data object
FitnessData* createFitnessData(int steps, int caloriesBurned, int distanceTraveled, time_t timestamp) {
    FitnessData* data = (FitnessData*)malloc(sizeof(FitnessData));
    data->steps = steps;
    data->caloriesBurned = caloriesBurned;
    data->distanceTraveled = distanceTraveled;
    data->timestamp = timestamp;
    return data;
}

// Function to print fitness data
void printFitnessData(FitnessData* data) {
    printf("Steps: %d\n", data->steps);
    printf("Calories Burned: %d\n", data->caloriesBurned);
    printf("Distance Traveled: %d\n", data->distanceTraveled);
    printf("Timestamp: %s", ctime(&data->timestamp));
}

// Function to generate random fitness data
FitnessData* generateRandomFitnessData() {
    srand(time(NULL));
    int steps = rand() % 10000;
    int caloriesBurned = rand() % 500;
    int distanceTraveled = rand() % 10;
    time_t timestamp = time(NULL);
    return createFitnessData(steps, caloriesBurned, distanceTraveled, timestamp);
}

// Function to store fitness data in a file
void storeFitnessData(FitnessData* data, char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%d,%d,%d,%ld\n", data->steps, data->caloriesBurned, data->distanceTraveled, data->timestamp);
    fclose(file);
}

// Function to load fitness data from a file
FitnessData* loadFitnessData(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }
    int steps, caloriesBurned, distanceTraveled;
    long timestamp;
    fscanf(file, "%d,%d,%d,%ld", &steps, &caloriesBurned, &distanceTraveled, &timestamp);
    fclose(file);
    return createFitnessData(steps, caloriesBurned, distanceTraveled, timestamp);
}

// Main function
int main() {
    // Generate random fitness data
    FitnessData* data = generateRandomFitnessData();

    // Print fitness data
    printf("Fitness Data:\n");
    printFitnessData(data);

    // Store fitness data in a file
    storeFitnessData(data, "fitness_data.txt");

    // Load fitness data from a file
    FitnessData* loadedData = loadFitnessData("fitness_data.txt");

    // Print loaded fitness data
    printf("Loaded Fitness Data:\n");
    printFitnessData(loadedData);

    // Free allocated memory
    free(data);
    free(loadedData);

    return 0;
}