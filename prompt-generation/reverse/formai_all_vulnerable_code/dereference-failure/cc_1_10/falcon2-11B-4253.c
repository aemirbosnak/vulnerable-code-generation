//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/err.h>

int main(int argc, char* argv[]) {
  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <plaintext>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const char* plaintext = argv[1];
  size_t plaintext_len = strlen(plaintext);
  char* ciphertext = (char*)malloc(plaintext_len + 1);
  if (ciphertext == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  unsigned char* key = (unsigned char*)malloc(32);
  if (key == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  RAND_bytes(key, 32);

  EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
  if (ctx == NULL) {
    fprintf(stderr, "EVP_CIPHER_CTX_new() failed\n");
    exit(EXIT_FAILURE);
  }

  EVP_CIPHER_CTX_init(ctx);
  if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL)!= 1) {
    fprintf(stderr, "EVP_EncryptInit_ex() failed\n");
    exit(EXIT_FAILURE);
  }

  EVP_CIPHER_CTX_set_padding(ctx, 0);

  int ciphertext_len;
  unsigned char* ciphertext_out = (unsigned char*)malloc(plaintext_len);
  if (ciphertext_out == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  int ret = 0;
  ret = EVP_EncryptUpdate(ctx, ciphertext_out, &ciphertext_len, plaintext, plaintext_len);
  if (ret <= 0) {
    fprintf(stderr, "EVP_EncryptUpdate() failed\n");
    exit(EXIT_FAILURE);
  }

  ret = EVP_EncryptFinal_ex(ctx, ciphertext_out + ciphertext_len, &ciphertext_len);
  if (ret <= 0) {
    fprintf(stderr, "EVP_EncryptFinal_ex() failed\n");
    exit(EXIT_FAILURE);
  }

  ciphertext[plaintext_len] = '\0';

  printf("Ciphertext: %s\n", ciphertext);

  EVP_CIPHER_CTX_cleanup(ctx);
  EVP_CIPHER_CTX_free(ctx);
  free(key);
  free(ciphertext_out);

  return 0;
}