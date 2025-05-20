//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define NUM_BASES 4
#define BASE_A 'A'
#define BASE_C 'C'
#define BASE_G 'G'
#define BASE_T 'T'

// Function to generate a random base
char generate_base() {
  int base_index = rand() % NUM_BASES;
  switch (base_index) {
    case 0:
      return BASE_A;
    case 1:
      return BASE_C;
    case 2:
      return BASE_G;
    case 3:
      return BASE_T;
    default:
      return '\0';
  }
}

// Function to generate a random sequence of bases
char *generate_sequence(int length) {
  char *sequence = malloc(length);
  for (int i = 0; i < length; i++) {
    sequence[i] = generate_base();
  }
  return sequence;
}

// Function to print a sequence of bases
void print_sequence(char *sequence, int length) {
  for (int i = 0; i < length; i++) {
    printf("%c", sequence[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Generate a random sequence of 100 bases
  char *sequence = generate_sequence(100);

  // Print the sequence
  printf("Sequence: ");
  print_sequence(sequence, 100);

  // Free the memory allocated for the sequence
  free(sequence);

  return 0;
}