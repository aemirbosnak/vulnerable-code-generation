//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide bases
char bases[] = {'A', 'C', 'G', 'T'};

// Simulate genome sequencing
char *simulate_genome_sequencing(int length) {
  // Allocate memory for the simulated sequence
  char *sequence = malloc(length + 1);
  if (sequence == NULL) {
    fprintf(stderr, "Error: Could not allocate memory for the sequence\n");
    exit(1);
  }

  // Generate random nucleotides
  for (int i = 0; i < length; i++) {
    sequence[i] = bases[rand() % 4];
  }

  // Terminate the string
  sequence[length] = '\0';

  // Return the simulated sequence
  return sequence;
}

// Print the simulated genome sequence
void print_genome_sequence(char *sequence) {
  printf("Simulated genome sequence:\n");
  printf("%s\n", sequence);
}

// Free the memory allocated for the simulated sequence
void free_genome_sequence(char *sequence) {
  free(sequence);
}

// Main function
int main(int argc, char **argv) {
  // Get the length of the genome sequence to simulate
  int length;
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <length>\n", argv[0]);
    exit(1);
  } else {
    length = atoi(argv[1]);
    if (length <= 0) {
      fprintf(stderr, "Error: Invalid length specified\n");
      exit(1);
    }
  }

  // Initialize the random number generator
  srand(time(NULL));

  // Simulate genome sequencing
  char *sequence = simulate_genome_sequencing(length);

  // Print the simulated genome sequence
  print_genome_sequence(sequence);

  // Free the memory allocated for the simulated sequence
  free_genome_sequence(sequence);

  return 0;
}