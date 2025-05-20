//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: satisfied
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <string to hash>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Initialize the OpenSSL library
  OpenSSL_add_all_digests();

  // Create a SHA256 context
  EVP_MD_CTX *ctx = EVP_MD_CTX_create();
  if (ctx == NULL) {
    perror("EVP_MD_CTX_create");
    return EXIT_FAILURE;
  }

  // Initialize the SHA256 context
  if (EVP_DigestInit_ex(ctx, EVP_sha256(), NULL) != 1) {
    perror("EVP_DigestInit_ex");
    EVP_MD_CTX_destroy(ctx);
    return EXIT_FAILURE;
  }

  // Update the SHA256 context with the string to hash
  if (EVP_DigestUpdate(ctx, argv[1], strlen(argv[1])) != 1) {
    perror("EVP_DigestUpdate");
    EVP_MD_CTX_destroy(ctx);
    return EXIT_FAILURE;
  }

  // Finalize the SHA256 context
  unsigned char hash[SHA256_DIGEST_LENGTH];
  unsigned int hash_len;
  if (EVP_DigestFinal_ex(ctx, hash, &hash_len) != 1) {
    perror("EVP_DigestFinal_ex");
    EVP_MD_CTX_destroy(ctx);
    return EXIT_FAILURE;
  }

  // Print the hash
  printf("SHA256 hash: ");
  for (int i = 0; i < hash_len; i++) {
    printf("%02x", hash[i]);
  }
  printf("\n");

  // Clean up
  EVP_MD_CTX_destroy(ctx);
  return EXIT_SUCCESS;
}