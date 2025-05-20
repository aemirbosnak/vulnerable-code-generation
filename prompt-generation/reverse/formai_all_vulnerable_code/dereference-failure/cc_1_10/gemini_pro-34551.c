//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides for the dice
#define NUM_SIDES 6

// Define the number of dice to roll
#define NUM_DICE 5

// Define the maximum number of rolls
#define MAX_ROLLS 100

// Function to roll a single die
int roll_die() {
  // Generate a random number between 1 and NUM_SIDES
  return rand() % NUM_SIDES + 1;
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

// Function to print the results of a dice roll
void print_roll(int* rolls, int num_dice) {
  // Print the results of each die roll
  printf("Dice rolls: ");
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", rolls[i]);
  }
  printf("\n");
}

// Function to calculate the sum of a dice roll
int sum_roll(int* rolls, int num_dice) {
  // Initialize the sum to 0
  int sum = 0;

  // Add the results of each die roll to the sum
  for (int i = 0; i < num_dice; i++) {
    sum += rolls[i];
  }

  // Return the sum of the dice rolls
  return sum;
}

// Function to simulate multiple rolls of the dice
void simulate_rolls(int num_dice, int num_rolls) {
  // Initialize the total sum of all rolls to 0
  int total_sum = 0;

  // Roll the dice num_rolls times
  for (int i = 0; i < num_rolls; i++) {
    // Roll the dice and store the results in an array
    int* rolls = roll_dice(num_dice);

    // Print the results of the dice roll
    print_roll(rolls, num_dice);

    // Calculate the sum of the dice roll and add it to the total sum
    total_sum += sum_roll(rolls, num_dice);

    // Free the memory allocated for the array of dice rolls
    free(rolls);
  }

  // Calculate the average sum of all rolls
  double average_sum = (double)total_sum / num_rolls;

  // Print the average sum of all rolls
  printf("Average sum of all rolls: %.2f\n", average_sum);
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Simulate multiple rolls of the dice
  simulate_rolls(NUM_DICE, MAX_ROLLS);

  return 0;
}