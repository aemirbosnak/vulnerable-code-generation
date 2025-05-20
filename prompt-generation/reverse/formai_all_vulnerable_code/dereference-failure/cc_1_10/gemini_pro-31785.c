//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define our DNA bases
#define A "A"
#define C "C"
#define G "G"
#define T "T"

// Generate a random DNA sequence of a specified length
char* generateSequence(int length) {
  // Initialize our random number generator
  srand(time(NULL));

  // Allocate memory for our sequence
  char* sequence = malloc(length + 1);
  sequence[length] = '\0'; // Null-terminate the string

  // Generate each nucleotide randomly
  for (int i = 0; i < length; i++) {
    int randomIndex = rand() % 4;
    switch (randomIndex) {
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

  // Return the generated sequence
  return sequence;
}

// Perform sequencing on a DNA sequence
char* sequence(char* sequence) {
  // Simulate the sequencing process
  char* sequencedSequence = malloc(strlen(sequence) + 1);
  sequencedSequence[strlen(sequence)] = '\0'; // Null-terminate the string

  for (int i = 0; i < strlen(sequence); i++) {
    // Simulate sequencing errors with a 1% probability
    if (rand() % 100 < 1) {
      int randomIndex = rand() % 4;
      switch (randomIndex) {
        case 0:
          sequencedSequence[i] = A;
          break;
        case 1:
          sequencedSequence[i] = C;
          break;
        case 2:
          sequencedSequence[i] = G;
          break;
        case 3:
          sequencedSequence[i] = T;
          break;
      }
    } else {
      sequencedSequence[i] = sequence[i];
    }
  }

  // Return the sequenced sequence
  return sequencedSequence;
}

// Print the original and sequenced sequences
void printSequences(char* originalSequence, char* sequencedSequence) {
  printf("Original sequence: %s\n", originalSequence);
  printf("Sequenced sequence: %s\n", sequencedSequence);
}

int main() {
  // Generate a random DNA sequence of 100 nucleotides
  char* originalSequence = generateSequence(100);

  // Perform sequencing on the DNA sequence
  char* sequencedSequence = sequence(originalSequence);

  // Print the original and sequenced sequences
  printSequences(originalSequence, sequencedSequence);

  // Free the allocated memory
  free(originalSequence);
  free(sequencedSequence);

  return 0;
}