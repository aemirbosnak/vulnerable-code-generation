//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY 0x42

// Function to encrypt a file
int encrypt_file(char *input_file, char *output_file) {
  // Open the input and output files
  FILE *input = fopen(input_file, "rb");
  if (input == NULL) {
    printf("Error opening input file %s\n", input_file);
    return -1;
  }

  FILE *output = fopen(output_file, "wb");
  if (output == NULL) {
    printf("Error opening output file %s\n", output_file);
    return -1;
  }

  // Read the input file byte by byte
  int c;
  while ((c = getc(input)) != EOF) {
    // XOR the byte with the encryption key
    c ^= KEY;

    // Write the encrypted byte to the output file
    putc(c, output);
  }

  // Close the input and output files
  fclose(input);
  fclose(output);

  return 0;
}

// Function to decrypt a file
int decrypt_file(char *input_file, char *output_file) {
  // Open the input and output files
  FILE *input = fopen(input_file, "rb");
  if (input == NULL) {
    printf("Error opening input file %s\n", input_file);
    return -1;
  }

  FILE *output = fopen(output_file, "wb");
  if (output == NULL) {
    printf("Error opening output file %s\n", output_file);
    return -1;
  }

  // Read the input file byte by byte
  int c;
  while ((c = getc(input)) != EOF) {
    // XOR the byte with the encryption key
    c ^= KEY;

    // Write the decrypted byte to the output file
    putc(c, output);
  }

  // Close the input and output files
  fclose(input);
  fclose(output);

  return 0;
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has provided enough arguments
  if (argc != 4) {
    printf("Usage: %s <encrypt/decrypt> <input_file> <output_file>\n", argv[0]);
    return -1;
  }

  // Get the operation (encrypt or decrypt)
  char *operation = argv[1];

  // Get the input and output file names
  char *input_file = argv[2];
  char *output_file = argv[3];

  // Encrypt or decrypt the file
  int result;
  if (strcmp(operation, "encrypt") == 0) {
    result = encrypt_file(input_file, output_file);
  } else if (strcmp(operation, "decrypt") == 0) {
    result = decrypt_file(input_file, output_file);
  } else {
    printf("Invalid operation: %s\n", operation);
    return -1;
  }

  // Check if the operation was successful
  if (result == 0) {
    printf("File %s successfully %sed!\n", input_file, operation);
  } else {
    printf("Error %sing file %s\n", operation, input_file);
  }

  return result;
}