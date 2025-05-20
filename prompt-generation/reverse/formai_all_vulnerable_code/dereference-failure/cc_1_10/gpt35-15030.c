//FormAI DATASET v1.0 Category: Modern Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Length of the encryption key
#define KEY_LENGTH 8

char* generateKey(void);
char* encrypt(char* plaintext, char* key);
char* decrypt(char* ciphertext, char* key);

int main() {

  char* key = generateKey();

  char plaintext[1000];
  printf("Enter the text to encrypt: ");
  fgets(plaintext, 1000, stdin);

  char* ciphertext = encrypt(plaintext, key);

  printf("Encrypted text: %s\n", ciphertext);

  char* decryptedText = decrypt(ciphertext, key);

  printf("Decrypted text: %s\n", decryptedText);

  free(key);
  free(ciphertext);
  free(decryptedText);

  return 0;
}

// Generate a random encryption key
char* generateKey() {

  char* key = malloc(sizeof(char) * KEY_LENGTH + 1);

  for (int i = 0; i < KEY_LENGTH; i++) {
    key[i] = rand() % 26 + 'a';
  }

  key[KEY_LENGTH] = '\0';

  return key;
}

// Encrypt a plaintext using the given key
char* encrypt(char* plaintext, char* key) {

  int plaintextLength = strlen(plaintext);
  int keyLength = strlen(key);

  char* ciphertext = malloc(sizeof(char) * plaintextLength + 1);

  for (int i = 0; i < plaintextLength; i++) {
    ciphertext[i] = plaintext[i] ^ key[i % keyLength];
  }

  ciphertext[plaintextLength] = '\0';

  return ciphertext;
}

// Decrypt a ciphertext using the given key
char* decrypt(char* ciphertext, char* key) {

  int ciphertextLength = strlen(ciphertext);
  int keyLength = strlen(key);

  char* plaintext = malloc(sizeof(char) * ciphertextLength + 1);

  for (int i = 0; i < ciphertextLength; i++) {
    plaintext[i] = ciphertext[i] ^ key[i % keyLength];
  }

  plaintext[ciphertextLength] = '\0';

  return plaintext;
}