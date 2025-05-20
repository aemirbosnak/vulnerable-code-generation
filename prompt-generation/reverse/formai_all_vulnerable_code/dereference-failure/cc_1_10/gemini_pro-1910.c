//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(unsigned char *a, unsigned char *b) {
  unsigned char tmp = *a;
  *a = *b;
  *b = tmp;
}

void reverse(unsigned char *s, int len) {
  for (int i = 0; i < len / 2; i++) {
    swap(s + i, s + len - 1 - i);
  }
}

unsigned char *encrypt(unsigned char *plaintext, unsigned char *key) {
  int keylen = strlen(key);
  int plaintextlen = strlen(plaintext);
  unsigned char *ciphertext = malloc(plaintextlen + 1);
  strcpy(ciphertext, plaintext);
  for (int i = 0; i < plaintextlen; i++) {
    ciphertext[i] = ciphertext[i] ^ key[i % keylen];
  }
  return ciphertext;
}

unsigned char *decrypt(unsigned char *ciphertext, unsigned char *key) {
  int keylen = strlen(key);
  int ciphertextlen = strlen(ciphertext);
  unsigned char *plaintext = malloc(ciphertextlen + 1);
  strcpy(plaintext, ciphertext);
  for (int i = 0; i < ciphertextlen; i++) {
    plaintext[i] = plaintext[i] ^ key[i % keylen];
  }
  return plaintext;
}

int main() {
  unsigned char *plaintext = "The quick brown fox jumps over the lazy dog";
  unsigned char *key = "My secret key";

  unsigned char *ciphertext = encrypt(plaintext, key);
  printf("Ciphertext: %s\n", ciphertext);

  unsigned char *decryptedtext = decrypt(ciphertext, key);
  printf("Decrypted text: %s\n", decryptedtext);

  return 0;
}