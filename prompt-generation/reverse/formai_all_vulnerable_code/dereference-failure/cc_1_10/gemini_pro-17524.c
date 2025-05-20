//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define NUM_YEARS 100
#define NUM_INVASIONS 1000
#define SUCCESS_RATE 0.01

// Define data structures
typedef struct {
  int year;
  int num_invasions;
  int num_successes;
} InvasionData;

// Define functions
InvasionData* generate_invasion_data();
void print_invasion_data(InvasionData* data);
double calculate_probability(InvasionData* data);

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate invasion data
  InvasionData* data = generate_invasion_data();

  // Print invasion data
  print_invasion_data(data);

  // Calculate probability of alien invasion
  double probability = calculate_probability(data);

  // Print probability
  printf("Probability of alien invasion: %.2f%%\n", probability * 100);

  // Free memory
  free(data);

  return 0;
}

// Generate invasion data
InvasionData* generate_invasion_data() {
  // Allocate memory for invasion data
  InvasionData* data = malloc(sizeof(InvasionData) * NUM_YEARS);

  // Generate invasion data
  for (int i = 0; i < NUM_YEARS; i++) {
    data[i].year = i + 1;
    data[i].num_invasions = rand() % NUM_INVASIONS;
    data[i].num_successes = rand() % data[i].num_invasions;
  }

  // Return invasion data
  return data;
}

// Print invasion data
void print_invasion_data(InvasionData* data) {
  // Print header
  printf("Year\tNum Invasions\tNum Successes\n");

  // Print invasion data
  for (int i = 0; i < NUM_YEARS; i++) {
    printf("%d\t%d\t\t\t%d\n", data[i].year, data[i].num_invasions, data[i].num_successes);
  }
}

// Calculate probability of alien invasion
double calculate_probability(InvasionData* data) {
  // Calculate total number of invasions and successes
  int total_invasions = 0;
  int total_successes = 0;
  for (int i = 0; i < NUM_YEARS; i++) {
    total_invasions += data[i].num_invasions;
    total_successes += data[i].num_successes;
  }

  // Calculate probability of alien invasion
  double probability = (double)total_successes / (double)total_invasions;

  // Return probability
  return probability;
}