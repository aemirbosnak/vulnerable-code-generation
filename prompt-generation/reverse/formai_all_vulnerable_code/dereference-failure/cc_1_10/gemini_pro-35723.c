//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the DNA bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a DNA sequence
#define MAX_SEQ_LEN 1000

// Define the probability of each base occurring in a random sequence
#define PROB_A 0.25
#define PROB_C 0.25
#define PROB_G 0.25
#define PROB_T 0.25

// Generate a random DNA sequence of the given length
char *generate_random_dna_sequence(int length) {
  // Allocate memory for the sequence
  char *sequence = malloc(length + 1);

  // Generate a random number for each base in the sequence
  for (int i = 0; i < length; i++) {
    double r = (double)rand() / RAND_MAX;
    if (r < PROB_A) {
      sequence[i] = A;
    } else if (r < PROB_A + PROB_C) {
      sequence[i] = C;
    } else if (r < PROB_A + PROB_C + PROB_G) {
      sequence[i] = G;
    } else {
      sequence[i] = T;
    }
  }

  // Terminate the sequence with a null character
  sequence[length] = '\0';

  // Return the sequence
  return sequence;
}

// Print the DNA sequence to the console
void print_dna_sequence(char *sequence) {
  printf("%s\n", sequence);
}

// Free the memory allocated for the DNA sequence
void free_dna_sequence(char *sequence) {
  free(sequence);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random DNA sequence of length 100
  char *sequence = generate_random_dna_sequence(100);

  // Print the DNA sequence to the console
  print_dna_sequence(sequence);

  // Free the memory allocated for the DNA sequence
  free_dna_sequence(sequence);

  return 0;
}