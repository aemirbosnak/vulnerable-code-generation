//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENOME_SIZE 1000000

// Function to generate a random DNA sequence
char *generate_dna_sequence(int size) {
  char *sequence = malloc(size + 1);
  for (int i = 0; i < size; i++) {
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
  sequence[size] = '\0';
  return sequence;
}

// Function to simulate the sequencing of a DNA sequence
char **simulate_sequencing(char *sequence, int read_length) {
  // Calculate the number of reads needed to cover the entire sequence
  int num_reads = (int)ceil((double)strlen(sequence) / read_length);

  // Create an array of reads
  char **reads = malloc(num_reads * sizeof(char *));
  for (int i = 0; i < num_reads; i++) {
    reads[i] = malloc(read_length + 1);
  }

  // Generate the reads
  int start_index = 0;
  for (int i = 0; i < num_reads; i++) {
    for (int j = 0; j < read_length; j++) {
      reads[i][j] = sequence[start_index + j];
    }
    reads[i][read_length] = '\0';
    start_index += read_length;
  }

  return reads;
}

// Function to print the reads
void print_reads(char **reads, int num_reads, int read_length) {
  for (int i = 0; i < num_reads; i++) {
    for (int j = 0; j < read_length; j++) {
      printf("%c", reads[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random DNA sequence
  char *sequence = generate_dna_sequence(MAX_GENOME_SIZE);

  // Simulate the sequencing of the DNA sequence
  char **reads = simulate_sequencing(sequence, 100);

  // Print the reads
  print_reads(reads, MAX_GENOME_SIZE / 100, 100);

  // Free the allocated memory
  free(sequence);
  for (int i = 0; i < MAX_GENOME_SIZE / 100; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}