//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Define the four nucleotides
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the number of nucleotides in the genome
#define GENOME_SIZE 1000000

// Define the probability of each nucleotide
#define P_A 0.25
#define P_C 0.25
#define P_G 0.25
#define P_T 0.25

// Define the function to generate a random nucleotide
char generate_nucleotide() {
  // Generate a random number between 0 and 1
  double r = (double)rand() / (double)RAND_MAX;

  // Return the corresponding nucleotide
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

// Define the function to generate a random genome
char *generate_genome() {
  // Allocate memory for the genome
  char *genome = malloc(GENOME_SIZE + 1);

  // Generate the genome
  for (int i = 0; i < GENOME_SIZE; i++) {
    genome[i] = generate_nucleotide();
  }

  // Terminate the genome with a null character
  genome[GENOME_SIZE] = '\0';

  // Return the genome
  return genome;
}

// Define the function to print a genome
void print_genome(char *genome) {
  // Print the genome
  printf("%s\n", genome);
}

// Define the main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random genome
  char *genome = generate_genome();

  // Print the genome
  print_genome(genome);

  // Free the memory allocated for the genome
  free(genome);

  // Return 0
  return 0;
}