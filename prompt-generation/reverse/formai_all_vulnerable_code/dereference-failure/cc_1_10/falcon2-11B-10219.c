//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define a function to generate random DNA sequences
char *generate_dna_sequence(int length) {
  char *dna_sequence = malloc(length * sizeof(char));
  srand(time(0));
  for (int i = 0; i < length; i++) {
    dna_sequence[i] = 'A' + rand() % 4;
  }
  return dna_sequence;
}

// Define a function to compare two DNA sequences
int compare_dna_sequences(char *dna1, char *dna2, int length) {
  int matches = 0;
  for (int i = 0; i < length; i++) {
    if (dna1[i] == dna2[i]) {
      matches++;
    }
  }
  return matches;
}

// Define a function to find the similarity between two DNA sequences
int find_similarity(char *dna1, char *dna2, int length) {
  int matches = compare_dna_sequences(dna1, dna2, length);
  int mismatches = length - matches;
  return matches / (matches + mismatches);
}

// Define a function to print the DNA sequences
void print_dna_sequence(char *dna_sequence, int length) {
  for (int i = 0; i < length; i++) {
    printf("%c", dna_sequence[i]);
  }
  printf("\n");
}

// Main function
int main() {
  int length = 1000;
  char *dna1 = generate_dna_sequence(length);
  char *dna2 = generate_dna_sequence(length);

  printf("DNA Sequence 1: ");
  print_dna_sequence(dna1, length);
  printf("DNA Sequence 2: ");
  print_dna_sequence(dna2, length);

  printf("Similarity between the two sequences: %.2f\n", find_similarity(dna1, dna2, length));

  free(dna1);
  free(dna2);

  return 0;
}