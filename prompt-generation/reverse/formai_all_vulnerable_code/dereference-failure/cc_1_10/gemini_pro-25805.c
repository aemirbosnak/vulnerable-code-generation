//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DNA_SIZE 1000000  // Size of the DNA sequence in base pairs
#define NUM_READS 10000  // Number of DNA reads to generate
#define READ_LENGTH 100  // Length of each DNA read

// Function to generate a random DNA sequence
char *generate_dna_sequence(int size) {
  char *sequence = malloc(size + 1);  // Allocate memory for the sequence
  for (int i = 0; i < size; i++) {
    // Generate a random character from the DNA alphabet
    int rand_num = rand() % 4;
    switch (rand_num) {
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
  sequence[size] = '\0';  // Add the null terminator
  return sequence;
}

// Function to generate a random DNA read
char *generate_dna_read(char *sequence, int start, int end) {
  char *read = malloc(end - start + 1);  // Allocate memory for the read
  for (int i = 0; i < end - start; i++) {
    read[i] = sequence[start + i];
  }
  read[end - start] = '\0';  // Add the null terminator
  return read;
}

// Driver function
int main() {
  srand(time(NULL));  // Initialize the random number generator

  // Generate a random DNA sequence
  char *sequence = generate_dna_sequence(DNA_SIZE);

  // Generate DNA reads from the sequence
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    int start = rand() % (DNA_SIZE - READ_LENGTH);
    int end = start + READ_LENGTH;
    reads[i] = generate_dna_read(sequence, start, end);
  }

  // Print the DNA reads
  for (int i = 0; i < NUM_READS; i++) {
    printf("%s\n", reads[i]);
  }

  // Free the allocated memory
  free(sequence);
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}