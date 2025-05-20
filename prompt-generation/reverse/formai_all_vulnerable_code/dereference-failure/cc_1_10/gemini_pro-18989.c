//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genius
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a genome
#define MAX_GENOME_LENGTH 1000000

// Define the probability of a mutation
#define MUTATION_PROBABILITY 0.001

// Define the types of mutations
enum mutation_type {
  INSERTION,
  DELETION,
  SUBSTITUTION
};

// Define the structure of a genome
struct genome {
  char *sequence;
  int length;
};

// Create a new genome
struct genome *create_genome(int length) {
  struct genome *genome = malloc(sizeof(struct genome));
  genome->sequence = malloc(length + 1);
  genome->length = length;
  return genome;
}

// Destroy a genome
void destroy_genome(struct genome *genome) {
  free(genome->sequence);
  free(genome);
}

// Generate a random genome
struct genome *generate_random_genome(int length) {
  struct genome *genome = create_genome(length);
  for (int i = 0; i < length; i++) {
    genome->sequence[i] = 'A' + rand() % 4;
  }
  genome->sequence[length] = '\0';
  return genome;
}

// Mutate a genome
void mutate_genome(struct genome *genome) {
  for (int i = 0; i < genome->length; i++) {
    if (rand() < MUTATION_PROBABILITY) {
      switch (rand() % 3) {
        case INSERTION:
          genome->sequence = realloc(genome->sequence, genome->length + 1);
          for (int j = genome->length; j > i; j--) {
            genome->sequence[j] = genome->sequence[j - 1];
          }
          genome->sequence[i] = 'A' + rand() % 4;
          genome->length++;
          break;
        case DELETION:
          for (int j = i; j < genome->length - 1; j++) {
            genome->sequence[j] = genome->sequence[j + 1];
          }
          genome->sequence = realloc(genome->sequence, genome->length - 1);
          genome->length--;
          break;
        case SUBSTITUTION:
          genome->sequence[i] = 'A' + rand() % 4;
          break;
      }
    }
  }
}

// Print a genome
void print_genome(struct genome *genome) {
  printf("%s\n", genome->sequence);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a new genome
  struct genome *genome = generate_random_genome(100000);

  // Mutate the genome
  mutate_genome(genome);

  // Print the genome
  print_genome(genome);

  // Destroy the genome
  destroy_genome(genome);

  return 0;
}