//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a six-sided die
int roll_die() {
  // Get a random number between 1 and 6
  int result = rand() % 6 + 1;

  // Return the result
  return result;
}

// Function to simulate rolling multiple dice
int* roll_dice(int num_dice) {
  // Allocate memory for the results
  int* results = malloc(sizeof(int) * num_dice);

  // Roll each die and store the result
  for (int i = 0; i < num_dice; i++) {
    results[i] = roll_die();
  }

  // Return the results
  return results;
}

// Function to print the results of rolling dice
void print_results(int* results, int num_dice) {
  // Print the results
  printf("Rolled %d dice: ", num_dice);
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", results[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Get the number of dice to roll
  int num_dice;
  printf("How many dice do you want to roll? ");
  scanf("%d", &num_dice);

  // Roll the dice
  int* results = roll_dice(num_dice);

  // Print the results
  print_results(results, num_dice);

  // Free the memory allocated for the results
  free(results);

  return 0;
}