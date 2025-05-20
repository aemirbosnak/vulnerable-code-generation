//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key to be used for encryption
#define KEY 13

// Define the maximum size of the input file
#define MAX_FILE_SIZE 1024

// Function to encrypt a file
int encryptFile(char *inputFile, char *outputFile) {
  // Open the input file
  FILE *fin = fopen(inputFile, "rb");
  if (fin == NULL) {
    perror("Error opening input file");
    return -1;
  }

  // Open the output file
  FILE *fout = fopen(outputFile, "wb");
  if (fout == NULL) {
    perror("Error opening output file");
    return -1;
  }

  // Read the input file into a buffer
  char buffer[MAX_FILE_SIZE];
  size_t bytesRead = fread(buffer, 1, MAX_FILE_SIZE, fin);
  if (bytesRead == 0) {
    perror("Error reading input file");
    return -1;
  }

  // Encrypt the buffer
  for (size_t i = 0; i < bytesRead; i++) {
    buffer[i] = buffer[i] ^ KEY;
  }

  // Write the encrypted buffer to the output file
  fwrite(buffer, 1, bytesRead, fout);
  if (fwrite != bytesRead) {
    perror("Error writing to output file");
    return -1;
  }

  // Close the input and output files
  fclose(fin);
  fclose(fout);

  return 0;
}

// Function to decrypt a file
int decryptFile(char *inputFile, char *outputFile) {
  // Open the input file
  FILE *fin = fopen(inputFile, "rb");
  if (fin == NULL) {
    perror("Error opening input file");
    return -1;
  }

  // Open the output file
  FILE *fout = fopen(outputFile, "wb");
  if (fout == NULL) {
    perror("Error opening output file");
    return -1;
  }

  // Read the input file into a buffer
  char buffer[MAX_FILE_SIZE];
  size_t bytesRead = fread(buffer, 1, MAX_FILE_SIZE, fin);
  if (bytesRead == 0) {
    perror("Error reading input file");
    return -1;
  }

  // Decrypt the buffer
  for (size_t i = 0; i < bytesRead; i++) {
    buffer[i] = buffer[i] ^ KEY;
  }

  // Write the decrypted buffer to the output file
  fwrite(buffer, 1, bytesRead, fout);
  if (fwrite != bytesRead) {
    perror("Error writing to output file");
    return -1;
  }

  // Close the input and output files
  fclose(fin);
  fclose(fout);

  return 0;
}

int main(int argc, char *argv[]) {
  // Check if the user provided the correct number of arguments
  if (argc != 4) {
    printf("Usage: %s <encrypt/decrypt> <input file> <output file>\n", argv[0]);
    return -1;
  }

  // Check if the user wants to encrypt or decrypt the file
  if (strcmp(argv[1], "encrypt") == 0) {
    // Encrypt the file
    if (encryptFile(argv[2], argv[3]) != 0) {
      perror("Error encrypting file");
      return -1;
    }
  } else if (strcmp(argv[1], "decrypt") == 0) {
    // Decrypt the file
    if (decryptFile(argv[2], argv[3]) != 0) {
      perror("Error decrypting file");
      return -1;
    }
  } else {
    printf("Invalid operation. Please specify either \"encrypt\" or \"decrypt\".\n");
    return -1;
  }

  return 0;
}