//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generate a random key for encryption
unsigned char *generateKey(int keyLength) {
  unsigned char *key = malloc(keyLength);
  for (int i = 0; i < keyLength; i++) {
    key[i] = rand() % 256;
  }
  return key;
}

// Encrypt a message using a key
unsigned char *encrypt(unsigned char *plaintext, unsigned char *key, int keyLength) {
  unsigned char *ciphertext = malloc(strlen(plaintext) + 1);
  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] ^ key[i % keyLength];
  }
  ciphertext[strlen(plaintext)] = '\0';
  return ciphertext;
}

// Decrypt a message using a key
unsigned char *decrypt(unsigned char *ciphertext, unsigned char *key, int keyLength) {
  unsigned char *plaintext = malloc(strlen(ciphertext) + 1);
  for (int i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = ciphertext[i] ^ key[i % keyLength];
  }
  plaintext[strlen(ciphertext)] = '\0';
  return plaintext;
}

int main() {
  // Generate a random key for encryption
  unsigned char *key = generateKey(16);

  // Encrypt a message using the key
  unsigned char *plaintext = "Hello, world!";
  unsigned char *ciphertext = encrypt(plaintext, key, 16);

  // Decrypt the message using the key
  unsigned char *decryptedPlaintext = decrypt(ciphertext, key, 16);

  // Print the original and decrypted messages
  printf("Original message: %s\n", plaintext);
  printf("Encrypted message: %s\n", ciphertext);
  printf("Decrypted message: %s\n", decryptedPlaintext);

  // Free the allocated memory
  free(key);
  free(ciphertext);
  free(decryptedPlaintext);

  return 0;
}