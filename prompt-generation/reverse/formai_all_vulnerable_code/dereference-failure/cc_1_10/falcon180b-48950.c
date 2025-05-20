//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_GENOME_LENGTH 1000000
#define MAX_MUTATION_RATE 0.05

typedef struct {
  char *sequence;
  int length;
} Sequence;

Sequence *generate_random_sequence(int length) {
  Sequence *sequence = malloc(sizeof(Sequence));
  sequence->length = length;
  sequence->sequence = malloc(length + 1);

  for (int i = 0; i < length; i++) {
    sequence->sequence[i] = 'A' + rand() % 4;
  }
  sequence->sequence[length] = '\0';

  return sequence;
}

void print_sequence(Sequence *sequence) {
  printf("%s\n", sequence->sequence);
}

void mutate_sequence(Sequence *sequence, double mutation_rate) {
  for (int i = 0; i < sequence->length; i++) {
    if (rand() % 100 < mutation_rate * 100) {
      sequence->sequence[i] = 'A' + rand() % 4;
    }
  }
}

int main() {
  srand(time(NULL));

  Sequence *genome = generate_random_sequence(MAX_GENOME_LENGTH);
  printf("Original genome:\n");
  print_sequence(genome);

  int num_mutations = 0;

  for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
    if (rand() % 100 < MAX_MUTATION_RATE * 100) {
      int position = rand() % genome->length;
      genome->sequence[position] = 'A' + rand() % 4;
      num_mutations++;
    }
  }

  printf("\nGenome after %d mutations:\n", num_mutations);
  print_sequence(genome);

  free(genome->sequence);
  free(genome);

  return 0;
}