//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_LEN 1024
#define MAX_SEQS 1000
#define MAX_SEQ_LEN 1000

const char *bases = "ACGT";

// Generate a random DNA sequence of the specified length
char *generate_sequence(int len) {
  char *seq = (char *)malloc(sizeof(char) * (len + 1));
  for (int i = 0; i < len; i++) {
    seq[i] = bases[rand() % 4];
  }
  seq[len] = '\0';
  return seq;
}

// Write a DNA sequence to a file
void write_sequence(char *seq, char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }
  fprintf(fp, "%s\n", seq);
  fclose(fp);
}

int main(int argc, char **argv) {
  // Check for proper usage
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <num_seqs> <seq_len> <output_file>\n", argv[0]);
    exit(1);
  }

  // Parse command line arguments
  int num_seqs = atoi(argv[1]);
  int seq_len = atoi(argv[2]);
  char *output_file = argv[3];

  // Initialize random number generator
  srand(time(NULL));

  // Generate DNA sequences
  char **seqs = (char **)malloc(sizeof(char *) * num_seqs);
  for (int i = 0; i < num_seqs; i++) {
    seqs[i] = generate_sequence(seq_len);
  }

  // Write DNA sequences to file
  for (int i = 0; i < num_seqs; i++) {
    char filename[BUF_LEN];
    sprintf(filename, "%s_%d.fasta", output_file, i);
    write_sequence(seqs[i], filename);
  }

  // Free memory
  for (int i = 0; i < num_seqs; i++) {
    free(seqs[i]);
  }
  free(seqs);

  return 0;
}