//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random DNA sequence
char *generateDNA(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int random = rand() % 4;
    switch (random) {
      case 0:
        sequence[i] = 'A';
        break;
      case 1:
        sequence[i] = 'C';
        break;
      case 2:
        sequence[i] = 'G';
        break;
      case 3:
        sequence[i] = 'T';
        break;
    }
  }
  sequence[length] = '\0';
  return sequence;
}

// Function to simulate the sequencing process
char **sequenceDNA(char *dna, int readLength) {
  int numReads = (strlen(dna) / readLength) + 1;
  char **reads = malloc(numReads * sizeof(char *));
  for (int i = 0; i < numReads; i++) {
    reads[i] = malloc(readLength + 1);
    for (int j = 0; j < readLength; j++) {
      int random = rand() % 4;
      switch (random) {
        case 0:
          reads[i][j] = 'A';
          break;
        case 1:
          reads[i][j] = 'C';
          break;
        case 2:
          reads[i][j] = 'G';
          break;
        case 3:
          reads[i][j] = 'T';
          break;
      }
    }
    reads[i][readLength] = '\0';
  }
  return reads;
}

// Function to print the DNA sequence and reads
void printResults(char *dna, char **reads, int numReads, int readLength) {
  printf("Original DNA sequence:\n%s\n", dna);
  printf("Simulated reads:\n");
  for (int i = 0; i < numReads; i++) {
    printf("%s\n", reads[i]);
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence
  int dnaLength = 1000;
  char *dna = generateDNA(dnaLength);

  // Simulate the sequencing process
  int readLength = 100;
  char **reads = sequenceDNA(dna, readLength);

  // Print the results
  printResults(dna, reads, (dnaLength / readLength) + 1, readLength);

  // Free the allocated memory
  free(dna);
  for (int i = 0; i < (dnaLength / readLength) + 1; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}