//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define ENCRYPTION_KEY "MySecretEncryptionKey"

// Encrypt a string using the XOR cipher
char *encrypt(char *plaintext) {
  char *ciphertext = malloc(strlen(plaintext) + 1);
  int keylen = strlen(ENCRYPTION_KEY);

  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] ^ ENCRYPTION_KEY[i % keylen];
  }

  ciphertext[strlen(plaintext)] = '\0';
  return ciphertext;
}

// Decrypt a string using the XOR cipher
char *decrypt(char *ciphertext) {
  char *plaintext = malloc(strlen(ciphertext) + 1);
  int keylen = strlen(ENCRYPTION_KEY);

  for (int i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = ciphertext[i] ^ ENCRYPTION_KEY[i % keylen];
  }

  plaintext[strlen(ciphertext)] = '\0';
  return plaintext;
}

// Print the usage instructions
void print_usage() {
  printf("Usage: ./file_encryptor [encrypt | decrypt] [input_file] [output_file]\n");
  printf("Example: ./file_encryptor encrypt plaintext.txt ciphertext.txt\n");
  printf("Example: ./file_encryptor decrypt ciphertext.txt decrypted.txt\n");
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the correct number of arguments were provided
  if (argc != 4) {
    print_usage();
    return EXIT_FAILURE;
  }

  // Get the operation (encrypt or decrypt)
  char *operation = argv[1];

  // Get the input file name
  char *input_file = argv[2];

  // Get the output file name
  char *output_file = argv[3];

  // Open the input file
  FILE *input = fopen(input_file, "r");
  if (input == NULL) {
    perror("Error opening input file");
    return EXIT_FAILURE;
  }

  // Create the output file
  FILE *output = fopen(output_file, "w");
  if (output == NULL) {
    perror("Error creating output file");
    return EXIT_FAILURE;
  }

  // Read the input file into a string
  fseek(input, 0, SEEK_END);
  long file_size = ftell(input);
  fseek(input, 0, SEEK_SET);
  char *input_string = malloc(file_size + 1);
  fread(input_string, file_size, 1, input);

  // Encrypt or decrypt the input string
  char *output_string;
  if (strcmp(operation, "encrypt") == 0) {
    output_string = encrypt(input_string);
  } else if (strcmp(operation, "decrypt") == 0) {
    output_string = decrypt(input_string);
  } else {
    print_usage();
    return EXIT_FAILURE;
  }

  // Write the output string to the output file
  fwrite(output_string, strlen(output_string), 1, output);

  // Free the allocated memory
  free(input_string);
  free(output_string);

  // Close the files
  fclose(input);
  fclose(output);

  return EXIT_SUCCESS;
}