//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: thoughtful
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Define the size of the genome
#define GENOME_SIZE 1000000

// Define the number of reads
#define READ_COUNT 10000

// Define the length of the reads
#define READ_LENGTH 100

// Define the error rate
#define ERROR_RATE 0.01

// Generate a random base
char generate_base() {
  int r = rand() % 4;
  if (r == 0) {
    return 'A';
  } else if (r == 1) {
    return 'C';
  } else if (r == 2) {
    return 'G';
  } else {
    return 'T';
  }
}

// Generate a random read
char *generate_read() {
  char *read = malloc(READ_LENGTH + 1);
  for (int i = 0; i < READ_LENGTH; i++) {
    read[i] = generate_base();
  }
  read[READ_LENGTH] = '\0';
  return read;
}

// Generate a random genome
char *generate_genome() {
  char *genome = malloc(GENOME_SIZE + 1);
  for (int i = 0; i < GENOME_SIZE; i++) {
    genome[i] = generate_base();
  }
  genome[GENOME_SIZE] = '\0';
  return genome;
}

// Simulate sequencing
char **simulate_sequencing(char *genome) {
  char **reads = malloc(READ_COUNT * sizeof(char *));
  for (int i = 0; i < READ_COUNT; i++) {
    int start = rand() % (GENOME_SIZE - READ_LENGTH);
    char *read = generate_read();
    for (int j = 0; j < READ_LENGTH; j++) {
      if ((double)rand() / RAND_MAX < ERROR_RATE) {
        read[j] = generate_base();
      } else {
        read[j] = genome[start + j];
      }
    }
    reads[i] = read;
  }
  return reads;
}

// Print the reads
void print_reads(char **reads) {
  for (int i = 0; i < READ_COUNT; i++) {
    printf("%s\n", reads[i]);
  }
}

// Free the memory
void free_reads(char **reads) {
  for (int i = 0; i < READ_COUNT; i++) {
    free(reads[i]);
  }
  free(reads);
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the genome
  char *genome = generate_genome();

  // Simulate sequencing
  char **reads = simulate_sequencing(genome);

  // Print the reads
  print_reads(reads);

  // Free the memory
  free_reads(reads);
  free(genome);

  return 0;
}