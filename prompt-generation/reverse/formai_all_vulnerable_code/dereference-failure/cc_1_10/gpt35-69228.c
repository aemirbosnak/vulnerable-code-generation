//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scanFile(char *fileName);

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <file name>\n", argv[0]);
    return 1;
  }

  char *fileName = argv[1];

  scanFile(fileName);

  return 0;
}

void scanFile(char *fileName) {
  char *virusSignature = "W32/Virus123";

  FILE *fp = fopen(fileName, "r");
  if (fp == NULL) {
    printf("File %s does not exist\n", fileName);
    return;
  }

  // Determine the file size
  fseek(fp, 0L, SEEK_END);
  long fileSize = ftell(fp);
  rewind(fp);

  // Read the whole file into memory
  char *buffer = (char *) malloc(fileSize * sizeof(char));
  size_t bytesRead = fread(buffer, sizeof(char), fileSize, fp);

  int virusFound = 0;

  // Search for the virus signature
  char *position = strstr(buffer, virusSignature);
  if (position != NULL) {
    virusFound = 1;
  }

  free(buffer);
  fclose(fp);

  if (virusFound) {
    printf("Virus found in %s\n", fileName);
  } else {
    printf("%s is clean\n", fileName);
  }
}