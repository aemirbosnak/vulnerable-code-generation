//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store fitness data
typedef struct FitnessData {
  time_t timestamp;  // Time of the measurement
  int steps;         // Number of steps taken
  int heartRate;     // Heart rate in beats per minute
  float distance;    // Distance traveled in kilometers
  float calories;    // Calories burned
} FitnessData;

// Allocate and initialize fitness data structure
FitnessData *createFitnessData() {
  FitnessData *data = malloc(sizeof(FitnessData));
  data->timestamp = time(NULL);
  data->steps = 0;
  data->heartRate = 0;
  data->distance = 0.0f;
  data->calories = 0.0f;
  return data;
}

// Free memory allocated for fitness data structure
void destroyFitnessData(FitnessData *data) {
  free(data);
}

// Update fitness data structure with new measurements
void updateFitnessData(FitnessData *data, int steps, int heartRate, float distance, float calories) {
  data->timestamp = time(NULL);
  data->steps += steps;
  data->heartRate += heartRate;
  data->distance += distance;
  data->calories += calories;
}

// Print fitness data to console
void printFitnessData(FitnessData *data) {
  printf("Timestamp: %ld\n", data->timestamp);
  printf("Steps: %d\n", data->steps);
  printf("Heart rate: %d bpm\n", data->heartRate);
  printf("Distance: %.2f km\n", data->distance);
  printf("Calories: %.2f\n", data->calories);
}

// Main function
int main() {
  // Create fitness tracker object
  FitnessData *fitnessData = createFitnessData();

  // Simulate fitness activity
  time_t startTimestamp = time(NULL);
  for (int i = 0; i < 1000; i++) {
    // Update fitness data every second
    if (difftime(time(NULL), startTimestamp) >= 1) {
      updateFitnessData(fitnessData, 100, 70, 0.1f, 10.0f);
      startTimestamp = time(NULL);
    }
  }

  // Print fitness data
  printFitnessData(fitnessData);

  // Free memory allocated for fitness tracker object
  destroyFitnessData(fitnessData);

  return 0;
}