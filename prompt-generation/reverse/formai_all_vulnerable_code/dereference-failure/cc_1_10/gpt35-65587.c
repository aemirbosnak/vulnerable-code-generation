//FormAI DATASET v1.0 Category: Data recovery tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <input file> <output file>\n", argv[0]);
    exit(1);
  }

  FILE *inputFile = fopen(argv[1], "r");
  if (inputFile == NULL) {
    printf("Error: Could not open input file %s\n", argv[1]);
    exit(1);
  }

  FILE *outputFile = fopen(argv[2], "w");
  if (outputFile == NULL) {
    printf("Error: Could not open output file %s\n", argv[2]);
    exit(1);
  }

  fseek(inputFile, 0L, SEEK_END);
  long int inputFileSize = ftell(inputFile);
  fseek(inputFile, 0L, SEEK_SET);

  char *inputBuffer = (char *) malloc(inputFileSize);
  if (inputBuffer == NULL) {
    printf("Error: Could not allocate memory for input buffer\n");
    exit(1);
  }

  size_t bytesRead = fread(inputBuffer, 1, inputFileSize, inputFile);
  if (bytesRead != inputFileSize) {
    printf("Error: Could not read input file into buffer\n");
    exit(1);
  }

  char *outputBuffer = (char *) malloc(inputFileSize);
  if (outputBuffer == NULL) {
    printf("Error: Could not allocate memory for output buffer\n");
    exit(1);
  }

  char *marker = "FILE_MARKER";
  size_t markerLength = strlen(marker);

  int currentIndex = 0;
  int outputIndex = 0;
  while (currentIndex < inputFileSize) {
    char *currentChar = &inputBuffer[currentIndex];
    if (strncmp(currentChar, marker, markerLength) == 0) {
      currentIndex += markerLength;
      continue;
    }

    outputBuffer[outputIndex++] = *currentChar;
    currentIndex++;
  }

  size_t bytesWritten = fwrite(outputBuffer, 1, outputIndex, outputFile);
  if (bytesWritten != outputIndex) {
    printf("Error: Could not write output buffer to file\n");
    exit(1);
  }

  fclose(inputFile);
  fclose(outputFile);

  printf("Data recovery complete!\n");

  return 0;
}