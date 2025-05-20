//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 10000

// Function to generate a random DNA sequence
char *generate_random_dna_sequence(int length) {
  char *sequence = malloc(sizeof(char) * (length + 1));
  for (int i = 0; i < length; i++) {
    int random_number = rand() % 4;
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
  sequence[length] = '\0';
  return sequence;
}

// Function to simulate the sequencing process
char **simulate_sequencing(char *genome, int read_length, int num_reads) {
  char **reads = malloc(sizeof(char *) * num_reads);
  for (int i = 0; i < num_reads; i++) {
    int start_position = rand() % (strlen(genome) - read_length + 1);
    reads[i] = malloc(sizeof(char) * (read_length + 1));
    for (int j = 0; j < read_length; j++) {
      reads[i][j] = genome[start_position + j];
    }
    reads[i][read_length] = '\0';
  }
  return reads;
}

// Function to print the reads
void print_reads(char **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    printf("%s\n", reads[i]);
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence
  int genome_length = 10000;
  char *genome = generate_random_dna_sequence(genome_length);

  // Simulate the sequencing process
  int read_length = 100;
  int num_reads = 1000;
  char **reads = simulate_sequencing(genome, read_length, num_reads);

  // Print the reads
  print_reads(reads, num_reads);

  // Free the memory allocated for the reads
  for (int i = 0; i < num_reads; i++) {
    free(reads[i]);
  }
  free(reads);

  // Free the memory allocated for the genome
  free(genome);

  return 0;
}