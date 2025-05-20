//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define NUM_BASES 4
#define BASE_SIZE 2
#define READ_LENGTH 100

// Base sequences
char *bases = "ACGT";

// Generate a random base
char generate_base() {
  return bases[rand() % NUM_BASES];
}

// Generate a random read
char *generate_read(int length) {
  char *read = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    read[i] = generate_base();
  }
  read[length] = '\0';
  return read;
}

// Generate a simulated genome
char *generate_genome(int length) {
  char *genome = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    genome[i] = generate_base();
  }
  genome[length] = '\0';
  return genome;
}

// Write the simulated genome to a file
void write_genome(char *genome, int length, char *filename) {
  FILE *file = fopen(filename, "w");
  fwrite(genome, BASE_SIZE, length, file);
  fclose(file);
}

// Write the simulated reads to a file
void write_reads(char **reads, int num_reads, int length, char *filename) {
  FILE *file = fopen(filename, "w");
  for (int i = 0; i < num_reads; i++) {
    fwrite(reads[i], BASE_SIZE, length, file);
    fputc('\n', file);
  }
  fclose(file);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate the simulated genome
  char *genome = generate_genome(1000000);

  // Generate the simulated reads
  char **reads = malloc(1000 * sizeof(char *));
  for (int i = 0; i < 1000; i++) {
    reads[i] = generate_read(READ_LENGTH);
  }

  // Write the simulated genome to a file
  write_genome(genome, 1000000, "genome.txt");

  // Write the simulated reads to a file
  write_reads(reads, 1000, READ_LENGTH, "reads.txt");

  // Free the allocated memory
  free(genome);
  for (int i = 0; i < 1000; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}