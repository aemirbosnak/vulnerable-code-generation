//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the sequence length
#define SEQUENCE_LENGTH 100

// Define the number of reads
#define NUM_READS 1000

// Define the read length
#define READ_LENGTH 50

// Define the error rate
#define ERROR_RATE 0.01

// Define the sequencing coverage
#define COVERAGE 10

// Define the seed for the random number generator
#define SEED 12345

// Generate a random nucleotide base
char generate_base() {
  double r = rand() / (double)RAND_MAX;
  if (r < 0.25) {
    return A;
  } else if (r < 0.5) {
    return C;
  } else if (r < 0.75) {
    return G;
  } else {
    return T;
  }
}

// Generate a random read
char *generate_read(char *sequence) {
  char *read = malloc(READ_LENGTH + 1);
  for (int i = 0; i < READ_LENGTH; i++) {
    // Get a random nucleotide base
    char base = generate_base();

    // Introduce an error with probability ERROR_RATE
    if (rand() / (double)RAND_MAX < ERROR_RATE) {
      // Flip the base
      base = (base == A) ? T : (base == C) ? G : (base == G) ? C : A;
    }

    // Add the base to the read
    read[i] = base;
  }

  // Add the null terminator
  read[READ_LENGTH] = '\0';

  return read;
}

// Generate a set of reads
char **generate_reads(char *sequence) {
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read(sequence);
  }

  return reads;
}

// Assemble the reads into a consensus sequence
char *assemble_sequence(char **reads) {
  char *consensus = malloc(SEQUENCE_LENGTH + 1);
  for (int i = 0; i < SEQUENCE_LENGTH; i++) {
    // Count the number of occurrences of each base
    int counts[4] = {0};
    for (int j = 0; j < NUM_READS; j++) {
      char base = reads[j][i];
      if (base == A) {
        counts[0]++;
      } else if (base == C) {
        counts[1]++;
      } else if (base == G) {
        counts[2]++;
      } else if (base == T) {
        counts[3]++;
      }
    }

    // Get the base with the highest count
    int max_count = 0;
    char max_base = 0;
    for (int j = 0; j < 4; j++) {
      if (counts[j] > max_count) {
        max_count = counts[j];
        max_base = (j == 0) ? A : (j == 1) ? C : (j == 2) ? G : T;
      }
    }

    // Add the base to the consensus sequence
    consensus[i] = max_base;
  }

  // Add the null terminator
  consensus[SEQUENCE_LENGTH] = '\0';

  return consensus;
}

// Print the consensus sequence
void print_sequence(char *sequence) {
  printf("Consensus sequence:\n");
  for (int i = 0; i < SEQUENCE_LENGTH; i++) {
    printf("%c", sequence[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Set the random seed
  srand(SEED);

  // Generate a random sequence
  char *sequence = malloc(SEQUENCE_LENGTH + 1);
  for (int i = 0; i < SEQUENCE_LENGTH; i++) {
    sequence[i] = generate_base();
  }

  // Add the null terminator
  sequence[SEQUENCE_LENGTH] = '\0';

  // Generate a set of reads
  char **reads = generate_reads(sequence);

  // Assemble the reads into a consensus sequence
  char *consensus = assemble_sequence(reads);

  // Print the consensus sequence
  print_sequence(consensus);

  // Free the allocated memory
  free(sequence);
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);
  free(consensus);

  return 0;
}