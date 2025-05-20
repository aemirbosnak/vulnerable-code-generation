//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// DNA bases
char bases[] = {'A', 'C', 'G', 'T'};

// Function to generate a random DNA sequence
char* generateSequence(int length) {
  // Allocate memory for the sequence
  char* sequence = (char*)malloc(length + 1);

  // Generate a random sequence of bases
  for (int i = 0; i < length; i++) {
    sequence[i] = bases[rand() % 4];
  }

  // Terminate the sequence with a null character
  sequence[length] = '\0';

  // Return the sequence
  return sequence;
}

// Function to simulate sequencing errors
char* simulateErrors(char* sequence, double errorRate) {
  // Allocate memory for the sequence with errors
  char* sequenceWithError = (char*)malloc(strlen(sequence) + 1);

  // Copy the original sequence into the sequence with errors
  strcpy(sequenceWithError, sequence);

  // Simulate sequencing errors
  for (int i = 0; i < strlen(sequence); i++) {
    // Generate a random number between 0.0 and 1.0
    double randomNumber = (double)rand() / (double)RAND_MAX;

    // If the random number is less than the error rate, then simulate an error
    if (randomNumber < errorRate) {
      // Change the base at the current position to a random base
      sequenceWithError[i] = bases[rand() % 4];
    }
  }

  // Terminate the sequence with a null character
  sequenceWithError[strlen(sequence)] = '\0';

  // Return the sequence with errors
  return sequenceWithError;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence of length 100
  char* sequence = generateSequence(100);

  // Simulate sequencing errors with an error rate of 0.01
  char* sequenceWithError = simulateErrors(sequence, 0.01);

  // Print the original sequence
  printf("Original sequence: %s\n", sequence);

  // Print the sequence with errors
  printf("Sequence with errors: %s\n", sequenceWithError);

  // Free the allocated memory
  free(sequence);
  free(sequenceWithError);

  return 0;
}