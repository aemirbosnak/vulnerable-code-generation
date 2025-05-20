//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the DNA bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of the genome
#define MAX_LENGTH 1000000

// Define the number of reads to generate
#define NUM_READS 10000

// Define the length of each read
#define READ_LENGTH 100

// Define the error rate
#define ERROR_RATE 0.01

// Generate a random DNA sequence
char *generate_sequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int base = rand() % 4;
    switch (base) {
      case 0:
        sequence[i] = A;
        break;
      case 1:
        sequence[i] = C;
        break;
      case 2:
        sequence[i] = G;
        break;
      case 3:
        sequence[i] = T;
        break;
    }
  }
  sequence[length] = '\0';
  return sequence;
}

// Generate a random read from a sequence
char *generate_read(char *sequence, int length) {
  int start = rand() % (length - READ_LENGTH + 1);
  char *read = malloc(READ_LENGTH + 1);
  for (int i = 0; i < READ_LENGTH; i++) {
    read[i] = sequence[start + i];
  }
  read[READ_LENGTH] = '\0';
  return read;
}

// Introduce errors into a read
void introduce_errors(char *read, int length) {
  for (int i = 0; i < length; i++) {
    if (rand() / (RAND_MAX + 1.0) < ERROR_RATE) {
      int base = rand() % 4;
      switch (base) {
        case 0:
          read[i] = A;
          break;
        case 1:
          read[i] = C;
          break;
        case 2:
          read[i] = G;
          break;
        case 3:
          read[i] = T;
          break;
      }
    }
  }
}

// Print the sequence and reads to a file
void print_output(char *sequence, char **reads, int num_reads) {
  FILE *fp = fopen("output.txt", "w");
  fprintf(fp, "Sequence: %s\n", sequence);
  for (int i = 0; i < num_reads; i++) {
    fprintf(fp, "Read %d: %s\n", i + 1, reads[i]);
  }
  fclose(fp);
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate the sequence
  char *sequence = generate_sequence(MAX_LENGTH);

  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read(sequence, MAX_LENGTH);
  }

  // Introduce errors into the reads
  for (int i = 0; i < NUM_READS; i++) {
    introduce_errors(reads[i], READ_LENGTH);
  }

  // Print the sequence and reads to a file
  print_output(sequence, reads, NUM_READS);

  // Free the memory
  free(sequence);
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}