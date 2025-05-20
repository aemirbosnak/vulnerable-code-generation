//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_READ_LENGTH 1000

typedef struct {
  char *sequence;
  int length;
} Read;

// Create a new read
Read *create_read(char *sequence, int length) {
  Read *read = malloc(sizeof(Read));
  read->sequence = malloc(length + 1);
  strcpy(read->sequence, sequence);
  read->length = length;
  return read;
}

// Free a read
void free_read(Read *read) {
  free(read->sequence);
  free(read);
}

// Generate a random read
Read *generate_random_read(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    sequence[i] = "ACGT"[rand() % 4];
  }
  sequence[length] = '\0';
  return create_read(sequence, length);
}

// Simulate the sequencing process
Read **simulate_sequencing(int num_reads, int read_length) {
  Read **reads = malloc(num_reads * sizeof(Read *));
  for (int i = 0; i < num_reads; i++) {
    reads[i] = generate_random_read(read_length);
  }
  return reads;
}

// Print the reads
void print_reads(Read **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    printf("%s\n", reads[i]->sequence);
  }
}

// Free the reads
void free_reads(Read **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    free_read(reads[i]);
  }
  free(reads);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Simulate the sequencing process
  int num_reads = 100;
  int read_length = 100;
  Read **reads = simulate_sequencing(num_reads, read_length);

  // Print the reads
  print_reads(reads, num_reads);

  // Free the reads
  free_reads(reads, num_reads);

  return 0;
}