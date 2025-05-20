//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY 13

// Encrypt a string using the Caesar cipher
char *encrypt(char *plaintext) {
  int length = strlen(plaintext);
  char *ciphertext = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    ciphertext[i] = (plaintext[i] + KEY) % 256;
  }
  ciphertext[length] = '\0';
  return ciphertext;
}

// Decrypt a string using the Caesar cipher
char *decrypt(char *ciphertext) {
  int length = strlen(ciphertext);
  char *plaintext = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    plaintext[i] = (ciphertext[i] - KEY) % 256;
  }
  plaintext[length] = '\0';
  return plaintext;
}

// Print the usage information
void print_usage() {
  printf("Usage: ./encryptor [encrypt|decrypt] [message]\n");
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the correct number of arguments were provided
  if (argc != 3) {
    print_usage();
    return EXIT_FAILURE;
  }

  // Get the action (encrypt or decrypt)
  char *action = argv[1];

  // Get the message to encrypt or decrypt
  char *message = argv[2];

  // Encrypt or decrypt the message
  char *result;
  if (strcmp(action, "encrypt") == 0) {
    result = encrypt(message);
  } else if (strcmp(action, "decrypt") == 0) {
    result = decrypt(message);
  } else {
    print_usage();
    return EXIT_FAILURE;
  }

  // Print the result
  printf("%s\n", result);

  // Free the allocated memory
  free(result);

  return EXIT_SUCCESS;
}