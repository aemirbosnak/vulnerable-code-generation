//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
const char key[] = "YourEncryptionKey";

// Function to encrypt a file
void encryptFile(const char *fileName) {
  // Open the file to be encrypted
  FILE *inputFile = fopen(fileName, "rb");
  if (inputFile == NULL) {
    printf("Error opening input file.\n");
    return;
  }

  // Open the output file where the encrypted data will be stored
  char outputFileName[256];
  strcpy(outputFileName, fileName);
  strcat(outputFileName, ".enc");
  FILE *outputFile = fopen(outputFileName, "wb");
  if (outputFile == NULL) {
    printf("Error opening output file.\n");
    return;
  }

  // Read the input file in blocks
  const size_t blockSize = 1024;
  unsigned char buffer[blockSize];
  size_t bytesRead;
  while ((bytesRead = fread(buffer, sizeof(unsigned char), blockSize, inputFile)) > 0) {
    // Encrypt the block of data
    for (size_t i = 0; i < bytesRead; i++) {
      buffer[i] ^= key[i % strlen(key)];
    }

    // Write the encrypted block to the output file
    fwrite(buffer, sizeof(unsigned char), bytesRead, outputFile);
  }

  // Close the input and output files
  fclose(inputFile);
  fclose(outputFile);

  printf("File encrypted successfully.\n");
}

// Function to decrypt a file
void decryptFile(const char *fileName) {
  // Open the file to be decrypted
  FILE *inputFile = fopen(fileName, "rb");
  if (inputFile == NULL) {
    printf("Error opening input file.\n");
    return;
  }

  // Open the output file where the decrypted data will be stored
  char outputFileName[256];
  strcpy(outputFileName, fileName);
  strcat(outputFileName, ".dec");
  FILE *outputFile = fopen(outputFileName, "wb");
  if (outputFile == NULL) {
    printf("Error opening output file.\n");
    return;
  }

  // Read the input file in blocks
  const size_t blockSize = 1024;
  unsigned char buffer[blockSize];
  size_t bytesRead;
  while ((bytesRead = fread(buffer, sizeof(unsigned char), blockSize, inputFile)) > 0) {
    // Decrypt the block of data
    for (size_t i = 0; i < bytesRead; i++) {
      buffer[i] ^= key[i % strlen(key)];
    }

    // Write the decrypted block to the output file
    fwrite(buffer, sizeof(unsigned char), bytesRead, outputFile);
  }

  // Close the input and output files
  fclose(inputFile);
  fclose(outputFile);

  printf("File decrypted successfully.\n");
}

// Main function
int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s <encrypt/decrypt> <file_name>\n", argv[0]);
    return 1;
  }

  const char *operation = argv[1];
  const char *fileName = argv[2];

  if (strcmp(operation, "encrypt") == 0) {
    encryptFile(fileName);
  } else if (strcmp(operation, "decrypt") == 0) {
    decryptFile(fileName);
  } else {
    printf("Invalid operation. Please specify either 'encrypt' or 'decrypt'.\n");
  }

  return 0;
}