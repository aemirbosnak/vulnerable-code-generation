//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define READ_LENGTH 100
#define NUM_READS 1000000

// The following array contains the probabilities of each nucleotide occurring in a human genome.
// Adenine: 30.1%, Thymine: 30.1%, Cytosine: 19.8%, Guanine: 19.8%
float probabilities[] = {0.301, 0.301, 0.198, 0.198};

// The following function generates a random nucleotide based on the probabilities defined in the probabilities array.
char generate_nucleotide() {
  float r = (float)rand() / (float)RAND_MAX;
  if (r < probabilities[0]) {
    return 'A';
  } else if (r < probabilities[0] + probabilities[1]) {
    return 'T';
  } else if (r < probabilities[0] + probabilities[1] + probabilities[2]) {
    return 'C';
  } else {
    return 'G';
  }
}

// The following function generates a random read of a given length.
char *generate_read(int length) {
  char *read = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    read[i] = generate_nucleotide();
  }
  read[length] = '\0';
  return read;
}

// The following function writes the generated reads to a file.
void write_reads_to_file(char *filename, char **reads, int num_reads, int read_length) {
  FILE *fp = fopen(filename, "w");
  for (int i = 0; i < num_reads; i++) {
    fprintf(fp, "%s\n", reads[i]);
  }
  fclose(fp);
}

int main() {
  // Set the random seed.
  srand(time(NULL));

  // Generate the reads.
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read(READ_LENGTH);
  }

  // Write the reads to a file.
  write_reads_to_file("reads.txt", reads, NUM_READS, READ_LENGTH);

  // Free the allocated memory.
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}