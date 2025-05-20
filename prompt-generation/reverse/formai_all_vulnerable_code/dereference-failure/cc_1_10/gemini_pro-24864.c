//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Cyberpunk-style data encryption

// Declare the encryption key
char key[] = "Cyberpunk2077";

// Encrypt a file
void encrypt(char *input_file, char *output_file) {
  // Open the input and output files
  FILE *input = fopen(input_file, "rb");
  FILE *output = fopen(output_file, "wb");

  // Check if the files were opened successfully
  if (input == NULL || output == NULL) {
    printf("Error opening files.\n");
    return;
  }

  // Get the file size
  fseek(input, 0, SEEK_END);
  int file_size = ftell(input);
  rewind(input);

  // Create a buffer to store the file data
  char *buffer = malloc(file_size);

  // Read the file data into the buffer
  fread(buffer, 1, file_size, input);

  // Encrypt the file data
  for (int i = 0; i < file_size; i++) {
    buffer[i] ^= key[i % strlen(key)];
  }

  // Write the encrypted data to the output file
  fwrite(buffer, 1, file_size, output);

  // Free the buffer
  free(buffer);

  // Close the files
  fclose(input);
  fclose(output);
}

// Decrypt a file
void decrypt(char *input_file, char *output_file) {
  // Open the input and output files
  FILE *input = fopen(input_file, "rb");
  FILE *output = fopen(output_file, "wb");

  // Check if the files were opened successfully
  if (input == NULL || output == NULL) {
    printf("Error opening files.\n");
    return;
  }

  // Get the file size
  fseek(input, 0, SEEK_END);
  int file_size = ftell(input);
  rewind(input);

  // Create a buffer to store the file data
  char *buffer = malloc(file_size);

  // Read the file data into the buffer
  fread(buffer, 1, file_size, input);

  // Decrypt the file data
  for (int i = 0; i < file_size; i++) {
    buffer[i] ^= key[i % strlen(key)];
  }

  // Write the decrypted data to the output file
  fwrite(buffer, 1, file_size, output);

  // Free the buffer
  free(buffer);

  // Close the files
  fclose(input);
  fclose(output);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the correct number of arguments were provided
  if (argc != 4) {
    printf("Usage: %s <operation> <input_file> <output_file>\n", argv[0]);
    return 1;
  }

  // Get the operation
  char *operation = argv[1];

  // Get the input and output file names
  char *input_file = argv[2];
  char *output_file = argv[3];

  // Perform the encryption or decryption operation
  if (strcmp(operation, "encrypt") == 0) {
    encrypt(input_file, output_file);
  } else if (strcmp(operation, "decrypt") == 0) {
    decrypt(input_file, output_file);
  } else {
    printf("Invalid operation: %s\n", operation);
    return 1;
  }

  return 0;
}