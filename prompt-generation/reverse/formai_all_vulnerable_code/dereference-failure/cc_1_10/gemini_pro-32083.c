//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 100000
#define MAX_GENOME_SIZE 1000000

// Function to generate a random DNA sequence of a given length
char *generate_random_dna_sequence(int length) {
  char *sequence = malloc(length + 1); // Allocate memory for the sequence
  for (int i = 0; i < length; i++) {
    // Generate a random number between 0 and 3
    int random_number = rand() % 4;
    // Convert the random number to a DNA base
    switch (random_number) {
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
  sequence[length] = '\0'; // Null-terminate the sequence
  return sequence;
}

// Function to simulate the sequencing of a DNA genome
char **simulate_sequencing(char *genome, int read_length, int num_reads) {
  // Allocate memory for the reads
  char **reads = malloc(num_reads * sizeof(char *));
  for (int i = 0; i < num_reads; i++) {
    reads[i] = malloc(read_length + 1); // Allocate memory for each read
  }

  // Generate the reads
  for (int i = 0; i < num_reads; i++) {
    // Generate a random start position for the read
    int start_position = rand() % (strlen(genome) - read_length);
    // Copy the read from the genome
    strncpy(reads[i], genome + start_position, read_length);
    reads[i][read_length] = '\0'; // Null-terminate the read
  }

  return reads;
}

// Function to print the reads
void print_reads(char **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    printf("%s\n", reads[i]);
  }
}

// Function to free the memory allocated for the reads
void free_reads(char **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    free(reads[i]);
  }
  free(reads);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random DNA genome
  char *genome = generate_random_dna_sequence(MAX_GENOME_SIZE);

  // Simulate the sequencing of the genome
  char **reads = simulate_sequencing(genome, MAX_READ_LENGTH, MAX_NUM_READS);

  // Print the reads
  print_reads(reads, MAX_NUM_READS);

  // Free the memory allocated for the reads
  free_reads(reads, MAX_NUM_READS);

  // Free the memory allocated for the genome
  free(genome);

  return 0;
}