//Gemma-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_READ_LENGTH 100

typedef struct Read {
  char sequence[MAX_READ_LENGTH];
  int length;
  struct Read* next;
} Read;

Read* createRead(int length) {
  Read* read = malloc(sizeof(Read));
  read->length = length;
  read->sequence[0] = '\0';
  return read;
}

void addSequence(Read* read, char sequence) {
  read->sequence[read->length++] = sequence;
  read->sequence[read->length] = '\0';
}

void printRead(Read* read) {
  printf("Read length: %d\n", read->length);
  printf("Sequence: %s\n", read->sequence);
}

int main() {
  Read* reads = NULL;

  // Create a few reads
  Read* read1 = createRead(10);
  addSequence(read1, 'A');
  addSequence(read1, 'T');
  addSequence(read1, 'C');

  Read* read2 = createRead(12);
  addSequence(read2, 'G');
  addSequence(read2, 'C');
  addSequence(read2, 'T');
  addSequence(read2, 'A');

  // Add reads to the list
  reads = read1;
  reads->next = read2;

  // Print the reads
  printRead(reads);

  return 0;
}