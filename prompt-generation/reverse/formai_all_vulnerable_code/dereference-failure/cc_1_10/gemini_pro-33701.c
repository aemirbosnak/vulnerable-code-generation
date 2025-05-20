//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// These are the four DNA bases
#define A 0
#define C 1
#define G 2
#define T 3

// This is the length of the genome we will simulate
#define GENOME_LENGTH 10000

// This is the probability of a mutation occurring
#define MUTATION_PROBABILITY 0.001

// This function generates a random DNA sequence
char *generate_random_sequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int base = rand() % 4;
    switch (base) {
      case A:
        sequence[i] = 'A';
        break;
      case C:
        sequence[i] = 'C';
        break;
      case G:
        sequence[i] = 'G';
        break;
      case T:
        sequence[i] = 'T';
        break;
    }
  }
  sequence[length] = '\0';
  return sequence;
}

// This function simulates the mutation of a DNA sequence
char *mutate_sequence(char *sequence, double mutation_probability) {
  char *new_sequence = malloc(GENOME_LENGTH + 1);
  for (int i = 0; i < GENOME_LENGTH; i++) {
    double random_number = (double)rand() / (double)RAND_MAX;
    if (random_number < mutation_probability) {
      int base = rand() % 4;
      switch (base) {
        case A:
          new_sequence[i] = 'A';
          break;
        case C:
          new_sequence[i] = 'C';
          break;
        case G:
          new_sequence[i] = 'G';
          break;
        case T:
          new_sequence[i] = 'T';
          break;
      }
    } else {
      new_sequence[i] = sequence[i];
    }
  }
  new_sequence[GENOME_LENGTH] = '\0';
  return new_sequence;
}

// This function prints the DNA sequence to the console
void print_sequence(char *sequence) {
  for (int i = 0; i < GENOME_LENGTH; i++) {
    printf("%c", sequence[i]);
  }
  printf("\n");
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence
  char *sequence = generate_random_sequence(GENOME_LENGTH);

  // Simulate the mutation of the DNA sequence
  char *new_sequence = mutate_sequence(sequence, MUTATION_PROBABILITY);

  // Print the original DNA sequence
  printf("Original sequence:\n");
  print_sequence(sequence);

  // Print the mutated DNA sequence
  printf("\nMutated sequence:\n");
  print_sequence(new_sequence);

  // Free the memory allocated for the DNA sequences
  free(sequence);
  free(new_sequence);

  return 0;
}