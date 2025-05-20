//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for the nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3

// Length of the genome sequence to be generated
#define GENOME_LENGTH 1000000

// Probabilities of each nucleotide base occurring
// These values can be adjusted to simulate different species or conditions
float base_probabilities[4] = {0.25, 0.25, 0.25, 0.25};

// Function to generate a random nucleotide base
int generate_base() {
  float rand_num = (float)rand() / (float)RAND_MAX;
  float cum_prob = 0.0;
  for (int i = 0; i < 4; i++) {
    cum_prob += base_probabilities[i];
    if (rand_num <= cum_prob) {
      return i;
    }
  }
  // Should never reach here
  return -1;
}

// Function to generate a random genome sequence
void generate_genome(char *genome) {
  for (int i = 0; i < GENOME_LENGTH; i++) {
    int base = generate_base();
    switch (base) {
      case A:
        genome[i] = 'A';
        break;
      case C:
        genome[i] = 'C';
        break;
      case G:
        genome[i] = 'G';
        break;
      case T:
        genome[i] = 'T';
        break;
    }
  }
}

// Function to print the genome sequence
void print_genome(char *genome) {
  for (int i = 0; i < GENOME_LENGTH; i++) {
    printf("%c", genome[i]);
  }
  printf("\n");
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Allocate memory for the genome sequence
  char *genome = malloc(sizeof(char) * GENOME_LENGTH);

  // Generate the genome sequence
  generate_genome(genome);

  // Print the genome sequence
  printf("Generated genome sequence:\n");
  print_genome(genome);

  // Free the memory allocated for the genome sequence
  free(genome);

  return 0;
}