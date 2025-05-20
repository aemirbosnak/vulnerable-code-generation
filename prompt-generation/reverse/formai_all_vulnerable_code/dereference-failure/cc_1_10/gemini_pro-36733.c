//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *key;
  int key_len;
} keypair;

keypair generate_keypair(int key_len) {
  keypair kp;
  kp.key = malloc(key_len + 1);
  for (int i = 0; i < key_len; i++) {
    kp.key[i] = rand() % 256;
  }
  kp.key[key_len] = '\0';
  kp.key_len = key_len;
  return kp;
}

void free_keypair(keypair kp) {
  free(kp.key);
}

char *encrypt(char *plaintext, keypair kp) {
  char *ciphertext = malloc(strlen(plaintext) + 1);
  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] ^ kp.key[i % kp.key_len];
  }
  ciphertext[strlen(plaintext)] = '\0';
  return ciphertext;
}

char *decrypt(char *ciphertext, keypair kp) {
  char *plaintext = malloc(strlen(ciphertext) + 1);
  for (int i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = ciphertext[i] ^ kp.key[i % kp.key_len];
  }
  plaintext[strlen(ciphertext)] = '\0';
  return plaintext;
}

int main() {
  keypair kp = generate_keypair(16);
  char *plaintext = "Hello, world!";
  char *ciphertext = encrypt(plaintext, kp);
  char *decryptedtext = decrypt(ciphertext, kp);
  printf("Plaintext: %s\n", plaintext);
  printf("Ciphertext: %s\n", ciphertext);
  printf("Decrypted text: %s\n", decryptedtext);
  free_keypair(kp);
  free(ciphertext);
  free(decryptedtext);
  return 0;
}