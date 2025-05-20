//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key.
#define KEY 123

// Define the maximum size of the input file.
#define MAX_FILE_SIZE 1024

// Function to encrypt a file.
void encrypt_file(char *input_file, char *output_file) {
  // Open the input file for reading.
  FILE *input = fopen(input_file, "rb");
  if (input == NULL) {
    perror("Error opening input file");
    exit(EXIT_FAILURE);
  }

  // Open the output file for writing.
  FILE *output = fopen(output_file, "wb");
  if (output == NULL) {
    perror("Error opening output file");
    exit(EXIT_FAILURE);
  }

  // Read the input file into a buffer.
  unsigned char buffer[MAX_FILE_SIZE];
  size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, input);
  if (bytes_read == 0) {
    perror("Error reading input file");
    exit(EXIT_FAILURE);
  }

  // Encrypt the buffer.
  for (size_t i = 0; i < bytes_read; i++) {
    buffer[i] ^= KEY;
  }

  // Write the encrypted buffer to the output file.
  size_t bytes_written = fwrite(buffer, 1, bytes_read, output);
  if (bytes_written != bytes_read) {
    perror("Error writing output file");
    exit(EXIT_FAILURE);
  }

  // Close the input and output files.
  fclose(input);
  fclose(output);
}

// Function to decrypt a file.
void decrypt_file(char *input_file, char *output_file) {
  // Open the input file for reading.
  FILE *input = fopen(input_file, "rb");
  if (input == NULL) {
    perror("Error opening input file");
    exit(EXIT_FAILURE);
  }

  // Open the output file for writing.
  FILE *output = fopen(output_file, "wb");
  if (output == NULL) {
    perror("Error opening output file");
    exit(EXIT_FAILURE);
  }

  // Read the input file into a buffer.
  unsigned char buffer[MAX_FILE_SIZE];
  size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, input);
  if (bytes_read == 0) {
    perror("Error reading input file");
    exit(EXIT_FAILURE);
  }

  // Decrypt the buffer.
  for (size_t i = 0; i < bytes_read; i++) {
    buffer[i] ^= KEY;
  }

  // Write the decrypted buffer to the output file.
  size_t bytes_written = fwrite(buffer, 1, bytes_read, output);
  if (bytes_written != bytes_read) {
    perror("Error writing output file");
    exit(EXIT_FAILURE);
  }

  // Close the input and output files.
  fclose(input);
  fclose(output);
}

// Main function.
int main(int argc, char *argv[]) {
  // Check if the user has provided the correct number of arguments.
  if (argc != 4) {
    fprintf(stderr, "Usage: %s input_file output_file mode\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the mode of operation.
  char *mode = argv[3];
  if (strcmp(mode, "encrypt") != 0 && strcmp(mode, "decrypt") != 0) {
    fprintf(stderr, "Invalid mode: %s\n", mode);
    exit(EXIT_FAILURE);
  }

  // Call the appropriate function to encrypt or decrypt the file.
  if (strcmp(mode, "encrypt") == 0) {
    encrypt_file(argv[1], argv[2]);
  } else {
    decrypt_file(argv[1], argv[2]);
  }

  return EXIT_SUCCESS;
}