//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// DNA bases
#define A 0
#define C 1
#define G 2
#define T 3

// Read length
#define READ_LENGTH 100

// Number of reads
#define NUM_READS 1000

// Error rate
#define ERROR_RATE 0.01

// Generate a random DNA sequence of length n
char *generate_sequence(int n) {
  char *sequence = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    int base = rand() % 4;
    switch (base) {
      case A:
        sequence[i] = 'A';
        break;
      case C:
        sequence[i] = 'C';
        break;
      case G:
        sequence[i] = 'G';
        break;
      case T:
        sequence[i] = 'T';
        break;
    }
  }
  sequence[n] = '\0';
  return sequence;
}

// Simulate sequencing errors in a read
char *simulate_errors(char *read) {
  int length = strlen(read);
  for (int i = 0; i < length; i++) {
    if (rand() < ERROR_RATE) {
      int base = rand() % 4;
      switch (base) {
        case A:
          read[i] = 'A';
          break;
        case C:
          read[i] = 'C';
          break;
        case G:
          read[i] = 'G';
          break;
        case T:
          read[i] = 'T';
          break;
      }
    }
  }
  return read;
}

// Generate a set of simulated reads from a DNA sequence
char **generate_reads(char *sequence) {
  int length = strlen(sequence);
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    int start = rand() % (length - READ_LENGTH);
    char *read = malloc(READ_LENGTH + 1);
    strncpy(read, sequence + start, READ_LENGTH);
    read[READ_LENGTH] = '\0';
    reads[i] = simulate_errors(read);
  }
  return reads;
}

// Print a DNA sequence
void print_sequence(char *sequence) {
  int length = strlen(sequence);
  for (int i = 0; i < length; i++) {
    printf("%c", sequence[i]);
  }
  printf("\n");
}

// Print a set of DNA reads
void print_reads(char **reads) {
  for (int i = 0; i < NUM_READS; i++) {
    printf("%s\n", reads[i]);
  }
}

// Free a set of DNA reads
void free_reads(char **reads) {
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);
}

int main() {
  // Set random seed
  srand(time(NULL));

  // Generate a random DNA sequence
  char *sequence = generate_sequence(1000);

  // Generate a set of simulated reads from the sequence
  char **reads = generate_reads(sequence);

  // Print the sequence and reads
  print_sequence(sequence);
  print_reads(reads);

  // Free the sequence and reads
  free(sequence);
  free_reads(reads);

  return 0;
}