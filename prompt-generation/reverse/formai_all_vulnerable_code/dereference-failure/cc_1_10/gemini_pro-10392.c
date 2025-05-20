//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a paranoid encryption function.
char *encrypt(char *plaintext) {
  // Allocate memory for the ciphertext.
  char *ciphertext = malloc(strlen(plaintext) + 1);

  // Initialize the ciphertext to the plaintext.
  strcpy(ciphertext, plaintext);

  // Encrypt the ciphertext by XORing each character with a secret key.
  for (int i = 0; i < strlen(ciphertext); i++) {
    ciphertext[i] ^= 0x42;
  }

  // Return the ciphertext.
  return ciphertext;
}

// Declare a paranoid decryption function.
char *decrypt(char *ciphertext) {
  // Allocate memory for the plaintext.
  char *plaintext = malloc(strlen(ciphertext) + 1);

  // Initialize the plaintext to the ciphertext.
  strcpy(plaintext, ciphertext);

  // Decrypt the plaintext by XORing each character with a secret key.
  for (int i = 0; i < strlen(plaintext); i++) {
    plaintext[i] ^= 0x42;
  }

  // Return the plaintext.
  return plaintext;
}

int main() {
  // Declare a paranoid variable to store the plaintext.
  char *plaintext = "Hello, world!";

  // Encrypt the plaintext.
  char *ciphertext = encrypt(plaintext);

  // Print the ciphertext.
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext.
  char *decryptedText = decrypt(ciphertext);

  // Print the decrypted text.
  printf("Decrypted text: %s\n", decryptedText);

  // Free the memory allocated for the ciphertext and decrypted text.
  free(ciphertext);
  free(decryptedText);

  return 0;
}