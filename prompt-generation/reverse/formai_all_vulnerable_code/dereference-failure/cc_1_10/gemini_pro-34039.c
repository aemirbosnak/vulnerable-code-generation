//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 10000

// Function to generate a random nucleotide
char generateNucleotide() {
  int randNum = rand() % 4;
  switch (randNum) {
    case 0:
      return 'A';
    case 1:
      return 'C';
    case 2:
      return 'G';
    case 3:
      return 'T';
  }
}

// Function to generate a random read
char* generateRead(int length) {
  char* read = (char*)malloc(length + 1);
  for (int i = 0; i < length; i++) {
    read[i] = generateNucleotide();
  }
  read[length] = '\0';
  return read;
}

// Function to simulate C genome sequencing
char** simulateSequencing(int numReads, int readLength) {
  char** reads = (char**)malloc(numReads * sizeof(char*));
  for (int i = 0; i < numReads; i++) {
    reads[i] = generateRead(readLength);
  }
  return reads;
}

// Function to print the reads
void printReads(char** reads, int numReads, int readLength) {
  for (int i = 0; i < numReads; i++) {
    printf("Read %d: ", i + 1);
    for (int j = 0; j < readLength; j++) {
      printf("%c", reads[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int numReads = 100;
  int readLength = 100;
  char** reads = simulateSequencing(numReads, readLength);
  printReads(reads, numReads, readLength);
  return 0;
}