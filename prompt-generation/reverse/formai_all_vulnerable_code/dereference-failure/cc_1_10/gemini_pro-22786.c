//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, unsigned char *ciphertext, unsigned char *out_len) {
  EVP_CIPHER_CTX *ctx;

  ctx = EVP_CIPHER_CTX_new();

  if (!ctx) {
    fprintf(stderr, "Could not allocate context\n");
    exit(1);
  }

  if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
    fprintf(stderr, "Could not initialize encryption\n");
    exit(1);
  }

  if (!EVP_EncryptUpdate(ctx, ciphertext, out_len, plaintext, plaintext_len)) {
    fprintf(stderr, "Could not update encryption\n");
    exit(1);
  }

  if (!EVP_EncryptFinal_ex(ctx, ciphertext + *out_len, out_len)) {
    fprintf(stderr, "Could not finalize encryption\n");
    exit(1);
  }

  EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
             unsigned char *iv, unsigned char *plaintext, unsigned char *out_len) {
  EVP_CIPHER_CTX *ctx;

  ctx = EVP_CIPHER_CTX_new();

  if (!ctx) {
    fprintf(stderr, "Could not allocate context\n");
    exit(1);
  }

  if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
    fprintf(stderr, "Could not initialize decryption\n");
    exit(1);
  }

  if (!EVP_DecryptUpdate(ctx, plaintext, out_len, ciphertext, ciphertext_len)) {
    fprintf(stderr, "Could not update decryption\n");
    exit(1);
  }

  if (!EVP_DecryptFinal_ex(ctx, plaintext + *out_len, out_len)) {
    fprintf(stderr, "Could not finalize decryption\n");
    exit(1);
  }

  EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s plaintext key iv ciphertext\n", argv[0]);
    exit(1);
  }

  unsigned char plaintext[1024];
  unsigned char key[32];
  unsigned char iv[16];
  unsigned char ciphertext[1024];
  unsigned char out_len;

  strcpy(plaintext, argv[1]);
  strcpy(key, argv[2]);
  strcpy(iv, argv[3]);

  encrypt(plaintext, strlen(plaintext), key, iv, ciphertext, &out_len);

  printf("Ciphertext:\n");
  for (int i = 0; i < out_len; i++) {
    printf("%02x", ciphertext[i]);
  }
  printf("\n");

  unsigned char decrypted_plaintext[1024];
  unsigned char decrypted_out_len;

  decrypt(ciphertext, out_len, key, iv, decrypted_plaintext, &decrypted_out_len);

  printf("Decrypted plaintext:\n");
  printf("%s\n", decrypted_plaintext);

  return 0;
}