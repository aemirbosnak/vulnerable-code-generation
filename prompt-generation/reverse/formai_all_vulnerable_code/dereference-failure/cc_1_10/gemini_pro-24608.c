//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the size of the genome
#define GENOME_SIZE 1000000

// Define the number of reads
#define NUM_READS 10000

// Define the length of the reads
#define READ_LENGTH 100

// Define the error rate
#define ERROR_RATE 0.01

// Define the coverage
#define COVERAGE 10

// Define the seed for the random number generator
#define SEED 12345

// Generate a random number between 0 and 1
double rand01() {
  return (double)rand() / RAND_MAX;
}

// Generate a random integer between 0 and n-1
int randInt(int n) {
  return (int)(rand01() * n);
}

// Generate a random nucleotide
char randNucleotide() {
  int n = randInt(4);
  if (n == 0) {
    return 'A';
  } else if (n == 1) {
    return 'C';
  } else if (n == 2) {
    return 'G';
  } else {
    return 'T';
  }
}

// Generate a random read
char *randRead() {
  char *read = malloc(READ_LENGTH + 1);
  for (int i = 0; i < READ_LENGTH; i++) {
    read[i] = randNucleotide();
  }
  read[READ_LENGTH] = '\0';
  return read;
}

// Generate a random genome
char *randGenome() {
  char *genome = malloc(GENOME_SIZE + 1);
  for (int i = 0; i < GENOME_SIZE; i++) {
    genome[i] = randNucleotide();
  }
  genome[GENOME_SIZE] = '\0';
  return genome;
}

// Generate a set of reads from a genome
char **randReads(char *genome) {
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    int start = randInt(GENOME_SIZE - READ_LENGTH + 1);
    reads[i] = malloc(READ_LENGTH + 1);
    for (int j = 0; j < READ_LENGTH; j++) {
      reads[i][j] = genome[start + j];
    }
    reads[i][READ_LENGTH] = '\0';
  }
  return reads;
}

// Simulate sequencing errors
char *simulateErrors(char *read) {
  char *errorRead = malloc(READ_LENGTH + 1);
  for (int i = 0; i < READ_LENGTH; i++) {
    if (rand01() < ERROR_RATE) {
      errorRead[i] = randNucleotide();
    } else {
      errorRead[i] = read[i];
    }
  }
  errorRead[READ_LENGTH] = '\0';
  return errorRead;
}

// Simulate coverage
char **simulateCoverage(char **reads) {
  char **coveredReads = malloc(NUM_READS * COVERAGE * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    for (int j = 0; j < COVERAGE; j++) {
      coveredReads[i * COVERAGE + j] = malloc(READ_LENGTH + 1);
      strcpy(coveredReads[i * COVERAGE + j], reads[i]);
    }
  }
  return coveredReads;
}

// Write reads to a file
void writeReads(char **reads, char *filename) {
  FILE *fp = fopen(filename, "w");
  for (int i = 0; i < NUM_READS * COVERAGE; i++) {
    fprintf(fp, "%s\n", reads[i]);
  }
  fclose(fp);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(SEED);

  // Generate a random genome
  char *genome = randGenome();

  // Generate a set of reads from the genome
  char **reads = randReads(genome);

  // Simulate sequencing errors
  char **errorReads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    errorReads[i] = simulateErrors(reads[i]);
  }

  // Simulate coverage
  char **coveredReads = simulateCoverage(errorReads);

  // Write reads to a file
  writeReads(coveredReads, "reads.txt");

  // Free memory
  free(genome);
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
    free(errorReads[i]);
  }
  for (int i = 0; i < NUM_READS * COVERAGE; i++) {
    free(coveredReads[i]);
  }
  free(reads);
  free(errorReads);
  free(coveredReads);

  return 0;
}