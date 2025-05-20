//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of nucleotides in the genome
#define GENOME_LENGTH 1000000

// Define the probability of a mutation occurring
#define MUTATION_PROBABILITY 0.001

// Define the types of mutations that can occur
#define INSERTION 1
#define DELETION 2
#define SUBSTITUTION 3

// Function to generate a random number between 0 and 1
double rand01() {
  return (double)rand() / RAND_MAX;
}

// Function to generate a random nucleotide
char rand_nucleotide() {
  double r = rand01();
  if (r < 0.25) {
    return 'A';
  } else if (r < 0.5) {
    return 'C';
  } else if (r < 0.75) {
    return 'G';
  } else {
    return 'T';
  }
}

// Function to simulate a mutation
char mutate(char nucleotide) {
  double r = rand01();
  if (r < MUTATION_PROBABILITY) {
    int mutation_type = rand() % 3 + 1;
    switch (mutation_type) {
    case INSERTION:
      return rand_nucleotide();
    case DELETION:
      return '\0';
    case SUBSTITUTION:
      return rand_nucleotide();
    }
  }
  return nucleotide;
}

// Function to simulate genome sequencing
char *sequence_genome(char *genome) {
  char *sequenced_genome = malloc(GENOME_LENGTH + 1);
  for (int i = 0; i < GENOME_LENGTH; i++) {
    sequenced_genome[i] = mutate(genome[i]);
  }
  sequenced_genome[GENOME_LENGTH] = '\0';
  return sequenced_genome;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random genome
  char *genome = malloc(GENOME_LENGTH + 1);
  for (int i = 0; i < GENOME_LENGTH; i++) {
    genome[i] = rand_nucleotide();
  }
  genome[GENOME_LENGTH] = '\0';

  // Simulate genome sequencing
  char *sequenced_genome = sequence_genome(genome);

  // Print the original genome and the sequenced genome
  printf("Original genome: %s\n", genome);
  printf("Sequenced genome: %s\n", sequenced_genome);

  // Free the allocated memory
  free(genome);
  free(sequenced_genome);

  return 0;
}