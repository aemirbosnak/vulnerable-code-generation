//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of dice and the number of sides per die
#define NUM_DICE 5
#define NUM_SIDES 6

// Function to roll a single die
int roll_die() {
  // Generate a random number between 1 and NUM_SIDES
  int roll = rand() % NUM_SIDES + 1;
  return roll;
}

// Function to roll multiple dice
int* roll_dice(int num_dice) {
  // Allocate memory for the array of dice rolls
  int* rolls = malloc(sizeof(int) * num_dice);

  // Roll each die and store the result in the array
  for (int i = 0; i < num_dice; i++) {
    rolls[i] = roll_die();
  }

  // Return the array of dice rolls
  return rolls;
}

// Function to print the results of the dice roll
void print_dice_rolls(int* rolls, int num_dice) {
  // Print the header
  printf("Dice Rolls:\n");

  // Print each die roll
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", rolls[i]);
  }

  // Print the newline
  printf("\n");
}

// Function to free the memory allocated for the array of dice rolls
void free_dice_rolls(int* rolls) {
  free(rolls);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Roll the dice
  int* rolls = roll_dice(NUM_DICE);

  // Print the results of the dice roll
  print_dice_rolls(rolls, NUM_DICE);

  // Free the memory allocated for the array of dice rolls
  free_dice_rolls(rolls);

  return 0;
}