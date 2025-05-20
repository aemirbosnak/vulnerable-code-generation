//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A Ken Thompson style C program to find the minimum number of coins
// required to make change for a given amount of money.

// The denominations of the coins we have available.
int denominations[] = {1, 5, 10, 25, 50, 100};
// The number of denominations we have.
int num_denominations = sizeof(denominations) / sizeof(int);

// Find the minimum number of coins required to make change for a given amount of money.
int make_change(int amount) {
  // Initialize the number of coins to 0.
  int num_coins = 0;

  // For each denomination, starting with the largest, see how many coins of that denomination
  // we can use to make change for the remaining amount.
  for (int i = num_denominations - 1; i >= 0; i--) {
    while (amount >= denominations[i]) {
      // Use a coin of this denomination.
      amount -= denominations[i];
      num_coins++;
    }
  }

  // Return the number of coins we used.
  return num_coins;
}

// Print the usage message and exit.
void usage(char *name) {
  fprintf(stderr, "Usage: %s amount\n", name);
  exit(1);
}

// Main program.
int main(int argc, char *argv[]) {
  // Check if the user specified the amount of money to make change for.
  if (argc != 2) {
    usage(argv[0]);
  }

  // Parse the amount of money from the command line.
  int amount = atoi(argv[1]);

  // Find the minimum number of coins required to make change for the given amount of money.
  int num_coins = make_change(amount);

  // Print the number of coins required.
  printf("%d\n", num_coins);

  return 0;
}