//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GENOME_SIZE 1000000

// Function to generate a random nucleotide
char generate_nucleotide() {
  int rand_num = rand() % 4;
  switch (rand_num) {
  case 0:
    return 'A';
  case 1:
    return 'C';
  case 2:
    return 'G';
  case 3:
    return 'T';
  default:
    return 'N';
  }
}

// Function to generate a random genome
char *generate_genome(int size) {
  char *genome = malloc(size + 1);
  for (int i = 0; i < size; i++) {
    genome[i] = generate_nucleotide();
  }
  genome[size] = '\0';
  return genome;
}

// Function to print a genome
void print_genome(char *genome) {
  printf("%s\n", genome);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random genome of size MAX_GENOME_SIZE
  char *genome = generate_genome(MAX_GENOME_SIZE);

  // Print the genome
  print_genome(genome);

  // Free the memory allocated for the genome
  free(genome);

  return 0;
}