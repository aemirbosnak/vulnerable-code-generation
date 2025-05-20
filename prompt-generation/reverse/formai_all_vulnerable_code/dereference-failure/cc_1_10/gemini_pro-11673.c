//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file using a simple XOR cipher
void encrypt_file(char *input_file, char *output_file, char *key) {
  // Open the input file
  FILE *input = fopen(input_file, "rb");
  if (input == NULL) {
    perror("Error opening input file");
    exit(EXIT_FAILURE);
  }

  // Open the output file
  FILE *output = fopen(output_file, "wb");
  if (output == NULL) {
    perror("Error opening output file");
    exit(EXIT_FAILURE);
  }

  // Read the key
  int key_len = strlen(key);

  // Read the input file and encrypt it
  int ch;
  int key_index = 0;
  while ((ch = fgetc(input)) != EOF) {
    // XOR the character with the key
    ch ^= key[key_index];

    // Increment the key index
    key_index = (key_index + 1) % key_len;

    // Write the encrypted character to the output file
    fputc(ch, output);
  }

  // Close the input and output files
  fclose(input);
  fclose(output);
}

// Function to decrypt a file using a simple XOR cipher
void decrypt_file(char *input_file, char *output_file, char *key) {
  // Open the input file
  FILE *input = fopen(input_file, "rb");
  if (input == NULL) {
    perror("Error opening input file");
    exit(EXIT_FAILURE);
  }

  // Open the output file
  FILE *output = fopen(output_file, "wb");
  if (output == NULL) {
    perror("Error opening output file");
    exit(EXIT_FAILURE);
  }

  // Read the key
  int key_len = strlen(key);

  // Read the input file and decrypt it
  int ch;
  int key_index = 0;
  while ((ch = fgetc(input)) != EOF) {
    // XOR the character with the key
    ch ^= key[key_index];

    // Increment the key index
    key_index = (key_index + 1) % key_len;

    // Write the decrypted character to the output file
    fputc(ch, output);
  }

  // Close the input and output files
  fclose(input);
  fclose(output);
}

// Main function
int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 5) {
    printf("Usage: %s <input_file> <output_file> <key> <encrypt/decrypt>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the input file name
  char *input_file = argv[1];

  // Get the output file name
  char *output_file = argv[2];

  // Get the key
  char *key = argv[3];

  // Get the operation (encrypt or decrypt)
  char *operation = argv[4];

  // Check if the operation is valid
  if (strcmp(operation, "encrypt") != 0 && strcmp(operation, "decrypt") != 0) {
    printf("Invalid operation: %s\n", operation);
    exit(EXIT_FAILURE);
  }

  // Perform the encryption or decryption
  if (strcmp(operation, "encrypt") == 0) {
    encrypt_file(input_file, output_file, key);
  } else {
    decrypt_file(input_file, output_file, key);
  }

  return EXIT_SUCCESS;
}