//FormAI DATASET v1.0 Category: File Encyptor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This program will encrypt a file using a custom key. It uses XOR encryption to scramble the data.
*/

void encrypt(char *fileName, char *key) {
  FILE *fileIn = fopen(fileName, "rb");
  if (fileIn == NULL) {
    printf("Error: Could not open file.\n");
    return;
  }
  
  char outputFile[256] = "";
  strcat(outputFile, fileName);
  strcat(outputFile, ".encrypted");

  FILE *fileOut = fopen(outputFile, "wb");
  if (fileOut == NULL) {
    printf("Error: Could not create output file.\n");
    fclose(fileIn);
    return;
  }

  int keyIndex = 0;
  int keyLength = strlen(key);
  int currentByte = fgetc(fileIn);
  while (currentByte != EOF) {
    fputc(currentByte ^ key[keyIndex % keyLength], fileOut);
    keyIndex++;
    currentByte = fgetc(fileIn);
  }

  fclose(fileIn);
  fclose(fileOut);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: fileEncryptor [filename] [key]\n");
    return 0;
  }

  char *fileName = argv[1];
  char *key = argv[2];
  int fileNameLength = strlen(fileName);
  if (fileNameLength > 4 && strcmp(&fileName[fileNameLength-4], ".txt") == 0) {
    encrypt(fileName, key);
    printf("File saved as %s.encrypted.\n", fileName);
  } else {
    printf("Error: Only .txt files can be encrypted.\n");
  }

  return 0;
}