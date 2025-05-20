//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encryptFile(char *fileName, char *key) {
  // Open the file to be encrypted
  FILE *inputFile = fopen(fileName, "rb");
  if (inputFile == NULL) {
    perror("Error opening input file");
    exit(1);
  }

  // Create a new file to store the encrypted data
  char outputFileName[strlen(fileName) + 5];
  strcpy(outputFileName, fileName);
  strcat(outputFileName, ".enc");
  FILE *outputFile = fopen(outputFileName, "wb");
  if (outputFile == NULL) {
    perror("Error opening output file");
    exit(1);
  }

  // Read the input file and encrypt each byte
  int ch;
  while ((ch = fgetc(inputFile)) != EOF) {
    // Get the corresponding key byte
    int keyByte = key[(int)ch % strlen(key)];

    // Encrypt the byte by XORing it with the key byte
    int encryptedByte = ch ^ keyByte;

    // Write the encrypted byte to the output file
    fputc(encryptedByte, outputFile);
  }

  // Close the input and output files
  fclose(inputFile);
  fclose(outputFile);
}

// Function to decrypt a file
void decryptFile(char *fileName, char *key) {
  // Open the file to be decrypted
  FILE *inputFile = fopen(fileName, "rb");
  if (inputFile == NULL) {
    perror("Error opening input file");
    exit(1);
  }

  // Create a new file to store the decrypted data
  char outputFileName[strlen(fileName) - 4];
  strncpy(outputFileName, fileName, strlen(fileName) - 4);
  FILE *outputFile = fopen(outputFileName, "wb");
  if (outputFile == NULL) {
    perror("Error opening output file");
    exit(1);
  }

  // Read the input file and decrypt each byte
  int ch;
  while ((ch = fgetc(inputFile)) != EOF) {
    // Get the corresponding key byte
    int keyByte = key[(int)ch % strlen(key)];

    // Decrypt the byte by XORing it with the key byte
    int decryptedByte = ch ^ keyByte;

    // Write the decrypted byte to the output file
    fputc(decryptedByte, outputFile);
  }

  // Close the input and output files
  fclose(inputFile);
  fclose(outputFile);
}

// Main function
int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 4) {
    printf("Usage: %s <encrypt|decrypt> <input file> <key>\n", argv[0]);
    exit(1);
  }

  // Get the operation to be performed
  char *operation = argv[1];

  // Get the input file name
  char *fileName = argv[2];

  // Get the key
  char *key = argv[3];

  // Check if the key is valid
  if (strlen(key) == 0) {
    printf("Invalid key\n");
    exit(1);
  }

  // Perform the encryption or decryption
  if (strcmp(operation, "encrypt") == 0) {
    encryptFile(fileName, key);
  } else if (strcmp(operation, "decrypt") == 0) {
    decryptFile(fileName, key);
  } else {
    printf("Invalid operation\n");
    exit(1);
  }

  return 0;
}