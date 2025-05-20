//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using the Vigenere cipher
char *encryptVigenere(char *plaintext, char *key) {
  int keyLen = strlen(key);
  int plaintextLen = strlen(plaintext);
  char *ciphertext = malloc(plaintextLen + 1);

  for (int i = 0; i < plaintextLen; i++) {
    char plaintextChar = plaintext[i];
    char keyChar = key[i % keyLen];
    int shift = keyChar - 'a';
    char ciphertextChar = (plaintextChar + shift - 'a') % 26 + 'a';
    ciphertext[i] = ciphertextChar;
  }

  ciphertext[plaintextLen] = '\0';
  return ciphertext;
}

// Function to decrypt a string using the Vigenere cipher
char *decryptVigenere(char *ciphertext, char *key) {
  int keyLen = strlen(key);
  int ciphertextLen = strlen(ciphertext);
  char *plaintext = malloc(ciphertextLen + 1);

  for (int i = 0; i < ciphertextLen; i++) {
    char ciphertextChar = ciphertext[i];
    char keyChar = key[i % keyLen];
    int shift = keyChar - 'a';
    char plaintextChar = (ciphertextChar - shift - 'a') % 26 + 'a';
    plaintext[i] = plaintextChar;
  }

  plaintext[ciphertextLen] = '\0';
  return plaintext;
}

int main() {
  // Define the plaintext and key
  char *plaintext = "Hello, world!";
  char *key = "SECRET";

  // Encrypt the plaintext using the Vigenere cipher
  char *ciphertext = encryptVigenere(plaintext, key);
  printf("Ciphertext: %s\n", ciphertext);

  // Decrypt the ciphertext using the Vigenere cipher
  char *decryptedPlaintext = decryptVigenere(ciphertext, key);
  printf("Decrypted plaintext: %s\n", decryptedPlaintext);

  // Free the allocated memory
  free(ciphertext);
  free(decryptedPlaintext);

  return 0;
}