//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "SECRETKEY"

// Function to encrypt a string
char *encrypt(char *plaintext) {
  // Allocate memory for the ciphertext
  char *ciphertext = malloc(strlen(plaintext) + 1);

  // Iterate over each character in the plaintext
  for (int i = 0; i < strlen(plaintext); i++) {
    // Encrypt the character by XORing it with the key
    ciphertext[i] = plaintext[i] ^ KEY[i % strlen(KEY)];
  }

  // Terminate the ciphertext with a null character
  ciphertext[strlen(plaintext)] = '\0';

  // Return the ciphertext
  return ciphertext;
}

// Function to decrypt a string
char *decrypt(char *ciphertext) {
  // Allocate memory for the plaintext
  char *plaintext = malloc(strlen(ciphertext) + 1);

  // Iterate over each character in the ciphertext
  for (int i = 0; i < strlen(ciphertext); i++) {
    // Decrypt the character by XORing it with the key
    plaintext[i] = ciphertext[i] ^ KEY[i % strlen(KEY)];
  }

  // Terminate the plaintext with a null character
  plaintext[strlen(ciphertext)] = '\0';

  // Return the plaintext
  return plaintext;
}

// Main function
int main() {
  // Get the plaintext from the user
  char *plaintext = "Hello world";

  // Encrypt the plaintext
  char *ciphertext = encrypt(plaintext);

  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  char *decryptedtext = decrypt(ciphertext);

  // Print the decrypted text
  printf("Decrypted text: %s\n", decryptedtext);

  return 0;
}