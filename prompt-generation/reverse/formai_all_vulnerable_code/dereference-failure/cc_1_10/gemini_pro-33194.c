//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: random
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

static char *decrypt(char *key) {
  unsigned char *ciphertext_hex;
  unsigned char ciphertext_dec[EVP_MAX_BLOCK_LENGTH];
  unsigned int ciphertext_len_dec;
  int key_len = strlen(key);
  EVP_CIPHER_CTX *ctx;
  char *plaintext;

  if (key_len != 32) {
    printf("Error: Key must be 32 characters long.\n");
    return NULL;
  }

  ciphertext_hex = "41d8dbcbfd68a7e1e6a07e69e85323cf0f897e567200665c8a21a22845a77bc1";
  ctx = EVP_CIPHER_CTX_new();
  if (ctx == NULL) {
    printf("Error: Could not create cipher context.\n");
    return NULL;
  }
  if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)key, (unsigned char *)"827151142d607209")) {
    printf("Error: Could not initialize decryption context.\n");
    EVP_CIPHER_CTX_free(ctx);
    return NULL;
  }
  if (!EVP_DecryptUpdate(ctx, ciphertext_dec, &ciphertext_len_dec, (unsigned char *)ciphertext_hex, strlen(ciphertext_hex) / 2)) {
    printf("Error: Could not decrypt data.\n");
    EVP_CIPHER_CTX_free(ctx);
    return NULL;
  }
  if (!EVP_DecryptFinal_ex(ctx, ciphertext_dec + ciphertext_len_dec, &ciphertext_len_dec)) {
    printf("Error: Could not finalize decryption.\n");
    EVP_CIPHER_CTX_free(ctx);
    return NULL;
  }
  plaintext = malloc(ciphertext_len_dec + 1);
  if (plaintext == NULL) {
    printf("Error: Could not allocate memory for plaintext.\n");
    EVP_CIPHER_CTX_free(ctx);
    return NULL;
  }
  memcpy(plaintext, ciphertext_dec, ciphertext_len_dec);
  plaintext[ciphertext_len_dec] = '\0';
  EVP_CIPHER_CTX_free(ctx);
  return plaintext;
}

int main(void) {
  char *key = "12345678901234567890123456789012";
  char *plaintext = decrypt(key);
  if (plaintext == NULL) {
    printf("Error: Could not decrypt data.\n");
    return -1;
  }
  printf("Plaintext: %s\n", plaintext);
  free(plaintext);
  return 0;
}