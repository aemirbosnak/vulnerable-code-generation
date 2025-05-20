//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The following macros are the magic numbers in the Knuth cipher.
#define A 0x5555555555555555
#define B 0x3333333333333333
#define C 0x0F0F0F0F0F0F0F0F

// The following function encrypts the given plaintext using the Knuth cipher.
void knuth_encrypt(char *plaintext, int len) {
  // Convert the plaintext to uppercase.
  for (int i = 0; i < len; i++) {
    plaintext[i] = toupper(plaintext[i]);
  }

  // Create a buffer to store the ciphertext.
  char *ciphertext = malloc(len + 1);
  ciphertext[len] = '\0';

  // Encrypt the plaintext.
  for (int i = 0; i < len; i++) {
    ciphertext[i] = (plaintext[i] ^ A) ^ (B * (i + 1)) ^ (C * (i + 1) * (i + 1));
  }

  // Print the ciphertext.
  printf("Ciphertext: %s\n", ciphertext);

  // Free the ciphertext buffer.
  free(ciphertext);
}

// The following function decrypts the given ciphertext using the Knuth cipher.
void knuth_decrypt(char *ciphertext, int len) {
  // Create a buffer to store the plaintext.
  char *plaintext = malloc(len + 1);
  plaintext[len] = '\0';

  // Decrypt the ciphertext.
  for (int i = 0; i < len; i++) {
    plaintext[i] = (ciphertext[i] ^ A) ^ (B * (i + 1)) ^ (C * (i + 1) * (i + 1));
  }

  // Convert the plaintext to lowercase.
  for (int i = 0; i < len; i++) {
    plaintext[i] = tolower(plaintext[i]);
  }

  // Print the plaintext.
  printf("Plaintext: %s\n", plaintext);

  // Free the plaintext buffer.
  free(plaintext);
}

// The following function tests the Knuth cipher.
void knuth_test() {
  // Define the plaintext.
  char *plaintext = "The quick brown fox jumps over the lazy dog.";

  // Encrypt the plaintext.
  knuth_encrypt(plaintext, strlen(plaintext));

  // Decrypt the ciphertext.
  knuth_decrypt(plaintext, strlen(plaintext));
}

// The following function is the main function of the program.
int main() {
  // Test the Knuth cipher.
  knuth_test();

  return 0;
}