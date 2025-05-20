//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define the encryption key
#define KEY 0x12345678

// Function to encrypt a file
void encryptFile(char *inputFile, char *outputFile) {
  // Open the input file in read mode
  FILE *input = fopen(inputFile, "rb");
  if (input == NULL) {
    perror("Error opening input file");
    exit(1);
  }

  // Open the output file in write mode
  FILE *output = fopen(outputFile, "wb");
  if (output == NULL) {
    perror("Error opening output file");
    exit(1);
  }

  // Read the input file byte by byte
  unsigned char byte;
  while (fread(&byte, sizeof(unsigned char), 1, input) == 1) {
    // Encrypt the byte using the XOR operator
    byte ^= KEY;

    // Write the encrypted byte to the output file
    fwrite(&byte, sizeof(unsigned char), 1, output);
  }

  // Close the input and output files
  fclose(input);
  fclose(output);
}

// Function to decrypt a file
void decryptFile(char *inputFile, char *outputFile) {
  // Open the input file in read mode
  FILE *input = fopen(inputFile, "rb");
  if (input == NULL) {
    perror("Error opening input file");
    exit(1);
  }

  // Open the output file in write mode
  FILE *output = fopen(outputFile, "wb");
  if (output == NULL) {
    perror("Error opening output file");
    exit(1);
  }

  // Read the input file byte by byte
  unsigned char byte;
  while (fread(&byte, sizeof(unsigned char), 1, input) == 1) {
    // Decrypt the byte using the XOR operator
    byte ^= KEY;

    // Write the decrypted byte to the output file
    fwrite(&byte, sizeof(unsigned char), 1, output);
  }

  // Close the input and output files
  fclose(input);
  fclose(output);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided enough arguments
  if (argc < 4) {
    printf("Usage: %s <input file> <output file> <encrypt/decrypt>\n", argv[0]);
    exit(1);
  }

  // Get the input file name
  char *inputFile = argv[1];

  // Get the output file name
  char *outputFile = argv[2];

  // Get the operation (encrypt or decrypt)
  char *operation = argv[3];

  // Encrypt the file
  if (strcmp(operation, "encrypt") == 0) {
    encryptFile(inputFile, outputFile);
  }
  // Decrypt the file
  else if (strcmp(operation, "decrypt") == 0) {
    decryptFile(inputFile, outputFile);
  }
  // Invalid operation
  else {
    printf("Invalid operation: %s\n", operation);
    exit(1);
  }

  // Success
  printf("Operation completed successfully.\n");
  return 0;
}