//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 1000000
#define MAX_GENOME_SIZE 1000000000

// Function to generate a random DNA sequence
char *generate_random_dna_sequence(int length) {
  char *sequence = malloc(length + 1);
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

// Function to generate a list of simulated reads from a DNA sequence
char **generate_simulated_reads(char *sequence, int num_reads, int read_length) {
  char **reads = malloc(num_reads * sizeof(char *));
  for (int i = 0; i < num_reads; i++) {
    int random_start = rand() % (strlen(sequence) - read_length);
    reads[i] = malloc(read_length + 1);
    strncpy(reads[i], sequence + random_start, read_length);
    reads[i][read_length] = '\0';
  }
  return reads;
}

// Function to write a list of simulated reads to a file
void write_simulated_reads_to_file(char **reads, int num_reads, int read_length,
                                     char *filename) {
  FILE *fp = fopen(filename, "w");
  for (int i = 0; i < num_reads; i++) {
    fprintf(fp, "%s\n", reads[i]);
  }
  fclose(fp);
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random DNA sequence
  char *sequence = generate_random_dna_sequence(MAX_GENOME_SIZE);

  // Generate a list of simulated reads from the DNA sequence
  char **reads = generate_simulated_reads(sequence, MAX_NUM_READS, MAX_READ_LENGTH);

  // Write the list of simulated reads to a file
  write_simulated_reads_to_file(reads, MAX_NUM_READS, MAX_READ_LENGTH, "simulated_reads.txt");

  // Free the allocated memory
  free(sequence);
  for (int i = 0; i < MAX_NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}