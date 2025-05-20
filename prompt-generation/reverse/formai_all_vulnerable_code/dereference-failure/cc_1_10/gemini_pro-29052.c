//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Salt to be used for encryption.
static const char SALT[] = "d53819a7";

// Number of rounds to perform for encryption.
static const int ROUNDS = 10;

// Encryption function.
void encrypt(char *plaintext, char *ciphertext) {
  // Calculate the length of the plaintext.
  int plaintext_len = strlen(plaintext);

  // Create a buffer for the ciphertext.
  char *ciphertext_buf = malloc(plaintext_len + 1);

  // Copy the plaintext to the ciphertext buffer.
  strcpy(ciphertext_buf, plaintext);

  // Encrypt the ciphertext buffer.
  for (int i = 0; i < plaintext_len; i++) {
    // XOR the character with the salt.
    ciphertext_buf[i] ^= SALT[i % strlen(SALT)];

    // Rotate the character left by the number of rounds.
    for (int j = 0; j < ROUNDS; j++) {
      char tmp = ciphertext_buf[i];
      ciphertext_buf[i] = ciphertext_buf[i + 1];
      ciphertext_buf[i + 1] = tmp;
    }
  }

  // Copy the ciphertext buffer to the ciphertext.
  strcpy(ciphertext, ciphertext_buf);

  // Free the ciphertext buffer.
  free(ciphertext_buf);
}

// Decryption function.
void decrypt(char *ciphertext, char *plaintext) {
  // Calculate the length of the ciphertext.
  int ciphertext_len = strlen(ciphertext);

  // Create a buffer for the plaintext.
  char *plaintext_buf = malloc(ciphertext_len + 1);

  // Copy the ciphertext to the plaintext buffer.
  strcpy(plaintext_buf, ciphertext);

  // Decrypt the plaintext buffer.
  for (int i = 0; i < ciphertext_len; i++) {
    // Rotate the character right by the number of rounds.
    for (int j = 0; j < ROUNDS; j++) {
      char tmp = plaintext_buf[i];
      plaintext_buf[i] = plaintext_buf[i - 1];
      plaintext_buf[i - 1] = tmp;
    }

    // XOR the character with the salt.
    plaintext_buf[i] ^= SALT[i % strlen(SALT)];
  }

  // Copy the plaintext buffer to the plaintext.
  strcpy(plaintext, plaintext_buf);

  // Free the plaintext buffer.
  free(plaintext_buf);
}

// Main function.
int main(int argc, char **argv) {
  // Check if the user has provided enough arguments.
  if (argc != 3) {
    printf("Usage: %s <plaintext> <ciphertext>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the plaintext from the user.
  char *plaintext = argv[1];

  // Get the ciphertext from the user.
  char *ciphertext = argv[2];

  // Encrypt the plaintext.
  encrypt(plaintext, ciphertext);

  // Decrypt the ciphertext.
  decrypt(ciphertext, plaintext);

  // Print the plaintext.
  printf("%s\n", plaintext);

  // Return success.
  return EXIT_SUCCESS;
}