//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_NUM_SEQUENCES 100

// Function to generate a random DNA sequence
char *generate_dna_sequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int rand_num = rand() % 4;
    switch (rand_num) {
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

// Function to write a DNA sequence to a file
void write_dna_sequence_to_file(char *sequence, char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }
  fprintf(fp, "%s\n", sequence);
  fclose(fp);
}

// Function to generate a random number of DNA sequences
int generate_random_num_sequences() {
  return rand() % MAX_NUM_SEQUENCES + 1;
}

// Function to generate a random DNA sequence length
int generate_random_sequence_length() {
  return rand() % MAX_SEQUENCE_LENGTH + 1;
}

// Function to main
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random number of DNA sequences
  int num_sequences = generate_random_num_sequences();

  // Generate a random DNA sequence length
  int sequence_length = generate_random_sequence_length();

  // Generate the DNA sequences
  char **sequences = malloc(num_sequences * sizeof(char *));
  for (int i = 0; i < num_sequences; i++) {
    sequences[i] = generate_dna_sequence(sequence_length);
  }

  // Write the DNA sequences to a file
  for (int i = 0; i < num_sequences; i++) {
    char filename[256];
    sprintf(filename, "sequence_%d.txt", i);
    write_dna_sequence_to_file(sequences[i], filename);
  }

  // Free the memory allocated for the DNA sequences
  for (int i = 0; i < num_sequences; i++) {
    free(sequences[i]);
  }
  free(sequences);

  return 0;
}