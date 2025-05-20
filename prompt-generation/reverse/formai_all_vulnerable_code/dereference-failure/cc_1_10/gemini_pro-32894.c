//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the possible nucleotides
#define A 0
#define C 1
#define G 2
#define T 3

// Generate a random nucleotide
int generate_nucleotide() {
  return rand() % 4;
}

// Generate a random DNA sequence of a given length
char* generate_dna(int length) {
  char* dna = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int nucleotide = generate_nucleotide();
    switch (nucleotide) {
      case A:
        dna[i] = 'A';
        break;
      case C:
        dna[i] = 'C';
        break;
      case G:
        dna[i] = 'G';
        break;
      case T:
        dna[i] = 'T';
        break;
    }
  }
  dna[length] = '\0';
  return dna;
}

// Print a DNA sequence
void print_dna(char* dna) {
  printf("%s\n", dna);
}

// Count the number of occurrences of a given nucleotide in a DNA sequence
int count_nucleotide(char* dna, int nucleotide) {
  int count = 0;
  for (int i = 0; i < strlen(dna); i++) {
    if (dna[i] == nucleotide) {
      count++;
    }
  }
  return count;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence of length 100
  char* dna = generate_dna(100);

  // Print the DNA sequence
  print_dna(dna);

  // Count the number of occurrences of each nucleotide in the DNA sequence
  int a_count = count_nucleotide(dna, A);
  int c_count = count_nucleotide(dna, C);
  int g_count = count_nucleotide(dna, G);
  int t_count = count_nucleotide(dna, T);

  // Print the number of occurrences of each nucleotide
  printf("A: %d\n", a_count);
  printf("C: %d\n", c_count);
  printf("G: %d\n", g_count);
  printf("T: %d\n", t_count);

  // Free the memory allocated for the DNA sequence
  free(dna);

  return 0;
}