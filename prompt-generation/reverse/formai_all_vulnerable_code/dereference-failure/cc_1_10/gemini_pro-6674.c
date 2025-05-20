//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Probability of each nucleotide base
#define PA 0.25
#define PC 0.25
#define PG 0.25
#define PT 0.25

// Maximum length of a genome
#define MAX_GENOME_LENGTH 1000000

// Function to generate a random nucleotide base
char generate_nucleotide() {
  double r = (double)rand() / RAND_MAX;

  if (r < PA) {
    return A;
  } else if (r < PA + PC) {
    return C;
  } else if (r < PA + PC + PG) {
    return G;
  } else {
    return T;
  }
}

// Function to generate a random genome
char *generate_genome(int length) {
  char *genome = malloc(length + 1);

  for (int i = 0; i < length; i++) {
    genome[i] = generate_nucleotide();
  }

  genome[length] = '\0';

  return genome;
}

// Function to write a genome to a file
void write_genome_to_file(char *genome, char *filename) {
  FILE *fp = fopen(filename, "w");

  if (fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  fprintf(fp, "%s", genome);

  fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a genome length
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <genome length>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the genome length from the user
  int length = atoi(argv[1]);

  // Check if the genome length is valid
  if (length <= 0 || length > MAX_GENOME_LENGTH) {
    fprintf(stderr, "Error: Invalid genome length\n");
    exit(EXIT_FAILURE);
  }

  // Seed the random number generator
  srand(time(NULL));

  // Generate a random genome
  char *genome = generate_genome(length);

  // Write the genome to a file
  write_genome_to_file(genome, "genome.txt");

  // Free the memory allocated for the genome
  free(genome);

  return 0;
}