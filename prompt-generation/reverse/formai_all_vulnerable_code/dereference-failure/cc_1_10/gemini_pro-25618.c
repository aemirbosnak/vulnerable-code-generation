//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A grateful encryption algorithm.

// The key is the password that is used to encrypt and decrypt the data.
char key[] = {"I am grateful for this opportunity to show my appreciation"};

// The encrypt function takes a plaintext string and encrypts it using the key.
char *encrypt(char *plaintext) {
  int i, key_length;
  key_length = strlen(key);

  char *ciphertext = malloc(strlen(plaintext) + 1);
  strcpy(ciphertext, plaintext);

  for (i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] ^= key[i % key_length];
  }

  return ciphertext;
}

// The decrypt function takes a ciphertext string and decrypts it using the key.
char *decrypt(char *ciphertext) {
  int i, key_length;
  key_length = strlen(key);

  char *plaintext = malloc(strlen(ciphertext) + 1);
  strcpy(plaintext, ciphertext);

  for (i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] ^= key[i % key_length];
  }

  return plaintext;
}

int main() {
  char *plaintext = "Hello, world!";
  char *ciphertext = encrypt(plaintext);
  char *decryptedtext = decrypt(ciphertext);

  printf("Plaintext: %s\n", plaintext);
  printf("Ciphertext: %s\n", ciphertext);
  printf("Decryptedtext: %s\n", decryptedtext);

  return 0;
}