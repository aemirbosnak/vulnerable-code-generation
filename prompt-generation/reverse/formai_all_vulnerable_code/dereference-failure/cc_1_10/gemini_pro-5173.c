//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of dice and sides
#define NUM_DICE 5
#define NUM_SIDES 6

// Define the minimum and maximum possible values
#define MIN_VALUE 1
#define MAX_VALUE NUM_DICE * NUM_SIDES

// Create a function to roll a single die
int roll_die() {
  // Generate a random number between 1 and NUM_SIDES
  int result = rand() % NUM_SIDES + 1;

  // Return the result
  return result;
}

// Create a function to roll multiple dice
int* roll_dice(int num_dice) {
  // Allocate memory for the array of results
  int* results = malloc(sizeof(int) * num_dice);

  // Roll each die and store the result in the array
  for (int i = 0; i < num_dice; i++) {
    results[i] = roll_die();
  }

  // Return the array of results
  return results;
}

// Create a function to print the results of rolling dice
void print_results(const int* results, int num_dice) {
  // Print the heading
  printf("Dice Roll Results:\n");

  // Print each result on a new line
  for (int i = 0; i < num_dice; i++) {
    printf("%d\n", results[i]);
  }

  // Print the total of the results
  int total = 0;
  for (int i = 0; i < num_dice; i++) {
    total += results[i];
  }
  printf("Total: %d\n", total);
}

// Create a function to get the minimum possible value
int get_min_value() {
  // Return the minimum possible value
  return MIN_VALUE;
}

// Create a function to get the maximum possible value
int get_max_value() {
  // Return the maximum possible value
  return MAX_VALUE;
}

// Create a function to get the average possible value
int get_avg_value() {
  // Return the average possible value
  return (MIN_VALUE + MAX_VALUE) / 2;
}

// Create a function to get the standard deviation of the possible values
double get_std_dev() {
  // Calculate the standard deviation
  double std_dev = (MAX_VALUE - MIN_VALUE) / 6;

  // Return the standard deviation
  return std_dev;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Roll the dice
  int* results = roll_dice(NUM_DICE);

  // Print the results
  print_results(results, NUM_DICE);

  // Free the memory allocated for the results array
  free(results);

  // Get the minimum possible value
  int min_value = get_min_value();

  // Get the maximum possible value
  int max_value = get_max_value();

  // Get the average possible value
  int avg_value = get_avg_value();

  // Get the standard deviation of the possible values
  double std_dev = get_std_dev();

  // Print the minimum, maximum, average, and standard deviation of the possible values
  printf("Minimum Possible Value: %d\n", min_value);
  printf("Maximum Possible Value: %d\n", max_value);
  printf("Average Possible Value: %d\n", avg_value);
  printf("Standard Deviation of Possible Values: %.2f\n", std_dev);

  return 0;
}