//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define NUM_BASES 4
#define BASE_A 'A'
#define BASE_C 'C'
#define BASE_G 'G'
#define BASE_T 'T'

// Function prototypes
void generate_sequence(char *sequence, int length);
void print_sequence(char *sequence, int length);

// Main function
int main(int argc, char *argv[]) {
  // Check for correct number of arguments
  if (argc != 2) {
    printf("Usage: %s <length>\n", argv[0]);
    return 1;
  }

  // Get the length of the sequence from the command line
  int length = atoi(argv[1]);

  // Allocate memory for the sequence
  char *sequence = malloc(length + 1);

  // Generate the sequence
  generate_sequence(sequence, length);

  // Print the sequence
  print_sequence(sequence, length);

  // Free the memory allocated for the sequence
  free(sequence);

  return 0;
}

// Function to generate a random DNA sequence
void generate_sequence(char *sequence, int length) {
  // Set the seed for the random number generator
  srand(time(NULL));

  // Generate each base in the sequence
  for (int i = 0; i < length; i++) {
    // Generate a random number between 0 and 3
    int base = rand() % NUM_BASES;

    // Convert the random number to a base character
    switch (base) {
      case 0:
        sequence[i] = BASE_A;
        break;
      case 1:
        sequence[i] = BASE_C;
        break;
      case 2:
        sequence[i] = BASE_G;
        break;
      case 3:
        sequence[i] = BASE_T;
        break;
    }
  }

  // Terminate the string with a null character
  sequence[length] = '\0';
}

// Function to print a DNA sequence
void print_sequence(char *sequence, int length) {
  // Print the sequence to the console
  printf("%s\n", sequence);
}