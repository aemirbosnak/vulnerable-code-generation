//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

unsigned char key[KEY_SIZE];
unsigned char iv[BLOCK_SIZE];

void init_key(unsigned char *key_str) {
  int i;
  for (i = 0; i < KEY_SIZE; i++) {
    key[i] = key_str[i];
  }
}

void init_iv(unsigned char *iv_str) {
  int i;
  for (i = 0; i < BLOCK_SIZE; i++) {
    iv[i] = iv_str[i];
  }
}

void aes_128_cbc_encrypt(unsigned char *plaintext, unsigned char *ciphertext,
                          int length) {
  int i;
  unsigned char prev_block[BLOCK_SIZE];
  memset(prev_block, 0, BLOCK_SIZE);

  for (i = 0; i < length; i += BLOCK_SIZE) {
    unsigned char block[BLOCK_SIZE];
    memcpy(block, plaintext + i, BLOCK_SIZE);

    for (int j = 0; j < BLOCK_SIZE; j++) {
      block[j] ^= prev_block[j];
    }

    // Encrypt the block
    // ...

    memcpy(prev_block, block, BLOCK_SIZE);
    memcpy(ciphertext + i, block, BLOCK_SIZE);
  }
}

void aes_128_cbc_decrypt(unsigned char *ciphertext, unsigned char *plaintext,
                          int length) {
  int i;
  unsigned char prev_block[BLOCK_SIZE];
  memset(prev_block, 0, BLOCK_SIZE);

  for (i = 0; i < length; i += BLOCK_SIZE) {
    unsigned char block[BLOCK_SIZE];
    memcpy(block, ciphertext + i, BLOCK_SIZE);

    // Decrypt the block
    // ...

    for (int j = 0; j < BLOCK_SIZE; j++) {
      block[j] ^= prev_block[j];
    }

    memcpy(prev_block, ciphertext + i, BLOCK_SIZE);
    memcpy(plaintext + i, block, BLOCK_SIZE);
  }
}

int main() {
  unsigned char plaintext[] = "Hello, world!";
  unsigned char ciphertext[sizeof(plaintext)];
  unsigned char decryptedtext[sizeof(plaintext)];

  // Initialize the key and IV
  init_key("0123456789abcdef");
  init_iv("fedcba9876543210");

  // Encrypt the plaintext
  aes_128_cbc_encrypt(plaintext, ciphertext, sizeof(plaintext));

  // Decrypt the ciphertext
  aes_128_cbc_decrypt(ciphertext, decryptedtext, sizeof(plaintext));

  // Print the decrypted text
  printf("%s\n", decryptedtext);

  return 0;
}