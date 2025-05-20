//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the number of sides for the dice
#define NUM_SIDES 6

// Define the number of dice to roll
#define NUM_DICE 2

// Define the function to roll a single die
int roll_die() {
  // Generate a random number between 1 and NUM_SIDES
  int roll = rand() % NUM_SIDES + 1;

  // Return the random number
  return roll;
}

// Define the function to roll multiple dice
int* roll_dice() {
  // Allocate memory for the array of dice rolls
  int* rolls = malloc(sizeof(int) * NUM_DICE);

  // Roll each die and store the result in the array
  for (int i = 0; i < NUM_DICE; i++) {
    rolls[i] = roll_die();
  }

  // Return the array of dice rolls
  return rolls;
}

// Define the function to print the dice rolls
void print_rolls(int* rolls) {
  // Print each die roll
  for (int i = 0; i < NUM_DICE; i++) {
    printf("Die %d: %d\n", i + 1, rolls[i]);
  }
}

// Define the function to play the game
void play_game() {
  // Seed the random number generator
  srand(time(NULL));

  // Roll the dice
  int* rolls = roll_dice();

  // Print the dice rolls
  print_rolls(rolls);

  // Calculate the sum of the dice rolls
  int sum = 0;
  for (int i = 0; i < NUM_DICE; i++) {
    sum += rolls[i];
  }

  // Print the sum of the dice rolls
  printf("Sum: %d\n", sum);

  // Free the memory allocated for the array of dice rolls
  free(rolls);
}

// Define the main function
int main() {
  // Play the game
  play_game();

  return 0;
}