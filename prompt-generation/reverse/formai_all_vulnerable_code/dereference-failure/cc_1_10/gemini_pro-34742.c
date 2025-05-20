//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define KEY_SIZE 16

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, unsigned char *ciphertext) {
  AES_KEY enc_key;

  if (!plaintext || !plaintext_len || !key || !ciphertext) {
    fprintf(stderr, "Invalid arguments.\n");
    exit(EXIT_FAILURE);
  }

  AES_set_encrypt_key(key, KEY_SIZE * 8, &enc_key);
  AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &enc_key, iv, AES_ENCRYPT);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
             unsigned char *iv, unsigned char *plaintext) {
  AES_KEY dec_key;

  if (!ciphertext || !ciphertext_len || !key || !plaintext) {
    fprintf(stderr, "Invalid arguments.\n");
    exit(EXIT_FAILURE);
  }

  AES_set_decrypt_key(key, KEY_SIZE * 8, &dec_key);
  AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &dec_key, iv,
                   AES_DECRYPT);
}

int main(int argc, char **argv) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s plaintext key iv\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  unsigned char plaintext[1024];
  unsigned char key[KEY_SIZE];
  unsigned char iv[AES_BLOCK_SIZE];

  strcpy(plaintext, argv[1]);
  strcpy(key, argv[2]);
  strcpy(iv, argv[3]);

  unsigned char ciphertext[1024];
  encrypt(plaintext, strlen(plaintext), key, iv, ciphertext);

  unsigned char decryptedtext[1024];
  decrypt(ciphertext, strlen(ciphertext), key, iv, decryptedtext);

  printf("Plaintext: %s\n", plaintext);
  printf("Ciphertext: %s\n", ciphertext);
  printf("Decryptedtext: %s\n", decryptedtext);

  return EXIT_SUCCESS;
}