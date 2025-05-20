//FormAI DATASET v1.0 Category: Modern Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// The plaintext message to be encrypted
char message[] = "Hello, world!";

int main() {
  // Initialize the OpenSSL library
  EVP_add_cipher(EVP_aes_256_cbc());

  // Generate a random 256-bit key and IV
  unsigned char key[EVP_MAX_KEY_LENGTH];
  unsigned char iv[EVP_MAX_IV_LENGTH];
  RAND_bytes(key, sizeof(key));
  RAND_bytes(iv, sizeof(iv));

  // Allocate space for the ciphertext (the same size as the plaintext 
  // plus one block for padding)
  size_t cyphertext_len = strlen(message) + EVP_CIPHER_block_size(EVP_aes_256_cbc());
  unsigned char *cyphertext = malloc(cyphertext_len);

  // Create a cipher context for encryption
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

  // Encrypt the plaintext into the cyphertext
  int len;
  EVP_EncryptUpdate(ctx, cyphertext, &len, (unsigned char *) message, strlen(message));
  int cyphertext_len2;
  EVP_EncryptFinal_ex(ctx, cyphertext + len, &cyphertext_len2);

  // Cleanup the cipher context
  EVP_CIPHER_CTX_free(ctx);

  // Print out the results
  printf("Message: %s\n", message);
  printf("Key: ");
  for (int i = 0; i < sizeof(key); i++) {
    printf("%02x", key[i]);
  }
  printf("\nIV: ");
  for (int i = 0; i < sizeof(iv); i++) {
    printf("%02x", iv[i]);
  }
  printf("\nCyphertext: ");
  for (int i = 0; i < cyphertext_len; i++) {
    printf("%02x", cyphertext[i]);
  }
  printf("\n");

  // Free the ciphertext buffer
  free(cyphertext);

  return 0;
}