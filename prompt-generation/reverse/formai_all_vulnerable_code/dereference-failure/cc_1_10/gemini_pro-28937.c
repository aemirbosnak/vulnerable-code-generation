//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of dice to roll and the number of sides on each die
#define NUM_DICE 5
#define NUM_SIDES 6

// Define the function to roll a die
int roll_die(void) {
  return rand() % NUM_SIDES + 1;
}

// Define the function to roll multiple dice
int* roll_dice(int num_dice) {
  int* rolls = malloc(sizeof(int) * num_dice);
  for (int i = 0; i < num_dice; i++) {
    rolls[i] = roll_die();
  }
  return rolls;
}

// Define the function to print the results of rolling the dice
void print_results(int* rolls, int num_dice) {
  printf("You rolled the following dice:\n");
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", rolls[i]);
  }
  printf("\n");
}

// Define the main function
int main(int argc, char** argv) {
  // Check if the user entered the correct number of arguments
  if (argc != 2) {
    printf("Usage: %s <number of dice to roll>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Convert the user's input to an integer
  int num_dice = atoi(argv[1]);

  // Check if the user entered a valid number of dice
  if (num_dice <= 0) {
    printf("Error: The number of dice must be greater than 0\n");
    return EXIT_FAILURE;
  }

  // Seed the random number generator
  srand(time(NULL));

  // Roll the dice
  int* rolls = roll_dice(num_dice);

  // Print the results of rolling the dice
  print_results(rolls, num_dice);

  // Free the memory allocated for the rolls array
  free(rolls);

  return EXIT_SUCCESS;
}