//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key.
#define KEY "SECRET"

// Define the encryption function.
char *encrypt(char *plaintext) {
  int i, j, keylen;
  char *ciphertext;

  // Get the length of the key.
  keylen = strlen(KEY);

  // Allocate memory for the ciphertext.
  ciphertext = malloc(strlen(plaintext) + 1);

  // Encrypt the plaintext.
  for (i = 0, j = 0; plaintext[i] != '\0'; i++, j++) {
    ciphertext[i] = plaintext[i] ^ KEY[j % keylen];
  }

  // Null-terminate the ciphertext.
  ciphertext[i] = '\0';

  // Return the ciphertext.
  return ciphertext;
}

// Define the decryption function.
char *decrypt(char *ciphertext) {
  int i, j, keylen;
  char *plaintext;

  // Get the length of the key.
  keylen = strlen(KEY);

  // Allocate memory for the plaintext.
  plaintext = malloc(strlen(ciphertext) + 1);

  // Decrypt the ciphertext.
  for (i = 0, j = 0; ciphertext[i] != '\0'; i++, j++) {
    plaintext[i] = ciphertext[i] ^ KEY[j % keylen];
  }

  // Null-terminate the plaintext.
  plaintext[i] = '\0';

  // Return the plaintext.
  return plaintext;
}

// Main function.
int main(int argc, char *argv[]) {
  char *plaintext, *ciphertext;

  // Get the plaintext from the command line.
  if (argc < 2) {
    printf("Usage: %s plaintext\n", argv[0]);
    return 1;
  }
  plaintext = argv[1];

  // Encrypt the plaintext.
  ciphertext = encrypt(plaintext);

  // Print the ciphertext.
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext.
  plaintext = decrypt(ciphertext);

  // Print the plaintext.
  printf("Plaintext: %s\n", plaintext);

  // Free the memory allocated for the ciphertext and plaintext.
  free(ciphertext);
  free(plaintext);

  return 0;
}