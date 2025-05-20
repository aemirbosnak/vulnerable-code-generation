//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible nucleotides
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the length of the genome
#define GENOME_LENGTH 100000

// Define the number of reads
#define NUM_READS 1000

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the error rate
#define ERROR_RATE 0.01

// Generate a random nucleotide
char generate_nucleotide() {
  int r = rand() % 4;
  switch (r) {
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

// Generate a random read
char *generate_read(int length) {
  char *read = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    read[i] = generate_nucleotide();
  }
  read[length] = '\0';
  return read;
}

// Introduce errors into a read
void introduce_errors(char *read, int length) {
  for (int i = 0; i < length; i++) {
    if (rand() / (double)RAND_MAX < ERROR_RATE) {
      int r = rand() % 4;
      switch (r) {
        case 0:
          read[i] = A;
          break;
        case 1:
          read[i] = C;
          break;
        case 2:
          read[i] = G;
          break;
        case 3:
          read[i] = T;
          break;
      }
    }
  }
}

// Print the genome
void print_genome(char *genome, int length) {
  for (int i = 0; i < length; i++) {
    printf("%c", genome[i]);
  }
  printf("\n");
}

// Print the reads
void print_reads(char **reads, int num_reads, int length) {
  for (int i = 0; i < num_reads; i++) {
    for (int j = 0; j < length; j++) {
      printf("%c", reads[i][j]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the genome
  char *genome = malloc(GENOME_LENGTH + 1);
  for (int i = 0; i < GENOME_LENGTH; i++) {
    genome[i] = generate_nucleotide();
  }
  genome[GENOME_LENGTH] = '\0';

  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    int length = rand() % MAX_READ_LENGTH + 1;
    reads[i] = generate_read(length);
    introduce_errors(reads[i], length);
  }

  // Print the genome
  printf("Genome:\n");
  print_genome(genome, GENOME_LENGTH);

  // Print the reads
  printf("\nReads:\n");
  print_reads(reads, NUM_READS, MAX_READ_LENGTH);

  return 0;
}