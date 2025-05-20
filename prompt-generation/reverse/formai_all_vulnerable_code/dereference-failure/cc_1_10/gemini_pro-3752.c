//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 1000

// Generate a random nucleotide base
int random_base() {
  return rand() % 4;
}

// Generate a random read
char *random_read() {
  // Allocate memory for the read
  char *read = malloc(MAX_READ_LENGTH + 1);

  // Generate the read
  for (int i = 0; i < MAX_READ_LENGTH; i++) {
    read[i] = random_base();
  }

  // Terminate the read with a null character
  read[MAX_READ_LENGTH] = '\0';

  // Return the read
  return read;
}

// Write the reads to a file
void write_reads(char **reads, int num_reads, char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "w");

  // Write the reads to the file
  for (int i = 0; i < num_reads; i++) {
    fprintf(fp, "%s\n", reads[i]);
  }

  // Close the file
  fclose(fp);
}

// Free the memory allocated for the reads
void free_reads(char **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    free(reads[i]);
  }
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = random_read();
  }

  // Write the reads to a file
  write_reads(reads, NUM_READS, "reads.txt");

  // Free the memory allocated for the reads
  free_reads(reads, NUM_READS);

  return 0;
}