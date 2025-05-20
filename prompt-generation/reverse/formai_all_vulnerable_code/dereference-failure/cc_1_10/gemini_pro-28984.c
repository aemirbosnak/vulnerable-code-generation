//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 1000

// Define the probability of a sequencing error
#define ERROR_PROBABILITY 0.01

// Generate a random nucleotide base
char generate_base() {
  int rand_num = rand() % 4;
  switch (rand_num) {
    case 0:
      return A;
    case 1:
      return C;
    case 2:
      return G;
    case 3:
      return T;
  }
}

// Generate a random read of a given length
char *generate_read(int length) {
  char *read = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    read[i] = generate_base();
  }
  read[length] = '\0';
  return read;
}

// Introduce sequencing errors into a read
char *introduce_errors(char *read, double error_probability) {
  int length = strlen(read);
  for (int i = 0; i < length; i++) {
    double rand_num = (double)rand() / RAND_MAX;
    if (rand_num < error_probability) {
      read[i] = generate_base();
    }
  }
  return read;
}

// Write the reads to a FASTA file
void write_reads_to_fasta(char **reads, int num_reads, char *filename) {
  FILE *fasta_file = fopen(filename, "w");
  for (int i = 0; i < num_reads; i++) {
    fprintf(fasta_file, ">Read%d\n", i);
    fprintf(fasta_file, "%s\n", reads[i]);
  }
  fclose(fasta_file);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read(MAX_READ_LENGTH);
  }

  // Introduce sequencing errors into the reads
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = introduce_errors(reads[i], ERROR_PROBABILITY);
  }

  // Write the reads to a FASTA file
  write_reads_to_fasta(reads, NUM_READS, "reads.fasta");

  // Free the allocated memory
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}