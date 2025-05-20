//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a file
void encryptFile(char *fileName) {
  // Open the file in read mode
  FILE *inputFile = fopen(fileName, "r");
  if (inputFile == NULL) {
    printf("Error opening file %s\n", fileName);
    return;
  }

  // Open the file in write mode
  FILE *outputFile = fopen("encrypted.txt", "w");
  if (outputFile == NULL) {
    printf("Error opening file encrypted.txt\n");
    return;
  }

  // Read the file character by character
  char ch;
  while ((ch = fgetc(inputFile)) != EOF) {
    // Encrypt the character
    ch ^= 0x55;

    // Write the encrypted character to the output file
    fputc(ch, outputFile);
  }

  // Close the input and output files
  fclose(inputFile);
  fclose(outputFile);
}

// Function to decrypt a file
void decryptFile(char *fileName) {
  // Open the file in read mode
  FILE *inputFile = fopen(fileName, "r");
  if (inputFile == NULL) {
    printf("Error opening file %s\n", fileName);
    return;
  }

  // Open the file in write mode
  FILE *outputFile = fopen("decrypted.txt", "w");
  if (outputFile == NULL) {
    printf("Error opening file decrypted.txt\n");
    return;
  }

  // Read the file character by character
  char ch;
  while ((ch = fgetc(inputFile)) != EOF) {
    // Decrypt the character
    ch ^= 0x55;

    // Write the decrypted character to the output file
    fputc(ch, outputFile);
  }

  // Close the input and output files
  fclose(inputFile);
  fclose(outputFile);
}

// Main function
int main() {
  // Encrypt the file
  encryptFile("plaintext.txt");

  // Decrypt the file
  decryptFile("encrypted.txt");

  return 0;
}