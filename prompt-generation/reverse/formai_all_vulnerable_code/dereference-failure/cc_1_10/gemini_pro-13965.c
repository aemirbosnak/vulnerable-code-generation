//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Simulate the sequencing of a single read
char *simulate_read(int length) {
  // Allocate memory for the read
  char *read = malloc(length + 1);

  // Generate a random sequence of nucleotides
  for (int i = 0; i < length; i++) {
    int nucleotide = rand() % 4;
    switch (nucleotide) {
      case 0:
        read[i] = 'A';
        break;
      case 1:
        read[i] = 'C';
        break;
      case 2:
        read[i] = 'G';
        break;
      case 3:
        read[i] = 'T';
        break;
    }
  }

  // Add a null terminator to the end of the read
  read[length] = '\0';

  // Return the read
  return read;
}

// Simulate the sequencing of a genome
char **simulate_genome(int num_reads, int read_length) {
  // Allocate memory for the reads
  char **reads = malloc(num_reads * sizeof(char *));

  // Simulate the sequencing of each read
  for (int i = 0; i < num_reads; i++) {
    reads[i] = simulate_read(read_length);
  }

  // Return the reads
  return reads;
}

// Print the reads
void print_reads(char **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    printf("%s\n", reads[i]);
  }
}

// Free the memory allocated for the reads
void free_reads(char **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    free(reads[i]);
  }

  free(reads);
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Simulate the sequencing of a genome
  char **reads = simulate_genome(100, 100);

  // Print the reads
  print_reads(reads, 100);

  // Free the memory allocated for the reads
  free_reads(reads, 100);

  return 0;
}