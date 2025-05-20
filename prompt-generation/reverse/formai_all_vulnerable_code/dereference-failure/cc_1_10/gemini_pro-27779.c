//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random DNA sequence
char* generateDNA(int length) {
  char* sequence = (char*)malloc(length + 1);  // +1 for the null terminator
  for (int i = 0; i < length; i++) {
    int randomNum = rand() % 4;
    switch (randomNum) {
      case 0:
        sequence[i] = 'A';
        break;
      case 1:
        sequence[i] = 'C';
        break;
      case 2:
        sequence[i] = 'G';
        break;
      case 3:
        sequence[i] = 'T';
        break;
    }
  }
  sequence[length] = '\0';  // Add the null terminator
  return sequence;
}

// Function to simulate the sequencing process
char** simulateSequencing(char* DNA, int readLength) {
  int numReads = (int)ceil((float)strlen(DNA) / readLength);
  char** reads = (char**)malloc(numReads * sizeof(char*));
  for (int i = 0; i < numReads; i++) {
    reads[i] = (char*)malloc(readLength + 1);
    int startPos = i * readLength;
    for (int j = 0; j < readLength; j++) {
      if (startPos + j < strlen(DNA)) {
        reads[i][j] = DNA[startPos + j];
      } else {
        reads[i][j] = 'N';  // Represent unknown bases as 'N'
      }
    }
    reads[i][readLength] = '\0';
  }
  return reads;
}

// Function to print the reads
void printReads(char** reads, int numReads, int readLength) {
  for (int i = 0; i < numReads; i++) {
    for (int j = 0; j < readLength; j++) {
      printf("%c", reads[i][j]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));  // Initialize the random number generator

  // Generate a random DNA sequence
  int DNA_length = 1000;
  char* DNA = generateDNA(DNA_length);

  // Simulate the sequencing process
  int readLength = 100;
  char** reads = simulateSequencing(DNA, readLength);

  int numReads = (int)ceil((float)strlen(DNA) / readLength);

  // Print the reads
  printf("DNA sequence:\n%s\n\n", DNA);
  printf("Simulated reads (length %d):\n", readLength);
  printReads(reads, numReads, readLength);

  // Free the allocated memory
  free(DNA);
  for (int i = 0; i < numReads; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}