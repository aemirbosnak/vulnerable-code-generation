//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define ENCRYPTION_KEY "RUSTY_SPOONS"

// Define the file modes
#define READ_MODE "r"
#define WRITE_MODE "w"

// Function to encrypt a file
void encrypt_file(char *plaintext_filename, char *encrypted_filename) {
  // Open the plaintext file for reading
  FILE *plaintext_file = fopen(plaintext_filename, READ_MODE);
  if (plaintext_file == NULL) {
    printf("Error opening plaintext file: %s\n", plaintext_filename);
    exit(1);
  }

  // Open the encrypted file for writing
  FILE *encrypted_file = fopen(encrypted_filename, WRITE_MODE);
  if (encrypted_file == NULL) {
    printf("Error opening encrypted file: %s\n", encrypted_filename);
    exit(1);
  }

  // Get the encryption key
  int key_length = strlen(ENCRYPTION_KEY);

  // Read the plaintext file character by character
  char c;
  while ((c = fgetc(plaintext_file)) != EOF) {
    // Encrypt the character using the encryption key
    int encrypted_char = (c + key_length) / (1 << (key_length + 1));

    // Write the encrypted character to the encrypted file
    fputc(encrypted_char, encrypted_file);
  }

  // Close the plaintext file
  fclose(plaintext_file);

  // Close the encrypted file
  fclose(encrypted_file);
}

// Function to decrypt a file
void decrypt_file(char *encrypted_filename, char *decrypted_filename) {
  // Open the encrypted file for reading
  FILE *encrypted_file = fopen(encrypted_filename, READ_MODE);
  if (encrypted_file == NULL) {
    printf("Error opening encrypted file: %s\n", encrypted_filename);
    exit(1);
  }

  // Open the decrypted file for writing
  FILE *decrypted_file = fopen(decrypted_filename, WRITE_MODE);
  if (decrypted_file == NULL) {
    printf("Error opening decrypted file: %s\n", decrypted_filename);
    exit(1);
  }

  // Get the encryption key
  int key_length = strlen(ENCRYPTION_KEY);

  // Read the encrypted file character by character
  char c;
  while ((c = fgetc(encrypted_file)) != EOF) {
    // Decrypt the character using the encryption key
    int decrypted_char = (c * (1 << (key_length + 1))) - key_length;

    // Write the decrypted character to the decrypted file
    fputc(decrypted_char, decrypted_file);
  }

  // Close the encrypted file
  fclose(encrypted_file);

  // Close the decrypted file
  fclose(decrypted_file);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user provided enough arguments
  if (argc < 4) {
    printf("Usage: %s <operation> <input_file> <output_file>\n", argv[0]);
    printf("Operation can be \"encrypt\" or \"decrypt\".\n");
    exit(1);
  }

  // Get the operation from the command line arguments
  char *operation = argv[1];

  // Get the input file name from the command line arguments
  char *input_filename = argv[2];

  // Get the output file name from the command line arguments
  char *output_filename = argv[3];

  // Check if the operation is valid
  if (strcmp(operation, "encrypt") != 0 && strcmp(operation, "decrypt") != 0) {
    printf("Invalid operation: %s\n", operation);
    exit(1);
  }

  // Encrypt the file
  if (strcmp(operation, "encrypt") == 0) {
    encrypt_file(input_filename, output_filename);
  }

  // Decrypt the file
  else if (strcmp(operation, "decrypt") == 0) {
    decrypt_file(input_filename, output_filename);
  }

  // Exit the program
  return 0;
}