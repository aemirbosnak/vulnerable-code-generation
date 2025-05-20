//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Base pairs
#define A 0
#define C 1
#define G 2
#define T 3

// Maximum length of a sequence
#define MAX_LENGTH 100

// Probability of a base pair mutation
#define MUTATION_PROBABILITY 0.01

// Function to generate a random base pair
int random_base_pair() {
  int r = rand() % 4;
  return r;
}

// Function to generate a random sequence of base pairs
char* generate_sequence(int length) {
  char* sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int base_pair = random_base_pair();
    switch (base_pair) {
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
  sequence[length] = '\0';
  return sequence;
}

// Function to mutate a sequence of base pairs
char* mutate_sequence(char* sequence, int length) {
  char* mutated_sequence = malloc(length + 1);
  strcpy(mutated_sequence, sequence);
  for (int i = 0; i < length; i++) {
    if ((double)rand() / RAND_MAX < MUTATION_PROBABILITY) {
      int base_pair = random_base_pair();
      switch (base_pair) {
        case A:
          mutated_sequence[i] = 'A';
          break;
        case C:
          mutated_sequence[i] = 'C';
          break;
        case G:
          mutated_sequence[i] = 'G';
          break;
        case T:
          mutated_sequence[i] = 'T';
          break;
      }
    }
  }
  mutated_sequence[length] = '\0';
  return mutated_sequence;
}

// Function to print a sequence of base pairs
void print_sequence(char* sequence) {
  printf("%s\n", sequence);
}

// Function to compare two sequences of base pairs
int compare_sequences(char* sequence1, char* sequence2) {
  int length1 = strlen(sequence1);
  int length2 = strlen(sequence2);
  if (length1 != length2) {
    return -1;
  }
  for (int i = 0; i < length1; i++) {
    if (sequence1[i] != sequence2[i]) {
      return -1;
    }
  }
  return 0;
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random sequence of base pairs
  char* sequence = generate_sequence(MAX_LENGTH);

  // Print the original sequence
  printf("Original sequence:\n");
  print_sequence(sequence);

  // Mutate the sequence
  char* mutated_sequence = mutate_sequence(sequence, MAX_LENGTH);

  // Print the mutated sequence
  printf("Mutated sequence:\n");
  print_sequence(mutated_sequence);

  // Compare the original and mutated sequences
  int result = compare_sequences(sequence, mutated_sequence);
  if (result == 0) {
    printf("The sequences are identical.\n");
  } else {
    printf("The sequences are different.\n");
  }

  // Free the allocated memory
  free(sequence);
  free(mutated_sequence);

  return 0;
}