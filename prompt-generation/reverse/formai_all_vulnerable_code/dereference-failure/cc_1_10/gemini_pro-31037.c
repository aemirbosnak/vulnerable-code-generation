//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the alphabet to use for encryption
#define ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

// Define the key to use for encryption
#define KEY "secret"

// Function to encrypt a string using the given key
char *encrypt(char *plaintext, char *key) {
  int keylen = strlen(key);
  int plaintextlen = strlen(plaintext);

  char *ciphertext = malloc(plaintextlen + 1);
  for (int i = 0; i < plaintextlen; i++) {
    int keyindex = i % keylen;
    ciphertext[i] = (plaintext[i] + key[keyindex]) % 256;
  }
  ciphertext[plaintextlen] = '\0';

  return ciphertext;
}

// Function to decrypt a string using the given key
char *decrypt(char *ciphertext, char *key) {
  int keylen = strlen(key);
  int ciphertextlen = strlen(ciphertext);

  char *plaintext = malloc(ciphertextlen + 1);
  for (int i = 0; i < ciphertextlen; i++) {
    int keyindex = i % keylen;
    plaintext[i] = (ciphertext[i] - key[keyindex] + 256) % 256;
  }
  plaintext[ciphertextlen] = '\0';

  return plaintext;
}

// Main function to test the encryption and decryption functions
int main() {
  char *plaintext = "Hello, world!";
  char *ciphertext = encrypt(plaintext, KEY);
  char *decryptedtext = decrypt(ciphertext, KEY);

  printf("Plaintext: %s\n", plaintext);
  printf("Ciphertext: %s\n", ciphertext);
  printf("Decryptedtext: %s\n", decryptedtext);

  return 0;
}