//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Nucleotide types
#define A 0
#define C 1
#define G 2
#define T 3

// Error rates
#define ERROR_RATE_SUBSTITUTION 0.01
#define ERROR_RATE_INSERTION 0.001
#define ERROR_RATE_DELETION 0.001

// Random number generator
#define RAND(min, max) ((rand() % (max - min + 1)) + min)

// Function to generate a random nucleotide
int random_nucleotide() {
  int nucleotide = RAND(0, 3);
  return nucleotide;
}

// Function to generate a random error
int random_error() {
  int error = RAND(0, 2);
  return error;
}

// Function to generate a random sequence of nucleotides
char *generate_sequence(int length) {
  char *sequence = malloc(sizeof(char) * (length + 1));
  for (int i = 0; i < length; i++) {
    int nucleotide = random_nucleotide();
    sequence[i] = nucleotide;
  }
  sequence[length] = '\0';
  return sequence;
}

// Function to introduce errors into a sequence
char *introduce_errors(char *sequence) {
  int length = strlen(sequence);
  for (int i = 0; i < length; i++) {
    int error = random_error();
    switch (error) {
      case 0:  // Substitution
        sequence[i] = random_nucleotide();
        break;
      case 1:  // Insertion
        sequence = realloc(sequence, sizeof(char) * (length + 2));
        for (int j = length + 1; j > i + 1; j--) {
          sequence[j] = sequence[j - 1];
        }
        sequence[i + 1] = random_nucleotide();
        length++;
        break;
      case 2:  // Deletion
        for (int j = i + 1; j < length; j++) {
          sequence[j - 1] = sequence[j];
        }
        length--;
        break;
    }
  }
  return sequence;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random sequence of nucleotides
  char *sequence = generate_sequence(100);

  // Introduce errors into the sequence
  char *error_sequence = introduce_errors(sequence);

  // Print the original sequence
  printf("Original sequence:\n%s\n", sequence);

  // Print the error-introduced sequence
  printf("Error-introduced sequence:\n%s\n", error_sequence);

  // Free the allocated memory
  free(sequence);
  free(error_sequence);

  return 0;
}