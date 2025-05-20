//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our secret key
const char KEY[] = "AVENGERS ASSEMBLE!";

// Encrypt a file
void encrypt(const char* inputFile, const char* outputFile) {
  // Open the input and output files
  FILE* input = fopen(inputFile, "rb");
  FILE* output = fopen(outputFile, "wb");

  // Get the file size
  fseek(input, 0, SEEK_END);
  long size = ftell(input);
  fseek(input, 0, SEEK_SET);

  // Create a buffer to store the file data
  char* buffer = malloc(size);

  // Read the file data into the buffer
  fread(buffer, 1, size, input);

  // Encrypt the buffer using our secret key
  for (long i = 0; i < size; i++) {
    buffer[i] ^= KEY[i % strlen(KEY)];
  }

  // Write the encrypted data to the output file
  fwrite(buffer, 1, size, output);

  // Free the buffer
  free(buffer);

  // Close the input and output files
  fclose(input);
  fclose(output);
}

// Decrypt a file
void decrypt(const char* inputFile, const char* outputFile) {
  // Open the input and output files
  FILE* input = fopen(inputFile, "rb");
  FILE* output = fopen(outputFile, "wb");

  // Get the file size
  fseek(input, 0, SEEK_END);
  long size = ftell(input);
  fseek(input, 0, SEEK_SET);

  // Create a buffer to store the file data
  char* buffer = malloc(size);

  // Read the file data into the buffer
  fread(buffer, 1, size, input);

  // Decrypt the buffer using our secret key
  for (long i = 0; i < size; i++) {
    buffer[i] ^= KEY[i % strlen(KEY)];
  }

  // Write the decrypted data to the output file
  fwrite(buffer, 1, size, output);

  // Free the buffer
  free(buffer);

  // Close the input and output files
  fclose(input);
  fclose(output);
}

int main(int argc, char* argv[]) {
  // Check if the user specified the input and output files
  if (argc != 4) {
    printf("Usage: %s <encrypt|decrypt> <input file> <output file>\n", argv[0]);
    return 1;
  }

  // Get the encryption/decryption mode
  char* mode = argv[1];

  // Get the input and output file names
  char* inputFile = argv[2];
  char* outputFile = argv[3];

  // Encrypt or decrypt the file
  if (strcmp(mode, "encrypt") == 0) {
    encrypt(inputFile, outputFile);
  } else if (strcmp(mode, "decrypt") == 0) {
    decrypt(inputFile, outputFile);
  } else {
    printf("Invalid encryption/decryption mode: %s\n", mode);
    return 1;
  }

  // Print a success message
  printf("File %s successfully %s!\n", inputFile, mode);
  return 0;
}