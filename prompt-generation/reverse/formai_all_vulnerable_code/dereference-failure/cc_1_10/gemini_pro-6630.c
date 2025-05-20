//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
char *encrypt(const char *plaintext, const char *key);
char *decrypt(const char *ciphertext, const char *key);

// Main Function
int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <encrypt/decrypt> <plaintext/ciphertext> <key>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the plaintext/ciphertext
  char *text = argv[2];

  // Get the key
  char *key = argv[3];

  // Check if the key is long enough
  if (strlen(key) < 8) {
    fprintf(stderr, "Error: Key must be at least 8 characters long.\n");
    return EXIT_FAILURE;
  }

  // Encrypt or decrypt the text
  char *result;
  if (strcmp(argv[1], "encrypt") == 0) {
    result = encrypt(text, key);
  } else if (strcmp(argv[1], "decrypt") == 0) {
    result = decrypt(text, key);
  } else {
    fprintf(stderr, "Error: Invalid operation specified.\n");
    return EXIT_FAILURE;
  }

  // Print the result
  printf("%s", result);

  // Free the memory
  free(result);

  return EXIT_SUCCESS;
}

// Encrypt the text using the key
char *encrypt(const char *plaintext, const char *key) {
  int keylen = strlen(key);
  int textlen = strlen(plaintext);
  char *ciphertext = malloc(textlen + 1);
  for (int i = 0; i < textlen; i++) {
    ciphertext[i] = plaintext[i] ^ key[i % keylen];
  }
  ciphertext[textlen] = '\0';
  return ciphertext;
}

// Decrypt the text using the key
char *decrypt(const char *ciphertext, const char *key) {
  int keylen = strlen(key);
  int textlen = strlen(ciphertext);
  char *plaintext = malloc(textlen + 1);
  for (int i = 0; i < textlen; i++) {
    plaintext[i] = ciphertext[i] ^ key[i % keylen];
  }
  plaintext[textlen] = '\0';
  return plaintext;
}