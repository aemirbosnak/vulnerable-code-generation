//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single die
int rollDie(int numSides) {
  // Get a random number between 1 and numSides
  int randomNumber = rand() % numSides + 1;

  return randomNumber;
}

// Function to roll multiple dice
int* rollDice(int numDice, int numSides) {
  // Allocate memory for the array of dice rolls
  int* diceRolls = malloc(sizeof(int) * numDice);

  // Roll each die and store the result in the array
  for (int i = 0; i < numDice; i++) {
    diceRolls[i] = rollDie(numSides);
  }

  return diceRolls;
}

// Function to print the results of rolling dice
void printDiceRolls(int* diceRolls, int numDice) {
  // Print the header
  printf("Dice Rolls:\n");

  // Print each die roll
  for (int i = 0; i < numDice; i++) {
    printf("%d ", diceRolls[i]);
  }

  // Print a newline
  printf("\n");
}

// Function to free the memory allocated for the dice rolls
void freeDiceRolls(int* diceRolls) {
  // Free the memory
  free(diceRolls);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Get the number of dice to roll
  int numDice;
  printf("How many dice do you want to roll? ");
  scanf("%d", &numDice);

  // Get the number of sides on each die
  int numSides;
  printf("How many sides should each die have? ");
  scanf("%d", &numSides);

  // Roll the dice
  int* diceRolls = rollDice(numDice, numSides);

  // Print the results
  printDiceRolls(diceRolls, numDice);

  // Free the memory
  freeDiceRolls(diceRolls);

  return 0;
}