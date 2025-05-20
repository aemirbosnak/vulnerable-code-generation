//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A happy encryption key
const char* key = "RainbowUnicornsAndFlyingCupcakes";

// Encrypt a file using the happy key
void encryptFile(char* filename) {
  // Open the file for reading
  FILE* inputFile = fopen(filename, "rb");
  if (inputFile == NULL) {
    printf("Couldn't open file: %s\n", filename);
    return;
  }

  // Get the file size
  fseek(inputFile, 0, SEEK_END);
  long fileSize = ftell(inputFile);
  fseek(inputFile, 0, SEEK_SET);

  // Allocate a buffer for the encrypted data
  char* encryptedData = malloc(fileSize);
  if (encryptedData == NULL) {
    printf("Couldn't allocate memory for encrypted data\n");
    return;
  }

  // Read the file data into the buffer
  fread(encryptedData, 1, fileSize, inputFile);

  // Encrypt the data using the happy key
  for (long i = 0; i < fileSize; i++) {
    encryptedData[i] ^= key[i % strlen(key)];
  }

  // Open a new file for writing
  FILE* outputFile = fopen("encrypted.bin", "wb");
  if (outputFile == NULL) {
    printf("Couldn't open file: encrypted.bin\n");
    return;
  }

  // Write the encrypted data to the file
  fwrite(encryptedData, 1, fileSize, outputFile);

  // Close the files
  fclose(inputFile);
  fclose(outputFile);

  // Free the allocated memory
  free(encryptedData);

  // Spread some joy with a happy message
  printf("File encrypted with rainbows and unicorns!\n");
}

int main() {
  // Encrypt a file with a happy name
  encryptFile("happy.txt");

  return 0;
}