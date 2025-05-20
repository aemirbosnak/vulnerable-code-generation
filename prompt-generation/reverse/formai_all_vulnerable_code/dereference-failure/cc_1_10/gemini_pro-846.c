//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of the genome
#define MAX_GENOME_LENGTH 1000000

// Define the probability of each nucleotide base
#define P_A 0.25
#define P_C 0.25
#define P_G 0.25
#define P_T 0.25

// Define the number of reads to generate
#define NUM_READS 10000

// Define the length of each read
#define READ_LENGTH 100

// Define the sequencing error rate
#define ERROR_RATE 0.01

// Function to generate a random nucleotide base
char generate_base() {
  double r = (double)rand() / RAND_MAX;
  if (r < P_A) {
    return A;
  } else if (r < P_A + P_C) {
    return C;
  } else if (r < P_A + P_C + P_G) {
    return G;
  } else {
    return T;
  }
}

// Function to generate a random genome
char *generate_genome() {
  // Allocate memory for the genome
  char *genome = malloc(MAX_GENOME_LENGTH);

  // Generate the genome
  for (int i = 0; i < MAX_GENOME_LENGTH; i++) {
    genome[i] = generate_base();
  }

  // Return the genome
  return genome;
}

// Function to generate a random read
char *generate_read(char *genome) {
  // Allocate memory for the read
  char *read = malloc(READ_LENGTH);

  // Generate the read
  int start = rand() % (MAX_GENOME_LENGTH - READ_LENGTH);
  for (int i = 0; i < READ_LENGTH; i++) {
    read[i] = genome[start + i];
  }

  // Return the read
  return read;
}

// Function to simulate sequencing errors
char *simulate_errors(char *read) {
  // Allocate memory for the errored read
  char *errored_read = malloc(READ_LENGTH);

  // Copy the read into the errored read
  strcpy(errored_read, read);

  // Simulate the errors
  for (int i = 0; i < READ_LENGTH; i++) {
    if ((double)rand() / RAND_MAX < ERROR_RATE) {
      errored_read[i] = generate_base();
    }
  }

  // Return the errored read
  return errored_read;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the genome
  char *genome = generate_genome();

  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read(genome);
  }

  // Simulate the sequencing errors
  char **errored_reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    errored_reads[i] = simulate_errors(reads[i]);
  }

  // Print the genome
  printf("Genome:\n%s\n", genome);

  // Print the reads
  printf("Reads:\n");
  for (int i = 0; i < NUM_READS; i++) {
    printf("%s\n", reads[i]);
  }

  // Print the errored reads
  printf("Errored reads:\n");
  for (int i = 0; i < NUM_READS; i++) {
    printf("%s\n", errored_reads[i]);
  }

  // Free the memory
  free(genome);
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
    free(errored_reads[i]);
  }
  free(reads);
  free(errored_reads);

  return 0;
}