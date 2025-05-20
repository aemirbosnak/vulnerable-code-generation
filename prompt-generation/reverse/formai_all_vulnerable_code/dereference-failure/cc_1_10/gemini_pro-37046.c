//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible dice sides
#define NUM_SIDES 6

// Define the maximum number of dice to roll
#define MAX_DICE 10

// Define the default number of dice to roll
#define DEFAULT_DICE 2

// Define the default number of sides per die
#define DEFAULT_SIDES NUM_SIDES

// Function to roll a single die
int roll_die(int sides) {
  return rand() % sides + 1;
}

// Function to roll multiple dice
int* roll_dice(int num_dice, int sides) {
  int* rolls = malloc(sizeof(int) * num_dice);
  for (int i = 0; i < num_dice; i++) {
    rolls[i] = roll_die(sides);
  }
  return rolls;
}

// Function to print the results of a dice roll
void print_rolls(int* rolls, int num_dice) {
  printf("You rolled: ");
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", rolls[i]);
  }
  printf("\n");
}

// Function to get the sum of a dice roll
int get_sum(int* rolls, int num_dice) {
  int sum = 0;
  for (int i = 0; i < num_dice; i++) {
    sum += rolls[i];
  }
  return sum;
}

// Function to get the average of a dice roll
double get_average(int* rolls, int num_dice) {
  double average = (double)get_sum(rolls, num_dice) / num_dice;
  return average;
}

// Function to get the maximum value of a dice roll
int get_max(int* rolls, int num_dice) {
  int max = rolls[0];
  for (int i = 1; i < num_dice; i++) {
    if (rolls[i] > max) {
      max = rolls[i];
    }
  }
  return max;
}

// Function to get the minimum value of a dice roll
int get_min(int* rolls, int num_dice) {
  int min = rolls[0];
  for (int i = 1; i < num_dice; i++) {
    if (rolls[i] < min) {
      min = rolls[i];
    }
  }
  return min;
}

// Function to get the standard deviation of a dice roll
double get_standard_deviation(int* rolls, int num_dice) {
  double average = get_average(rolls, num_dice);
  double sum_of_squared_differences = 0;
  for (int i = 0; i < num_dice; i++) {
    sum_of_squared_differences += pow(rolls[i] - average, 2);
  }
  double variance = sum_of_squared_differences / (num_dice - 1);
  double standard_deviation = sqrt(variance);
  return standard_deviation;
}

// Main function
int main(int argc, char** argv) {
  // Set the random seed
  srand(time(NULL));

  // Parse the command line arguments
  int num_dice = DEFAULT_DICE;
  int sides = DEFAULT_SIDES;
  if (argc > 1) {
    num_dice = atoi(argv[1]);
  }
  if (argc > 2) {
    sides = atoi(argv[2]);
  }

  // Roll the dice
  int* rolls = roll_dice(num_dice, sides);

  // Print the results of the dice roll
  print_rolls(rolls, num_dice);

  // Get the sum of the dice roll
  int sum = get_sum(rolls, num_dice);
  printf("The sum of the dice roll is: %d\n", sum);

  // Get the average of the dice roll
  double average = get_average(rolls, num_dice);
  printf("The average of the dice roll is: %.2f\n", average);

  // Get the maximum value of the dice roll
  int max = get_max(rolls, num_dice);
  printf("The maximum value of the dice roll is: %d\n", max);

  // Get the minimum value of the dice roll
  int min = get_min(rolls, num_dice);
  printf("The minimum value of the dice roll is: %d\n", min);

  // Get the standard deviation of the dice roll
  double standard_deviation = get_standard_deviation(rolls, num_dice);
  printf("The standard deviation of the dice roll is: %.2f\n", standard_deviation);

  // Free the memory allocated for the rolls
  free(rolls);

  return 0;
}