//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define DNA base pair probabilities
#define PROBAB_A 0.25
#define PROBAB_C 0.25
#define PROBAB_G 0.25
#define PROBAB_T 0.25

// Function to generate a random DNA base pair
char generate_base_pair() {
  double rand_num = (double)rand() / RAND_MAX;
  if (rand_num < PROBAB_A) {
    return 'A';
  } else if (rand_num < PROBAB_A + PROBAB_C) {
    return 'C';
  } else if (rand_num < PROBAB_A + PROBAB_C + PROBAB_G) {
    return 'G';
  } else {
    return 'T';
  }
}

// Function to generate a DNA sequence of a given length
char *generate_sequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    sequence[i] = generate_base_pair();
  }
  sequence[length] = '\0';
  return sequence;
}

// Function to print a DNA sequence
void print_sequence(char *sequence) {
  printf("%s\n", sequence);
}

// Main function
int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Generate a DNA sequence of length 100
  char *sequence = generate_sequence(100);

  // Print the DNA sequence
  print_sequence(sequence);

  // Free the allocated memory
  free(sequence);

  return 0;
}