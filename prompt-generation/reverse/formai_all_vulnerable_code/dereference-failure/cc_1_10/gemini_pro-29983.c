//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

void encrypt(char *plaintext, char *key, char *ciphertext) {
  int i, key_len, plaintext_len;
  key_len = strlen(key);
  plaintext_len = strlen(plaintext);

  for (i = 0; i < plaintext_len; i++) {
    ciphertext[i] = plaintext[i] ^ key[i % key_len];
  }

  ciphertext[plaintext_len] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
  int i, key_len, ciphertext_len;
  key_len = strlen(key);
  ciphertext_len = strlen(ciphertext);

  for (i = 0; i < ciphertext_len; i++) {
    plaintext[i] = ciphertext[i] ^ key[i % key_len];
  }

  plaintext[ciphertext_len] = '\0';
}

int main(int argc, char *argv[]) {
  char plaintext[BUF_SIZE], key[BUF_SIZE], ciphertext[BUF_SIZE];

  if (argc != 4) {
    printf("Usage: %s plaintext key ciphertext\n", argv[0]);
    return EXIT_FAILURE;
  }

  strcpy(plaintext, argv[1]);
  strcpy(key, argv[2]);
  strcpy(ciphertext, argv[3]);

  encrypt(plaintext, key, ciphertext);
  decrypt(ciphertext, key, plaintext);

  printf("Plaintext: %s\n", plaintext);
  printf("Key: %s\n", key);
  printf("Ciphertext: %s\n", ciphertext);

  return EXIT_SUCCESS;
}