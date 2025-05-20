//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 10000

// Function to generate a random sequence of nucleotides
char *generate_sequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int rand_num = rand() % 4;
    if (rand_num == 0) {
      sequence[i] = 'A';
    } else if (rand_num == 1) {
      sequence[i] = 'C';
    } else if (rand_num == 2) {
      sequence[i] = 'G';
    } else {
      sequence[i] = 'T';
    }
  }
  sequence[length] = '\0';
  return sequence;
}

// Function to generate a random read from a sequence
char *generate_read(char *sequence, int length) {
  int start_pos = rand() % (strlen(sequence) - length);
  char *read = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    read[i] = sequence[start_pos + i];
  }
  read[length] = '\0';
  return read;
}

// Function to simulate the sequencing of a genome
char **simulate_sequencing(char *genome, int num_reads, int read_length) {
  char **reads = malloc(num_reads * sizeof(char *));
  for (int i = 0; i < num_reads; i++) {
    reads[i] = generate_read(genome, read_length);
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
  // Set the random seed
  srand(time(NULL));

  // Generate the genome
  char *genome = generate_sequence(10000);

  // Simulate the sequencing of the genome
  char **reads = simulate_sequencing(genome, MAX_NUM_READS, MAX_READ_LENGTH);

  // Print the reads
  print_reads(reads, MAX_NUM_READS);

  // Free the allocated memory
  free(genome);
  for (int i = 0; i < MAX_NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}