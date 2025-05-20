//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the nucleotide characters
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of the genome
#define MAX_LENGTH 1000000

// Define the probability of each nucleotide
#define P_A 0.25
#define P_C 0.25
#define P_G 0.25
#define P_T 0.25

// Generate a random nucleotide
char random_nucleotide() {
  double r = (double)rand() / RAND_MAX;
  if (r < P_A) {
    return A;
  } else if (r < P_A + P_C) {
    return C;
  } else if (r < P_A + P_C + P_G) {
    return G;
  } else {
    return T;
  }
}

// Generate a random genome
char *random_genome(int length) {
  char *genome = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    genome[i] = random_nucleotide();
  }
  genome[length] = '\0';
  return genome;
}

// Print a genome
void print_genome(char *genome) {
  printf("%s\n", genome);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random genome
  char *genome = random_genome(MAX_LENGTH);

  // Print the genome
  print_genome(genome);

  // Free the memory allocated for the genome
  free(genome);

  return 0;
}