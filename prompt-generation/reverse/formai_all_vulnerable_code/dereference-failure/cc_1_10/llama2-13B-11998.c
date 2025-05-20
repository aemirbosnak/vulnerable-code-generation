//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: irregular
// This program is like a box of chocolates - you never know what you're gonna get!
// But hey, at least it's not as messy as a real box of chocolates... right? 🍫😜

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INPUT_LEN 1024
#define MAX_CHOCOLATES 10

// Function to generate a random number between 1 and 10
int get_random_num() {
  return (rand() % 10) + 1;
}

// Function to print a chocolate's name and weight
void print_chocolate(char *name, int weight) {
  printf("%s (%d grams)\n", name, weight);
}

// Function to print a list of chocolates
void print_chocolates(char **names, int *weights, int num_chocolates) {
  int i;

  for (i = 0; i < num_chocolates; i++) {
    printf("%d. %s (%d grams)\n", i + 1, names[i], weights[i]);
  }
}

int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Create an array of chocolate names and weights
  char **names = malloc(MAX_CHOCOLATES * sizeof(char *));
  int *weights = malloc(MAX_CHOCOLATES * sizeof(int));

  for (int i = 0; i < MAX_CHOCOLATES; i++) {
    names[i] = malloc(MAX_INPUT_LEN * sizeof(char));
    weights[i] = get_random_num();

    // Generate a random chocolate name
    snprintf(names[i], MAX_INPUT_LEN, "Chocolate %d", i + 1);
  }

  // Print the list of chocolates
  print_chocolates(names, weights, MAX_CHOCOLATES);

  // Free memory
  for (int i = 0; i < MAX_CHOCOLATES; i++) {
    free(names[i]);
  }
  free(names);
  free(weights);

  return 0;
}