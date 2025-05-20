//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of dice and the number of sides per die
#define NUM_DICE 5
#define NUM_SIDES 6

// Function to roll a single die
int roll_die() {
  return rand() % NUM_SIDES + 1;
}

// Function to roll multiple dice
int* roll_dice(int num_dice) {
  int* results = malloc(sizeof(int) * num_dice);

  for (int i = 0; i < num_dice; i++) {
    results[i] = roll_die();
  }

  return results;
}

// Function to print the results of rolling dice
void print_results(int* results, int num_dice) {
  printf("You rolled: ");
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", results[i]);
  }
  printf("\n");
}

// Function to get the sum of the results of rolling dice
int get_sum(int* results, int num_dice) {
  int sum = 0;
  for (int i = 0; i < num_dice; i++) {
    sum += results[i];
  }
  return sum;
}

// Function to play a game of Yahtzee
void play_yahtzee() {
  // Roll the dice three times
  int* rolls[3];
  for (int i = 0; i < 3; i++) {
    rolls[i] = roll_dice(NUM_DICE);
  }

  // Print the results of each roll
  for (int i = 0; i < 3; i++) {
    printf("Roll %d: ", i + 1);
    print_results(rolls[i], NUM_DICE);
  }

  // Get the sum of the results of each roll
  int sums[3];
  for (int i = 0; i < 3; i++) {
    sums[i] = get_sum(rolls[i], NUM_DICE);
  }

  // Find the highest sum
  int highest_sum = sums[0];
  for (int i = 1; i < 3; i++) {
    if (sums[i] > highest_sum) {
      highest_sum = sums[i];
    }
  }

  // Print the highest sum
  printf("Highest sum: %d\n", highest_sum);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play a game of Yahtzee
  play_yahtzee();

  return 0;
}