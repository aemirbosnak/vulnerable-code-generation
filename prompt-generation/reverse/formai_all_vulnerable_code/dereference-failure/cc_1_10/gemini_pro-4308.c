//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption and decryption functions
void encrypt(char *plaintext, char *key, char *ciphertext);
void decrypt(char *ciphertext, char *key, char *plaintext);

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user specified the correct number of arguments
  if (argc != 4) {
    printf("Usage: %s plaintext key ciphertext\n", argv[0]);
    return 1;
  }

  // Get the plaintext, key, and ciphertext from the command line arguments
  char *plaintext = argv[1];
  char *key = argv[2];
  char *ciphertext = argv[3];

  // Encrypt the plaintext
  encrypt(plaintext, key, ciphertext);

  // Decrypt the ciphertext
  decrypt(ciphertext, key, plaintext);

  // Print the decrypted plaintext
  printf("Decrypted plaintext: %s\n", plaintext);

  return 0;
}

// Define the encryption function
void encrypt(char *plaintext, char *key, char *ciphertext) {
  // Get the lengths of the plaintext and key
  int plaintext_len = strlen(plaintext);
  int key_len = strlen(key);

  // Initialize the ciphertext to the empty string
  ciphertext[0] = '\0';

  // Iterate over the plaintext characters
  for (int i = 0; i < plaintext_len; i++) {
    // Get the plaintext character
    char plaintext_char = plaintext[i];

    // Get the key character
    char key_char = key[i % key_len];

    // Encrypt the plaintext character using the key character
    char ciphertext_char = plaintext_char ^ key_char;

    // Append the ciphertext character to the ciphertext
    strncat(ciphertext, &ciphertext_char, 1);
  }
}

// Define the decryption function
void decrypt(char *ciphertext, char *key, char *plaintext) {
  // Get the lengths of the ciphertext and key
  int ciphertext_len = strlen(ciphertext);
  int key_len = strlen(key);

  // Initialize the plaintext to the empty string
  plaintext[0] = '\0';

  // Iterate over the ciphertext characters
  for (int i = 0; i < ciphertext_len; i++) {
    // Get the ciphertext character
    char ciphertext_char = ciphertext[i];

    // Get the key character
    char key_char = key[i % key_len];

    // Decrypt the ciphertext character using the key character
    char plaintext_char = ciphertext_char ^ key_char;

    // Append the plaintext character to the plaintext
    strncat(plaintext, &plaintext_char, 1);
  }
}