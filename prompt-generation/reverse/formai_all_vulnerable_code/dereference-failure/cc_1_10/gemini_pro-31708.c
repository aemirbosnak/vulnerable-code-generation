//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the size of the genome
#define GENOME_SIZE 1000000

// Define the probability of a mutation
#define MUTATION_PROBABILITY 0.01

// Define the list of возможных nucleotides
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Generate a random nucleotide
char random_nucleotide() {
  return nucleotides[rand() % 4];
}

// Generate a random genome
char *generate_genome() {
  char *genome = malloc(GENOME_SIZE + 1);
  for (int i = 0; i < GENOME_SIZE; i++) {
    genome[i] = random_nucleotide();
  }
  genome[GENOME_SIZE] = '\0';
  return genome;
}

// Mutate a genome
void mutate_genome(char *genome) {
  for (int i = 0; i < GENOME_SIZE; i++) {
    if (rand() / (RAND_MAX + 1.0) < MUTATION_PROBABILITY) {
      genome[i] = random_nucleotide();
    }
  }
}

// Print a genome
void print_genome(char *genome) {
  printf("%s\n", genome);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random genome
  char *genome = generate_genome();

  // Mutate the genome
  mutate_genome(genome);

  // Print the genome
  print_genome(genome);

  // Free the memory allocated for the genome
  free(genome);

  return 0;
}