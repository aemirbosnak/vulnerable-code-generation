//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3

// Define the maximum length of the genome
#define MAX_GENOME_LENGTH 10000

// Generate a random nucleotide base
int random_base() {
  return rand() % 4;
}

// Generate a random genome of the given length
char *generate_genome(int length) {
  char *genome = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    genome[i] = random_base() + 'A';
  }
  genome[length] = '\0';
  return genome;
}

// Print the genome to the console
void print_genome(char *genome) {
  printf("%s\n", genome);
}

// Free the memory allocated for the genome
void free_genome(char *genome) {
  free(genome);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random genome of length 10000
  char *genome = generate_genome(10000);

  // Print the genome to the console
  print_genome(genome);

  // Free the memory allocated for the genome
  free_genome(genome);

  return 0;
}