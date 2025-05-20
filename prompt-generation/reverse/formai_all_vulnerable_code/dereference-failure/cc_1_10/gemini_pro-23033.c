//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// DNA bases
#define A 0
#define C 1
#define G 2
#define T 3

// Generate a random DNA base
int generate_base() {
  return rand() % 4;
}

// Generate a random DNA sequence of length n
char *generate_sequence(int n) {
  char *sequence = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    int base = generate_base();
    switch (base) {
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
  sequence[n] = '\0';
  return sequence;
}

// Print a DNA sequence
void print_sequence(char *sequence) {
  printf("%s\n", sequence);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence of length 100
  char *sequence = generate_sequence(100);

  // Print the sequence
  print_sequence(sequence);

  // Free the memory allocated for the sequence
  free(sequence);

  return 0;
}