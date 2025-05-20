//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of the genome
#define MAX_GENOME_LENGTH 1000000

// Define the probability of each nucleotide base
#define PROB_A 0.25
#define PROB_C 0.25
#define PROB_G 0.25
#define PROB_T 0.25

// Generate a random nucleotide base
char generate_base() {
  double r = (double)rand() / RAND_MAX;
  if (r < PROB_A) {
    return A;
  } else if (r < PROB_A + PROB_C) {
    return C;
  } else if (r < PROB_A + PROB_C + PROB_G) {
    return G;
  } else {
    return T;
  }
}

// Generate a random genome of a given length
char *generate_genome(int length) {
  char *genome = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    genome[i] = generate_base();
  }
  genome[length] = '\0';
  return genome;
}

// Print a genome to the console
void print_genome(char *genome) {
  printf("%s\n", genome);
}

// Save a genome to a file
void save_genome(char *genome, char *filename) {
  FILE *file = fopen(filename, "w");
  fprintf(file, "%s", genome);
  fclose(file);
}

// Load a genome from a file
char *load_genome(char *filename) {
  FILE *file = fopen(filename, "r");
  fseek(file, 0, SEEK_END);
  long length = ftell(file);
  fseek(file, 0, SEEK_SET);
  char *genome = malloc(length + 1);
  fread(genome, length, 1, file);
  genome[length] = '\0';
  fclose(file);
  return genome;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random genome of length 1000000
  char *genome = generate_genome(1000000);

  // Print the genome to the console
  print_genome(genome);

  // Save the genome to a file
  save_genome(genome, "genome.txt");

  // Load the genome from the file
  char *loaded_genome = load_genome("genome.txt");

  // Print the loaded genome to the console
  print_genome(loaded_genome);

  // Free the memory allocated for the genomes
  free(genome);
  free(loaded_genome);

  return 0;
}