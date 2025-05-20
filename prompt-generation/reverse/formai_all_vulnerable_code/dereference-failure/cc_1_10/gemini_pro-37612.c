//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: light-weight
// C Genome Sequencing Simulator Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Nucleotide types
#define A 0
#define C 1
#define G 2
#define T 3

// Simulated sequencing technology parameters
#define READ_LENGTH 100
#define ERROR_RATE 0.01

// Function to generate a random nucleotide sequence
char *generate_sequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int nucleotide = rand() % 4;
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

// Function to simulate sequencing errors
char *simulate_errors(char *sequence) {
  int length = strlen(sequence);
  char *sequenced_sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    if ((double)rand() / RAND_MAX < ERROR_RATE) {
      int error_nucleotide = rand() % 4;
      while (error_nucleotide == sequence[i]) {
        error_nucleotide = rand() % 4;
      }
      sequenced_sequence[i] = error_nucleotide;
    } else {
      sequenced_sequence[i] = sequence[i];
    }
  }
  sequenced_sequence[length] = '\0';
  return sequenced_sequence;
}

// Function to print a sequence
void print_sequence(char *sequence) {
  printf("%s\n", sequence);
}

// Main function
int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Generate a random DNA sequence
  char *sequence = generate_sequence(1000);

  // Simulate sequencing errors
  char *sequenced_sequence = simulate_errors(sequence);

  // Print the original sequence
  printf("Original sequence:\n");
  print_sequence(sequence);

  // Print the sequenced sequence
  printf("\nSequenced sequence:\n");
  print_sequence(sequenced_sequence);

  // Free allocated memory
  free(sequence);
  free(sequenced_sequence);

  return 0;
}