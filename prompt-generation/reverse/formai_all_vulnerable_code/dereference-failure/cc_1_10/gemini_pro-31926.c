//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 256

// Function to encrypt a string using a key
char *encrypt(char *plaintext, char *key) {
  int key_len = strlen(key);
  int plaintext_len = strlen(plaintext);

  // Allocate memory for the ciphertext
  char *ciphertext = malloc(plaintext_len + 1);
  if (ciphertext == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  // Encrypt the plaintext
  for (int i = 0; i < plaintext_len; i++) {
    ciphertext[i] = plaintext[i] ^ key[i % key_len];
  }

  // Terminate the ciphertext with a null character
  ciphertext[plaintext_len] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Function to decrypt a string using a key
char *decrypt(char *ciphertext, char *key) {
  int key_len = strlen(key);
  int ciphertext_len = strlen(ciphertext);

  // Allocate memory for the plaintext
  char *plaintext = malloc(ciphertext_len + 1);
  if (plaintext == NULL) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  // Decrypt the ciphertext
  for (int i = 0; i < ciphertext_len; i++) {
    plaintext[i] = ciphertext[i] ^ key[i % key_len];
  }

  // Terminate the plaintext with a null character
  plaintext[ciphertext_len] = '\0';

  // Return the plaintext
  return plaintext;
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has provided enough arguments
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <plaintext> <key> <encrypt|decrypt>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the plaintext, key, and operation from the command line
  char *plaintext = argv[1];
  char *key = argv[2];
  char *operation = argv[3];

  // Check if the key is too long
  if (strlen(key) > MAX_KEY_SIZE) {
    fprintf(stderr, "Error: Key is too long (%d characters maximum)\n", MAX_KEY_SIZE);
    exit(EXIT_FAILURE);
  }

  // Perform the encryption or decryption operation
  char *result;
  if (strcmp(operation, "encrypt") == 0) {
    result = encrypt(plaintext, key);
  } else if (strcmp(operation, "decrypt") == 0) {
    result = decrypt(plaintext, key);
  } else {
    fprintf(stderr, "Error: Invalid operation (%s)\n", operation);
    exit(EXIT_FAILURE);
  }

  // Print the result
  printf("%s\n", result);

  // Free the allocated memory
  free(result);

  return EXIT_SUCCESS;
}