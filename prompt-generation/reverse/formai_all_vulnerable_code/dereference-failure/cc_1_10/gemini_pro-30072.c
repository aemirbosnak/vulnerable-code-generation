//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random base
char random_base() {
  // Generate a random number between 0 and 3
  int r = rand() % 4;

  // Return the corresponding base
  switch (r) {
    case 0:
      return 'A';
    case 1:
      return 'C';
    case 2:
      return 'G';
    case 3:
      return 'T';
  }
}

// Function to generate a random sequence of bases
char *random_sequence(int length) {
  // Allocate memory for the sequence
  char *sequence = malloc(length + 1);

  // Generate the sequence
  for (int i = 0; i < length; i++) {
    sequence[i] = random_base();
  }

  // Terminate the sequence with a null character
  sequence[length] = '\0';

  // Return the sequence
  return sequence;
}

// Function to main
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random sequence of 100 bases
  char *sequence = random_sequence(100);

  // Print the sequence
  printf("%s\n", sequence);

  // Free the memory allocated for the sequence
  free(sequence);

  return 0;
}