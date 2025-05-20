//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int roll_die() {
  // Initialize random number generator
  srand(time(NULL));

  // Generate a random number from 1 to 6
  int roll = rand() % 6 + 1;

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

  return rolls;
}

// Function to print the results of rolling dice
void print_rolls(int* rolls, int num_dice) {
  // Print the results
  printf("You rolled: ");
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", rolls[i]);
  }
  printf("\n");
}

// Function to calculate the sum of the dice rolls
int calculate_sum(int* rolls, int num_dice) {
  // Initialize the sum variable
  int sum = 0;

  // Calculate the sum of the dice rolls
  for (int i = 0; i < num_dice; i++) {
    sum += rolls[i];
  }

  return sum;
}

// Function to play the dice rolling game
void play_game() {
  // Get the number of dice to roll from the user
  int num_dice;
  printf("How many dice do you want to roll? ");
  scanf("%d", &num_dice);

  // Roll the dice and print the results
  int* rolls = roll_dice(num_dice);
  print_rolls(rolls, num_dice);

  // Calculate the sum of the dice rolls and print the result
  int sum = calculate_sum(rolls, num_dice);
  printf("The sum of the dice rolls is: %d\n", sum);

  // Free the memory allocated for the array of dice rolls
  free(rolls);
}

// Main function to run the program
int main() {
  // Play the dice rolling game
  play_game();

  return 0;
}