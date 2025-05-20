//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_READ_LENGTH 100
#define MAX_READS 10000

// Function to generate a random DNA sequence
char *generate_sequence(int length) {
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

// Function to generate a set of reads from a DNA sequence
char **generate_reads(char *sequence, int num_reads, int read_length) {
  char **reads = malloc(num_reads * sizeof(char *));
  for (int i = 0; i < num_reads; i++) {
    int start_position = rand() % (strlen(sequence) - read_length + 1);
    reads[i] = malloc(read_length + 1);
    strncpy(reads[i], sequence + start_position, read_length);
    reads[i][read_length] = '\0';
  }
  return reads;
}

// Function to print a set of reads
void print_reads(char **reads, int num_reads, int read_length) {
  for (int i = 0; i < num_reads; i++) {
    printf("%s\n", reads[i]);
  }
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a DNA sequence
  char *sequence = generate_sequence(1000);

  // Generate a set of reads from the DNA sequence
  char **reads = generate_reads(sequence, 100, 50);

  // Print the set of reads
  print_reads(reads, 100, 50);

  // Free the allocated memory
  free(sequence);
  for (int i = 0; i < 100; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}