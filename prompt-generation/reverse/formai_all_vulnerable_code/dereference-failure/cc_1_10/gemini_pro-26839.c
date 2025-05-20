//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the encryption key
#define KEY "MySuperSecretEncryptionKey"

// Function to encrypt a file
void encrypt_file(char *input_file, char *output_file) {
  // Open the input file in read mode
  FILE *input = fopen(input_file, "rb");
  if (input == NULL) {
    printf("Error opening input file %s\n", input_file);
    exit(1);
  }

  // Open the output file in write mode
  FILE *output = fopen(output_file, "wb");
  if (output == NULL) {
    printf("Error opening output file %s\n", output_file);
    exit(1);
  }

  // Read the input file into a buffer
  fseek(input, 0, SEEK_END);
  long file_size = ftell(input);
  rewind(input);

  char *buffer = malloc(file_size);
  if (buffer == NULL) {
    printf("Error allocating memory for buffer\n");
    exit(1);
  }

  fread(buffer, file_size, 1, input);

  // Encrypt the buffer
  int key_len = strlen(KEY);
  for (long i = 0; i < file_size; i++) {
    buffer[i] ^= KEY[i % key_len];
  }

  // Write the encrypted buffer to the output file
  fwrite(buffer, file_size, 1, output);

  // Free the buffer
  free(buffer);

  // Close the input and output files
  fclose(input);
  fclose(output);
}

// Function to decrypt a file
void decrypt_file(char *input_file, char *output_file) {
  // Open the input file in read mode
  FILE *input = fopen(input_file, "rb");
  if (input == NULL) {
    printf("Error opening input file %s\n", input_file);
    exit(1);
  }

  // Open the output file in write mode
  FILE *output = fopen(output_file, "wb");
  if (output == NULL) {
    printf("Error opening output file %s\n", output_file);
    exit(1);
  }

  // Read the input file into a buffer
  fseek(input, 0, SEEK_END);
  long file_size = ftell(input);
  rewind(input);

  char *buffer = malloc(file_size);
  if (buffer == NULL) {
    printf("Error allocating memory for buffer\n");
    exit(1);
  }

  fread(buffer, file_size, 1, input);

  // Decrypt the buffer
  int key_len = strlen(KEY);
  for (long i = 0; i < file_size; i++) {
    buffer[i] ^= KEY[i % key_len];
  }

  // Write the decrypted buffer to the output file
  fwrite(buffer, file_size, 1, output);

  // Free the buffer
  free(buffer);

  // Close the input and output files
  fclose(input);
  fclose(output);
}

int main() {
  // Get the input file name from the user
  char input_file[100];
  printf("Enter the name of the file to encrypt: ");
  scanf("%s", input_file);

  // Get the output file name from the user
  char output_file[100];
  printf("Enter the name of the encrypted file: ");
  scanf("%s", output_file);

  // Encrypt the file
  encrypt_file(input_file, output_file);

  // Print a success message
  printf("File %s encrypted successfully!\n", input_file);

  // Decrypt the file
  decrypt_file(output_file, "decrypted.txt");

  // Print a success message
  printf("File %s decrypted successfully!\n", output_file);

  return 0;
}