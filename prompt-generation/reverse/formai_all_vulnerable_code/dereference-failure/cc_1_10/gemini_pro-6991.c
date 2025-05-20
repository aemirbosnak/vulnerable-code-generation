//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "MySecretEncryptionKey"

// Function to encrypt a file
void encryptFile(char *fileName) {
  // Open the file in read mode
  FILE *inputFile = fopen(fileName, "r");
  if (inputFile == NULL) {
    perror("Error opening the input file");
    exit(1);
  }

  // Open the file in write mode
  FILE *outputFile = fopen("encrypted.txt", "w");
  if (outputFile == NULL) {
    perror("Error opening the output file");
    exit(1);
  }

  // Get the file size
  fseek(inputFile, 0, SEEK_END);
  long fileSize = ftell(inputFile);
  rewind(inputFile);

  // Create a buffer to store the file contents
  char *buffer = malloc(fileSize);
  if (buffer == NULL) {
    perror("Error allocating memory for the buffer");
    exit(1);
  }

  // Read the file contents into the buffer
  fread(buffer, fileSize, 1, inputFile);

  // Encrypt the file contents
  for (int i = 0; i < fileSize; i++) {
    buffer[i] ^= KEY[i % strlen(KEY)];
  }

  // Write the encrypted contents to the output file
  fwrite(buffer, fileSize, 1, outputFile);

  // Free the memory allocated for the buffer
  free(buffer);

  // Close the input and output files
  fclose(inputFile);
  fclose(outputFile);
}

// Function to decrypt a file
void decryptFile(char *fileName) {
  // Open the file in read mode
  FILE *inputFile = fopen(fileName, "r");
  if (inputFile == NULL) {
    perror("Error opening the input file");
    exit(1);
  }

  // Open the file in write mode
  FILE *outputFile = fopen("decrypted.txt", "w");
  if (outputFile == NULL) {
    perror("Error opening the output file");
    exit(1);
  }

  // Get the file size
  fseek(inputFile, 0, SEEK_END);
  long fileSize = ftell(inputFile);
  rewind(inputFile);

  // Create a buffer to store the file contents
  char *buffer = malloc(fileSize);
  if (buffer == NULL) {
    perror("Error allocating memory for the buffer");
    exit(1);
  }

  // Read the file contents into the buffer
  fread(buffer, fileSize, 1, inputFile);

  // Decrypt the file contents
  for (int i = 0; i < fileSize; i++) {
    buffer[i] ^= KEY[i % strlen(KEY)];
  }

  // Write the decrypted contents to the output file
  fwrite(buffer, fileSize, 1, outputFile);

  // Free the memory allocated for the buffer
  free(buffer);

  // Close the input and output files
  fclose(inputFile);
  fclose(outputFile);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a file name
  if (argc != 2) {
    printf("Usage: %s <file name>\n", argv[0]);
    exit(1);
  }

  // Get the file name from the command line
  char *fileName = argv[1];

  // Encrypt the file
  encryptFile(fileName);

  // Decrypt the file
  decryptFile("encrypted.txt");

  // Print a success message
  printf("File encrypted and decrypted successfully!\n");

  return 0;
}