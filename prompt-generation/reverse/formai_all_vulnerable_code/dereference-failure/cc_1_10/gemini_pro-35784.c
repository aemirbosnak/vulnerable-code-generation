//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 1000

// Generate a random DNA sequence of length 'len'.
char *generate_dna(int len) {
  char *seq = (char *)malloc(sizeof(char) * (len + 1));
  for (int i = 0; i < len; i++) {
    int rand_num = rand() % 4;
    switch (rand_num) {
    case 0:
      seq[i] = 'A';
      break;
    case 1:
      seq[i] = 'C';
      break;
    case 2:
      seq[i] = 'G';
      break;
    case 3:
      seq[i] = 'T';
      break;
    }
  }
  seq[len] = '\0';
  return seq;
}

// Print the DNA sequence 'seq'.
void print_dna(char *seq) {
  printf("%s\n", seq);
}

// Generate a random number between 'min' and 'max'.
int rand_range(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Generate a random read of length 'len' from the DNA sequence 'seq'.
char *generate_read(char *seq, int len) {
  int start = rand_range(0, strlen(seq) - len);
  char *read = (char *)malloc(sizeof(char) * (len + 1));
  strncpy(read, seq + start, len);
  read[len] = '\0';
  return read;
}

// Read a DNA sequence from a file.
char *read_dna(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }
  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char *seq = (char *)malloc(sizeof(char) * (fsize + 1));
  fread(seq, fsize, 1, fp);
  fclose(fp);
  seq[fsize] = '\0';
  return seq;
}

// Write a DNA sequence to a file.
void write_dna(char *seq, char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }
  fwrite(seq, strlen(seq), 1, fp);
  fclose(fp);
}

// Generate a random set of reads from the DNA sequence 'seq'.
char **generate_reads(char *seq, int num_reads, int read_len) {
  char **reads = (char **)malloc(sizeof(char *) * num_reads);
  for (int i = 0; i < num_reads; i++) {
    reads[i] = generate_read(seq, read_len);
  }
  return reads;
}

// Print a set of reads.
void print_reads(char **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    printf("%s\n", reads[i]);
  }
}

// Free a set of reads.
void free_reads(char **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    free(reads[i]);
  }
  free(reads);
}

// Main function.
int main() {
  // Set the random seed.
  srand(time(NULL));

  // Generate a DNA sequence of length 1000.
  char *seq = generate_dna(1000);

  // Print the DNA sequence.
  print_dna(seq);

  // Generate a set of 100 reads of length 100 from the DNA sequence.
  char **reads = generate_reads(seq, 100, 100);

  // Print the set of reads.
  print_reads(reads, 100);

  // Free the set of reads.
  free_reads(reads, 100);

  // Free the DNA sequence.
  free(seq);

  return 0;
}