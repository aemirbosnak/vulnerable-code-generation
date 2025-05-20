//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides for the dice.
#define NUM_SIDES 6

// Define the number of dice to roll.
#define NUM_DICE 5

// Function to roll a single die.
int roll_die() {
  // Generate a random number between 1 and NUM_SIDES.
  int roll = rand() % NUM_SIDES + 1;

  // Return the roll.
  return roll;
}

// Function to roll multiple dice.
int* roll_dice(int num_dice) {
  // Allocate memory for the array of rolls.
  int* rolls = malloc(sizeof(int) * num_dice);

  // Roll each die and store the result in the array.
  for (int i = 0; i < num_dice; i++) {
    rolls[i] = roll_die();
  }

  // Return the array of rolls.
  return rolls;
}

// Function to print the results of a dice roll.
void print_rolls(int* rolls, int num_dice) {
  // Print the rolls.
  for (int i = 0; i < num_dice; i++) {
    printf("Die %d: %d\n", i + 1, rolls[i]);
  }

  // Print the total roll.
  int total = 0;
  for (int i = 0; i < num_dice; i++) {
    total += rolls[i];
  }
  printf("Total: %d\n", total);
}

// Main function.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Roll the dice.
  int* rolls = roll_dice(NUM_DICE);

  // Print the results of the dice roll.
  print_rolls(rolls, NUM_DICE);

  // Free the memory allocated for the array of rolls.
  free(rolls);

  return 0;
}