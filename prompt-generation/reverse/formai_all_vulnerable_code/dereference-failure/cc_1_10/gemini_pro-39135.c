//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: authentic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

void print_bytes(unsigned char *buf, size_t len) {
  size_t i;
  for (i = 0; i < len; i++) {
    printf("%02x", buf[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <key> <input> <output>\n", argv[0]);
    return EXIT_FAILURE;
  }

  unsigned char *key = (unsigned char *)argv[1];
  size_t keylen = strlen(argv[1]);
  unsigned char *plaintext = (unsigned char *)argv[2];
  size_t plaintext_len = strlen(argv[2]);
  unsigned char *ciphertext = malloc(plaintext_len + EVP_MAX_BLOCK_LENGTH);
  int ciphertext_len;

  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  if (ctx == NULL) {
    fprintf(stderr, "Failed to create cipher context\n");
    return EXIT_FAILURE;
  }

  if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cfb(), NULL, key, NULL) != 1) {
    fprintf(stderr, "Failed to initialize cipher\n");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len) != 1) {
    fprintf(stderr, "Failed to encrypt plaintext\n");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len) != 1) {
    fprintf(stderr, "Failed to finalize encryption\n");
    EVP_CIPHER_CTX_free(ctx);
    return EXIT_FAILURE;
  }

  EVP_CIPHER_CTX_free(ctx);

  FILE *output = fopen(argv[3], "wb");
  if (output == NULL) {
    fprintf(stderr, "Failed to open output file\n");
    free(ciphertext);
    return EXIT_FAILURE;
  }

  fwrite(ciphertext, 1, ciphertext_len, output);
  fclose(output);

  free(ciphertext);

  return EXIT_SUCCESS;
}