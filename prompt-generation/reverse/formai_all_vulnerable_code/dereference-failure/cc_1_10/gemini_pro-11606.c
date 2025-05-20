//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the encryption and decryption functions
void encrypt(char *plaintext, char *key);
void decrypt(char *ciphertext, char *key);

int main() {
  // Declare the plaintext and ciphertext
  char plaintext[] = "This is a secret message.";
  char ciphertext[strlen(plaintext) + 1];

  // Declare the encryption key
  char key[] = "mysecretkey";

  // Encrypt the plaintext
  encrypt(plaintext, key);

  // Print the ciphertext
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext
  decrypt(ciphertext, key);

  // Print the decrypted plaintext
  printf("Plaintext: %s\n", plaintext);

  return 0;
}

void encrypt(char *plaintext, char *key) {
  int i, j;
  int keylen = strlen(key);
  int plaintextlen = strlen(plaintext);

  // XOR each character of the plaintext with the corresponding character of the key
  for (i = 0, j = 0; i < plaintextlen; i++, j = (j + 1) % keylen) {
    plaintext[i] ^= key[j];
  }
}

void decrypt(char *ciphertext, char *key) {
  int i, j;
  int keylen = strlen(key);
  int ciphertextlen = strlen(ciphertext);

  // XOR each character of the ciphertext with the corresponding character of the key
  for (i = 0, j = 0; i < ciphertextlen; i++, j = (j + 1) % keylen) {
    ciphertext[i] ^= key[j];
  }
}