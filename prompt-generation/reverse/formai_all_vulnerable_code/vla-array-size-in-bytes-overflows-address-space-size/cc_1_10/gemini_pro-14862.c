//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of dice to roll and the number of sides per die
#define NUM_DICE 5
#define NUM_SIDES 6

// Function to roll a single die and return the result
int roll_die() {
  return rand() % NUM_SIDES + 1;
}

// Function to roll multiple dice and return the sum of the results
int roll_dice(int num_dice) {
  int sum = 0;
  for (int i = 0; i < num_dice; i++) {
    sum += roll_die();
  }
  return sum;
}

// Function to print the results of rolling a single die
void print_roll(int roll) {
  printf("You rolled a %d!\n", roll);
}

// Function to print the results of rolling multiple dice
void print_rolls(int num_dice, int rolls[]) {
  printf("You rolled %d dice and got the following results:\n", num_dice);
  for (int i = 0; i < num_dice; i++) {
    printf("%d ", rolls[i]);
  }
  printf("\n");
}

// Function to get the user's input for the number of dice to roll
int get_num_dice() {
  int num_dice;
  printf("How many dice do you want to roll? ");
  scanf("%d", &num_dice);
  return num_dice;
}

// Function to get the user's input for the number of sides per die
int get_num_sides() {
  int num_sides;
  printf("How many sides do you want each die to have? ");
  scanf("%d", &num_sides);
  return num_sides;
}

// Function to play the dice rolling game
void play_game() {
  // Get the user's input for the number of dice to roll and the number of sides per die
  int num_dice = get_num_dice();
  int num_sides = get_num_sides();

  // Roll the dice and store the results in an array
  int rolls[num_dice];
  for (int i = 0; i < num_dice; i++) {
    rolls[i] = roll_die();
  }

  // Print the results of the roll to the console
  print_rolls(num_dice, rolls);
}

// Main function to start the program
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the dice rolling game
  play_game();

  return 0;
}