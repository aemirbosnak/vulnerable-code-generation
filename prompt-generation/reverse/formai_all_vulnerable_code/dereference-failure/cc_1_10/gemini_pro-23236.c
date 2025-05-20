//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Nucleotide codes
#define A 0
#define C 1
#define G 2
#define T 3

// Error probabilities
#define P_SUBSTITUTION 0.01
#define P_INSERTION 0.001
#define P_DELETION 0.001

// Generate a random nucleotide code
int random_nucleotide() {
  int r = rand() % 4;
  return r;
}

// Generate a random sequence of nucleotides
char *random_sequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int nucleotide = random_nucleotide();
    switch (nucleotide) {
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

// Introduce errors into a sequence
char *introduce_errors(char *sequence, double p_substitution, double p_insertion,
                       double p_deletion) {
  int length = strlen(sequence);
  char *new_sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    double r = (double)rand() / RAND_MAX;
    if (r < p_substitution) {
      // Substitution error
      int nucleotide = random_nucleotide();
      while (nucleotide == sequence[i]) {
        nucleotide = random_nucleotide();
      }
      new_sequence[i] = nucleotide;
    } else if (r < p_substitution + p_insertion) {
      // Insertion error
      int nucleotide = random_nucleotide();
      new_sequence[i] = sequence[i];
      new_sequence[i + 1] = nucleotide;
      i++;
    } else if (r < p_substitution + p_insertion + p_deletion) {
      // Deletion error
      new_sequence[i] = sequence[i + 1];
      i++;
    } else {
      // No error
      new_sequence[i] = sequence[i];
    }
  }
  new_sequence[length] = '\0';
  return new_sequence;
}

// Print a sequence
void print_sequence(char *sequence) {
  printf("%s\n", sequence);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random sequence
  int length = 100;
  char *sequence = random_sequence(length);

  // Introduce errors into the sequence
  char *new_sequence = introduce_errors(sequence, P_SUBSTITUTION, P_INSERTION,
                                        P_DELETION);

  // Print the original and new sequences
  printf("Original sequence: ");
  print_sequence(sequence);
  printf("New sequence: ");
  print_sequence(new_sequence);

  // Free the allocated memory
  free(sequence);
  free(new_sequence);

  return 0;
}