//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct { char dna[50]; int length; } genome;

void mutate(genome *g) {
  int i, pos, base;
  char old = g->dna[rand() % g->length];

  if (old == 'A') base = 'C';
  if (old == 'C') base = 'G';
  if (old == 'G') base = 'A';
  if (old == 'T') base = 'T';
  if (old == 'X') base = rand() % 4 + 'A';

  pos = rand() % g->length;
  g->dna[pos] = base;
  g->length = g->length + (base == 'X' ? rand() % 3 - 1 : 0);
}

genome read_sequence(char *filename) {
  FILE *fp;
  char line[51], strand[51];
  int i, len = 0;
  genome seq;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Could not open %s\n", filename);
    exit(EXIT_FAILURE);
  }

  while (fgets(line, sizeof line, fp)) {
    strcpy(strand, line);
    for (i = 0; i < strlen(strand) && len < 50; i++) {
      seq.dna[len++] = strand[i];
    }
  }

  seq.length = len;
  fclose(fp);

  return seq;
}

void print_sequence(genome g) {
  int i;

  for (i = 0; i < g.length; i++) printf("%c", g.dna[i]);
  printf("\nLength: %d\n", g.length);
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  int i, generations = atoi(argv[1]), mutations_per_genome = atoi(argv[2]);
  genome parent1, parent2, offspring;

  parent1 = read_sequence(argv[3]);
  parent2 = read_sequence(argv[4]);

  for (i = 0; i < generations; i++) {
    mutate(&parent1);
    mutate(&parent2);

    offspring = parent1;
    strcpy(offspring.dna + offspring.length, parent2.dna);
    offspring.length += parent2.length;

    print_sequence(parent1);
    print_sequence(parent2);
    print_sequence(offspring);

    parent1 = offspring;
  }

  for (i = 0; i < mutations_per_genome; i++) mutate(&parent1);

  printf("Final sequence after %d mutations:\n", mutations_per_genome);
  print_sequence(parent1);

  return EXIT_SUCCESS;
}