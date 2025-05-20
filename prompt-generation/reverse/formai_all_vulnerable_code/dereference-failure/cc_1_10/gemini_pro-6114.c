//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A structure to represent a DNA sequence
typedef struct DNA_sequence {
  char *sequence;  // The DNA sequence
  int length;     // The length of the sequence
} DNA_sequence;

// A function to generate a random DNA sequence of a given length
DNA_sequence generate_random_DNA(int length) {
  // Allocate memory for the sequence
  char *sequence = malloc(length + 1);

  // Generate a random sequence of nucleotides
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

  // Terminate the string with a null character
  sequence[length] = '\0';

  // Return the DNA sequence
  DNA_sequence dna_sequence;
  dna_sequence.sequence = sequence;
  dna_sequence.length = length;
  return dna_sequence;
}

// A function to print a DNA sequence
void print_DNA(DNA_sequence dna_sequence) {
  printf("DNA sequence: %s\n", dna_sequence.sequence);
  printf("Length: %d\n", dna_sequence.length);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence of length 100
  DNA_sequence dna_sequence = generate_random_DNA(100);

  // Print the DNA sequence
  print_DNA(dna_sequence);

  // Free the memory allocated for the sequence
  free(dna_sequence.sequence);

  return 0;
}