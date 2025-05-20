//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define ENCRYPTION_KEY "AdaLovelace"

// Function to encrypt a file
void encryptFile(FILE *inputFile, FILE *outputFile) {
  // Get the file size
  fseek(inputFile, 0, SEEK_END);
  long fileSize = ftell(inputFile);
  rewind(inputFile);

  // Read the file into a buffer
  char *buffer = malloc(fileSize);
  fread(buffer, fileSize, 1, inputFile);

  // Encrypt the buffer using XOR encryption
  for (int i = 0; i < fileSize; i++) {
    buffer[i] ^= ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
  }

  // Write the encrypted buffer to the output file
  fwrite(buffer, fileSize, 1, outputFile);
  free(buffer);
}

// Function to decrypt a file
void decryptFile(FILE *inputFile, FILE *outputFile) {
  // Get the file size
  fseek(inputFile, 0, SEEK_END);
  long fileSize = ftell(inputFile);
  rewind(inputFile);

  // Read the file into a buffer
  char *buffer = malloc(fileSize);
  fread(buffer, fileSize, 1, inputFile);

  // Decrypt the buffer using XOR encryption
  for (int i = 0; i < fileSize; i++) {
    buffer[i] ^= ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
  }

  // Write the decrypted buffer to the output file
  fwrite(buffer, fileSize, 1, outputFile);
  free(buffer);
}

// Main function
int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s encrypt|decrypt inputFile outputFile\n", argv[0]);
    return 1;
  }

  // Open the input and output files
  FILE *inputFile = fopen(argv[2], "rb");
  if (inputFile == NULL) {
    printf("Error opening input file: %s\n", argv[2]);
    return 1;
  }

  FILE *outputFile = fopen(argv[3], "wb");
  if (outputFile == NULL) {
    printf("Error opening output file: %s\n", argv[3]);
    return 1;
  }

  // Encrypt or decrypt the file
  if (strcmp(argv[1], "encrypt") == 0) {
    encryptFile(inputFile, outputFile);
  } else if (strcmp(argv[1], "decrypt") == 0) {
    decryptFile(inputFile, outputFile);
  } else {
    printf("Invalid operation: %s\n", argv[1]);
    return 1;
  }

  // Close the files
  fclose(inputFile);
  fclose(outputFile);

  return 0;
}