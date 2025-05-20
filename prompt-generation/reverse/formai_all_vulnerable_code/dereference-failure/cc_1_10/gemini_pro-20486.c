//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_NUM_BASES 4
#define MAX_NUM_ERRORS 100

// Function to generate a random DNA sequence
char *generate_sequence(int length) {
  // Create an array to store the sequence
  char *sequence = (char *)malloc(length * sizeof(char));

  // Initialize the random number generator
  srand(time(NULL));

  // Generate each base in the sequence
  for (int i = 0; i < length; i++) {
    // Generate a random number between 0 and 3
    int base = rand() % MAX_NUM_BASES;

    // Convert the random number to a base
    switch (base) {
      case 0:
        sequence[i] = 'A';
        break;
      case 1:
        sequence[i] = 'C';
        break;
      case 2:
        sequence[i] = 'G';
        break;
      case 3:
        sequence[i] = 'T';
        break;
    }
  }

  // Return the sequence
  return sequence;
}

// Function to introduce errors into a DNA sequence
char *introduce_errors(char *sequence, int num_errors) {
  // Create an array to store the sequence with errors
  char *sequence_with_errors = (char *)malloc(strlen(sequence) * sizeof(char));

  // Copy the original sequence into the new array
  strcpy(sequence_with_errors, sequence);

  // Initialize the random number generator
  srand(time(NULL));

  // Introduce errors into the sequence
  for (int i = 0; i < num_errors; i++) {
    // Generate a random number between 0 and the length of the sequence
    int position = rand() % strlen(sequence);

    // Generate a random number between 0 and 3
    int base = rand() % MAX_NUM_BASES;

    // Convert the random number to a base
    switch (base) {
      case 0:
        sequence_with_errors[position] = 'A';
        break;
      case 1:
        sequence_with_errors[position] = 'C';
        break;
      case 2:
        sequence_with_errors[position] = 'G';
        break;
      case 3:
        sequence_with_errors[position] = 'T';
        break;
    }
  }

  // Return the sequence with errors
  return sequence_with_errors;
}

// Function to print a DNA sequence
void print_sequence(char *sequence) {
  // Print the sequence to the console
  printf("%s\n", sequence);
}

// Main function
int main() {
  // Generate a random DNA sequence
  char *sequence = generate_sequence(MAX_SEQUENCE_LENGTH);

  // Introduce errors into the sequence
  char *sequence_with_errors = introduce_errors(sequence, MAX_NUM_ERRORS);

  // Print the original sequence
  printf("Original sequence:\n");
  print_sequence(sequence);

  // Print the sequence with errors
  printf("Sequence with errors:\n");
  print_sequence(sequence_with_errors);

  // Free the memory allocated for the sequences
  free(sequence);
  free(sequence_with_errors);

  return 0;
}