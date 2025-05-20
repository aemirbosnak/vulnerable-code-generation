//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_SIZE 100
#define MUTATION_CHANCE 5

// Function to generate a random genome sequence
char *generateSequence(int size) {
  char *sequence = (char*) malloc(sizeof(char) * (size + 1));
  char bases[] = {'A', 'T', 'C', 'G'};
  srand(time(NULL));

  for (int i = 0; i < size; i++) {
    sequence[i] = bases[rand() % 4];
  }

  sequence[size] = '\0';
  return sequence;
}

// Function to mutate a given genome sequence
char *mutateSequence(char *sequence) {
  int size = strlen(sequence);
  char *mutatedSeq = (char*) malloc(sizeof(char) * (size + 1));

  for (int i = 0; i < size; i++) {
    if (rand() % 100 < MUTATION_CHANCE) {
      char base = sequence[i];
      do {
        mutatedSeq[i] = (rand() % 4) + 'A';
      } while (mutatedSeq[i] == base);
    } else {
      mutatedSeq[i] = sequence[i];
    }
  }

  mutatedSeq[size] = '\0';
  return mutatedSeq;
}

// Function to print genome sequence
void printSequence(char *sequence) {
  printf("Sequence: %s\n", sequence);
}

int main() {
  char *genome = generateSequence(GENOME_SIZE);
  printSequence(genome);

  genome = mutateSequence(genome);
  printSequence(genome);

  free(genome);
  return 0;
}