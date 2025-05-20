//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the DNA bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a DNA sequence
#define MAX_LENGTH 100

// Generate a random DNA sequence
char *generate_dna_sequence(int length) {
  // Allocate memory for the DNA sequence
  char *sequence = malloc(length + 1);

  // Initialize the random number generator
  srand(time(NULL));

  // Generate the DNA sequence
  for (int i = 0; i < length; i++) {
    // Generate a random number between 0 and 3
    int random_number = rand() % 4;

    // Convert the random number to a DNA base
    switch (random_number) {
      case 0:
        sequence[i] = A;
        break;
      case 1:
        sequence[i] = C;
        break;
      case 2:
        sequence[i] = G;
        break;
      case 3:
        sequence[i] = T;
        break;
    }
  }

  // Terminate the DNA sequence with a null character
  sequence[length] = '\0';

  // Return the DNA sequence
  return sequence;
}

// Print a DNA sequence
void print_dna_sequence(char *sequence) {
  // Print the DNA sequence
  printf("%s\n", sequence);
}

// Main function
int main() {
  // Generate a random DNA sequence
  char *sequence = generate_dna_sequence(MAX_LENGTH);

  // Print the DNA sequence
  print_dna_sequence(sequence);

  // Free the memory allocated for the DNA sequence
  free(sequence);

  return 0;
}