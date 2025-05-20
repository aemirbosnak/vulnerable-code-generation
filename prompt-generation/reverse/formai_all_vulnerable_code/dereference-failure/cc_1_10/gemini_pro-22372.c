//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the size of the genome
#define GENOME_SIZE 1000000

// Define the number of reads to generate
#define NUM_READS 10000

// Define the length of each read
#define READ_LENGTH 100

// Define the probability of an error in a read
#define ERROR_PROBABILITY 0.01

// Generate a random nucleotide
char generate_nucleotide() {
  int r = rand() % 4;
  switch (r) {
    case 0:
      return 'A';
    case 1:
      return 'C';
    case 2:
      return 'G';
    case 3:
      return 'T';
  }
}

// Generate a random read
char *generate_read() {
  char *read = malloc(READ_LENGTH + 1);
  for (int i = 0; i < READ_LENGTH; i++) {
    read[i] = generate_nucleotide();
  }
  read[READ_LENGTH] = '\0';
  return read;
}

// Generate a genome
char *generate_genome() {
  char *genome = malloc(GENOME_SIZE + 1);
  for (int i = 0; i < GENOME_SIZE; i++) {
    genome[i] = generate_nucleotide();
  }
  genome[GENOME_SIZE] = '\0';
  return genome;
}

// Simulate sequencing the genome
char **simulate_sequencing(char *genome) {
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    int start = rand() % GENOME_SIZE;
    int end = start + READ_LENGTH;
    char *read = malloc(READ_LENGTH + 1);
    strncpy(read, genome + start, READ_LENGTH);
    read[READ_LENGTH] = '\0';
    // Introduce errors
    for (int j = 0; j < READ_LENGTH; j++) {
      if (rand() / (double)RAND_MAX < ERROR_PROBABILITY) {
        read[j] = generate_nucleotide();
      }
    }
    reads[i] = read;
  }
  return reads;
}

// Print the reads
void print_reads(char **reads) {
  for (int i = 0; i < NUM_READS; i++) {
    printf("%s\n", reads[i]);
  }
}

// Free the memory allocated for the reads
void free_reads(char **reads) {
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate the genome
  char *genome = generate_genome();

  // Simulate sequencing the genome
  char **reads = simulate_sequencing(genome);

  // Print the reads
  print_reads(reads);

  // Free the memory allocated for the reads
  free_reads(reads);

  // Free the memory allocated for the genome
  free(genome);

  return 0;
}