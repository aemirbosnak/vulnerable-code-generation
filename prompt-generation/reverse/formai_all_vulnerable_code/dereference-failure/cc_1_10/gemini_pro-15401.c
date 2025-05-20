//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Linus Torvalds
// Linus Torvalds' C Genome Sequencing Simulator

// Header includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define BASE_COUNT 4
#define MAX_SEQUENCE_LENGTH 1000000

// Function prototypes
char *generate_random_sequence(int length);
void print_sequence(char *sequence);

// Main function
int main(int argc, char *argv[]) {
  // Check if the user provided a sequence length
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <sequence length>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the sequence length from the user
  int length = atoi(argv[1]);

  // Check if the sequence length is valid
  if (length <= 0 || length > MAX_SEQUENCE_LENGTH) {
    fprintf(stderr, "Error: Invalid sequence length\n");
    return EXIT_FAILURE;
  }

  // Generate a random sequence
  char *sequence = generate_random_sequence(length);

  // Print the sequence
  print_sequence(sequence);

  // Free the sequence
  free(sequence);

  return EXIT_SUCCESS;
}

// Function to generate a random sequence
char *generate_random_sequence(int length) {
  // Allocate memory for the sequence
  char *sequence = malloc(length + 1);

  // Seed the random number generator
  srand(time(NULL));

  // Generate the sequence
  for (int i = 0; i < length; i++) {
    sequence[i] = "ACGT"[rand() % BASE_COUNT];
  }

  // Terminate the sequence with a null character
  sequence[length] = '\0';

  // Return the sequence
  return sequence;
}

// Function to print a sequence
void print_sequence(char *sequence) {
  // Print the sequence to the console
  printf("%s\n", sequence);
}