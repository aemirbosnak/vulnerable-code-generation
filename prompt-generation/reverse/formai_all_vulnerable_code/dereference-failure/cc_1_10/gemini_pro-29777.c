//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Base pair probabilities. */
#define PROB_A 0.25
#define PROB_C 0.25
#define PROB_G 0.25
#define PROB_T 0.25

/* Read length. */
#define READ_LENGTH 100

/* Number of reads. */
#define NUM_READS 10000

/* Generate a random base pair. */
char generate_base_pair() {
  double r = (double)rand() / RAND_MAX;
  if (r < PROB_A) {
    return 'A';
  } else if (r < PROB_A + PROB_C) {
    return 'C';
  } else if (r < PROB_A + PROB_C + PROB_G) {
    return 'G';
  } else {
    return 'T';
  }
}

/* Generate a random read. */
char *generate_read() {
  char *read = malloc(READ_LENGTH + 1);
  for (int i = 0; i < READ_LENGTH; i++) {
    read[i] = generate_base_pair();
  }
  read[READ_LENGTH] = '\0';
  return read;
}

/* Generate a set of reads. */
char **generate_reads(int num_reads) {
  char **reads = malloc(num_reads * sizeof(char *));
  for (int i = 0; i < num_reads; i++) {
    reads[i] = generate_read();
  }
  return reads;
}

/* Write reads to a file. */
void write_reads_to_file(char **reads, int num_reads, char *filename) {
  FILE *fp = fopen(filename, "w");
  for (int i = 0; i < num_reads; i++) {
    fprintf(fp, "%s\n", reads[i]);
  }
  fclose(fp);
}

/* Free reads. */
void free_reads(char **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    free(reads[i]);
  }
  free(reads);
}

int main() {
  srand(time(NULL));

  char **reads = generate_reads(NUM_READS);
  write_reads_to_file(reads, NUM_READS, "reads.txt");
  free_reads(reads, NUM_READS);

  return 0;
}