//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 1000

// Define the probability of each nucleotide base
#define PROB_A 0.25
#define PROB_C 0.25
#define PROB_G 0.25
#define PROB_T 0.25

// Generate a random nucleotide base
char generate_base() {
  double r = (double)rand() / RAND_MAX;
  if (r < PROB_A) {
    return A;
  } else if (r < PROB_A + PROB_C) {
    return C;
  } else if (r < PROB_A + PROB_C + PROB_G) {
    return G;
  } else {
    return T;
  }
}

// Generate a random read
char *generate_read() {
  // Allocate memory for the read
  char *read = malloc(MAX_READ_LENGTH + 1);

  // Generate the read
  for (int i = 0; i < MAX_READ_LENGTH; i++) {
    read[i] = generate_base();
  }

  // Terminate the read with a null character
  read[MAX_READ_LENGTH] = '\0';

  // Return the read
  return read;
}

// Write the reads to a file
void write_reads(char **reads, int num_reads) {
  // Open the file
  FILE *fp = fopen("reads.txt", "w");

  // Write the reads to the file
  for (int i = 0; i < num_reads; i++) {
    fprintf(fp, "%s\n", reads[i]);
  }

  // Close the file
  fclose(fp);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read();
  }

  // Write the reads to a file
  write_reads(reads, NUM_READS);

  // Free the memory allocated for the reads
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}