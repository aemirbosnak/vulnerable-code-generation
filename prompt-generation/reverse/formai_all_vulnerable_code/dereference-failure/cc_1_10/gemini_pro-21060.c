//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 1000

// Define the probability of a mutation
#define MUTATION_PROBABILITY 0.01

// Define the probability of a sequencing error
#define SEQUENCING_ERROR_PROBABILITY 0.02

// Generate a random number between 0 and 1
double rand01() {
  return (double)rand() / RAND_MAX;
}

// Generate a random nucleotide
char rand_nucleotide() {
  double r = rand01();
  if (r < 0.25) {
    return 'A';
  } else if (r < 0.5) {
    return 'C';
  } else if (r < 0.75) {
    return 'G';
  } else {
    return 'T';
  }
}

// Generate a random read
char *rand_read() {
  int length = rand() % MAX_READ_LENGTH + 1;
  char *read = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    read[i] = rand_nucleotide();
  }
  read[length] = '\0';
  return read;
}

// Mutate a read
void mutate_read(char *read) {
  int length = strlen(read);
  for (int i = 0; i < length; i++) {
    if (rand01() < MUTATION_PROBABILITY) {
      read[i] = rand_nucleotide();
    }
  }
}

// Introduce sequencing errors into a read
void introduce_sequencing_errors(char *read) {
  int length = strlen(read);
  for (int i = 0; i < length; i++) {
    if (rand01() < SEQUENCING_ERROR_PROBABILITY) {
      read[i] = rand_nucleotide();
    }
  }
}

// Print a read
void print_read(char *read) {
  printf("%s\n", read);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = rand_read();
  }

  // Mutate the reads
  for (int i = 0; i < NUM_READS; i++) {
    mutate_read(reads[i]);
  }

  // Introduce sequencing errors into the reads
  for (int i = 0; i < NUM_READS; i++) {
    introduce_sequencing_errors(reads[i]);
  }

  // Print the reads
  for (int i = 0; i < NUM_READS; i++) {
    print_read(reads[i]);
  }

  // Free the reads
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}