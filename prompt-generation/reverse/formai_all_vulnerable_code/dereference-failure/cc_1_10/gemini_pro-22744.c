//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Generates a random number between 0 and 1
double rand_double() {
  return (double)rand() / (double)RAND_MAX;
}

// Choose a random nucleotide
char rand_nucleotide() {
  double r = rand_double();
  if (r < 0.25) {
    return 'A';
  } else if (r < 0.5) {
    return 'C';
  } else if (r < 0.75) {
    return 'G';
  } else {
    return 'T';
  }
}

// Generate a random DNA sequence of length n
char *generate_dna_sequence(int n) {
  char *sequence = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    sequence[i] = rand_nucleotide();
  }
  sequence[n] = '\0';
  return sequence;
}

// Calculate the GC content of a DNA sequence
double gc_content(char *sequence) {
  int n = strlen(sequence);
  int num_gc = 0;
  for (int i = 0; i < n; i++) {
    if (sequence[i] == 'G' || sequence[i] == 'C') {
      num_gc++;
    }
  }
  return (double)num_gc / (double)n;
}

// Calculate the melting temperature of a DNA sequence
double melting_temperature(char *sequence) {
  int n = strlen(sequence);
  double tm = 4 * (gc_content(sequence)) + 2 * (1 - gc_content(sequence));
  return tm;
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random DNA sequence of length 100
  char *sequence = generate_dna_sequence(100);

  // Print the DNA sequence
  printf("DNA sequence: %s\n", sequence);

  // Calculate the GC content of the DNA sequence
  double gc = gc_content(sequence);

  // Print the GC content
  printf("GC content: %.2f%%\n", gc * 100);

  // Calculate the melting temperature of the DNA sequence
  double tm = melting_temperature(sequence);

  // Print the melting temperature
  printf("Melting temperature: %.2f°C\n", tm);

  // Free the memory allocated for the DNA sequence
  free(sequence);

  return 0;
}