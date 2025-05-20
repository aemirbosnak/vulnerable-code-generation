//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PAR_COUNT 5

typedef struct {
  char *name;
  int length;
  char *sequence;
} chromosome;

chromosome *chromosomes;
int num_chromosomes;

void init_chromosomes() {
  // Initialize the chromosomes array
  chromosomes = (chromosome *)malloc(sizeof(chromosome) * PAR_COUNT);
  num_chromosomes = PAR_COUNT;

  // Initialize the chromosomes
  for (int i = 0; i < num_chromosomes; i++) {
    chromosomes[i].name = (char *)malloc(sizeof(char) * 10);
    sprintf(chromosomes[i].name, "chr%d", i + 1);
    chromosomes[i].length = 10000;
    chromosomes[i].sequence = (char *)malloc(sizeof(char) * chromosomes[i].length);
  }
}

void generate_sequence(chromosome *chrom) {
  // Generate a random sequence of nucleotides
  for (int i = 0; i < chrom->length; i++) {
    int rand_num = rand() % 4;
    switch (rand_num) {
      case 0:
        chrom->sequence[i] = 'A';
        break;
      case 1:
        chrom->sequence[i] = 'C';
        break;
      case 2:
        chrom->sequence[i] = 'G';
        break;
      case 3:
        chrom->sequence[i] = 'T';
        break;
    }
  }
}

void print_chromosome(chromosome *chrom) {
  // Print the chromosome name and sequence
  printf("%s\n", chrom->name);
  for (int i = 0; i < chrom->length; i++) {
    printf("%c", chrom->sequence[i]);
  }
  printf("\n");
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the chromosomes
  init_chromosomes();

  // Generate the sequences for each chromosome
  for (int i = 0; i < num_chromosomes; i++) {
    generate_sequence(&chromosomes[i]);
  }

  // Print the chromosomes
  for (int i = 0; i < num_chromosomes; i++) {
    print_chromosome(&chromosomes[i]);
  }

  // Free the memory allocated for the chromosomes
  for (int i = 0; i < num_chromosomes; i++) {
    free(chromosomes[i].name);
    free(chromosomes[i].sequence);
  }
  free(chromosomes);

  return 0;
}