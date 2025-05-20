//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Sherlock Holmes
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a DNA sequence
#define MAX_SEQUENCE_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 100

// Define the maximum length of a read
#define MAX_READ_LENGTH 50

// Define the probability of an error in a read
#define ERROR_PROBABILITY 0.01

// Define the seed for the random number generator
#define RANDOM_SEED 12345

// Generate a random DNA sequence
char *generate_sequence(int length) {
  // Allocate memory for the sequence
  char *sequence = malloc(length + 1);

  // Initialize the random number generator
  srand(RANDOM_SEED);

  // Generate the sequence
  for (int i = 0; i < length; i++) {
    switch (rand() % 4) {
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

  // Terminate the sequence with a null character
  sequence[length] = '\0';

  // Return the sequence
  return sequence;
}

// Generate a random read from a DNA sequence
char *generate_read(char *sequence, int length) {
  // Allocate memory for the read
  char *read = malloc(length + 1);

  // Initialize the random number generator
  srand(RANDOM_SEED);

  // Generate the read
  for (int i = 0; i < length; i++) {
    // Get the corresponding character from the sequence
    char c = sequence[rand() % length];

    // Introduce an error with probability ERROR_PROBABILITY
    if (rand() < ERROR_PROBABILITY * RAND_MAX) {
      switch (c) {
        case A:
          c = C;
          break;
        case C:
          c = G;
          break;
        case G:
          c = T;
          break;
        case T:
          c = A;
          break;
      }
    }

    // Store the character in the read
    read[i] = c;
  }

  // Terminate the read with a null character
  read[length] = '\0';

  // Return the read
  return read;
}

// Print a DNA sequence
void print_sequence(char *sequence) {
  printf("%s\n", sequence);
}

// Print a read
void print_read(char *read) {
  printf("%s\n", read);
}

// Main function
int main() {
  // Generate a random DNA sequence
  char *sequence = generate_sequence(MAX_SEQUENCE_LENGTH);

  // Print the sequence
  print_sequence(sequence);

  // Generate NUM_READS reads from the sequence
  for (int i = 0; i < NUM_READS; i++) {
    // Generate a random read
    char *read = generate_read(sequence, MAX_READ_LENGTH);

    // Print the read
    print_read(read);

    // Free the memory allocated for the read
    free(read);
  }

  // Free the memory allocated for the sequence
  free(sequence);

  return 0;
}