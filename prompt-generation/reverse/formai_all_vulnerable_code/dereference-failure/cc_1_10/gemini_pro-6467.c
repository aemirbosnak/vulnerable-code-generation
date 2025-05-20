//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The genome to be sequenced
char genome[] = "ACTGTACGTACGT";

// The sequencing machine
char sequencer[] = "ATCGTACGTACGT";

// The number of reads to generate
int num_reads = 100;

// The read length
int read_length = 10;

// The maximum number of errors per read
int max_errors = 2;

// The probability of an error
float error_probability = 0.01;

// Generate a random number between 0 and 1
float rand_float() {
  return (float)rand() / RAND_MAX;
}

// Generate a random character from the genome
char rand_char() {
  return genome[rand() % strlen(genome)];
}

// Generate a random read from the genome
char *rand_read() {
  char *read = malloc(read_length + 1);
  for (int i = 0; i < read_length; i++) {
    read[i] = rand_char();
  }
  read[read_length] = '\0';
  return read;
}

// Introduce errors into a read
void introduce_errors(char *read) {
  for (int i = 0; i < read_length; i++) {
    if (rand_float() < error_probability) {
      read[i] = rand_char();
    }
  }
}

// Simulate the sequencing process
void simulate_sequencing() {
  for (int i = 0; i < num_reads; i++) {
    char *read = rand_read();
    introduce_errors(read);
    printf("%s\n", read);
    free(read);
  }
}

int main() {
  srand(time(NULL));
  simulate_sequencing();
  return 0;
}