//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the size of the genome
#define GENOME_SIZE 1000000

// Define the number of reads
#define NUM_READS 10000

// Define the length of each read
#define READ_LENGTH 100

// Define the error rate
#define ERROR_RATE 0.01

// Function to generate a random base
char generate_base() {
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
    default:
      return 'N';
  }
}

// Function to generate a random read
char *generate_read() {
  char *read = malloc(READ_LENGTH + 1);
  for (int i = 0; i < READ_LENGTH; i++) {
    read[i] = generate_base();
  }
  read[READ_LENGTH] = '\0';
  return read;
}

// Function to simulate sequencing errors
void simulate_errors(char *read) {
  int r = rand() % 100;
  if (r < ERROR_RATE * 100) {
    int pos = rand() % READ_LENGTH;
    read[pos] = generate_base();
  }
}

// Function to main
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the genome
  char *genome = malloc(GENOME_SIZE + 1);
  for (int i = 0; i < GENOME_SIZE; i++) {
    genome[i] = generate_base();
  }
  genome[GENOME_SIZE] = '\0';

  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read();
  }

  // Simulate sequencing errors
  for (int i = 0; i < NUM_READS; i++) {
    simulate_errors(reads[i]);
  }

  // Print the genome and the reads
  printf("Genome:\n%s\n", genome);
  printf("Reads:\n");
  for (int i = 0; i < NUM_READS; i++) {
    printf("%s\n", reads[i]);
  }

  // Free the memory
  free(genome);
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}