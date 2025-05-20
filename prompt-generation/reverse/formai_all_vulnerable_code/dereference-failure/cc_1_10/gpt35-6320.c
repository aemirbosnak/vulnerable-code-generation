//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BLOCK_SIZE 16
#define SALT_SIZE 8

void print_hex(const unsigned char* data, size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf("%02x", data[i]);
  }
  printf("\n");
}

int encrypt_data(const unsigned char* plaintext, size_t plaintext_len,
                 const char* password, unsigned char** ciphertext, size_t* ciphertext_len) {
  size_t key_len = EVP_MAX_KEY_LENGTH;
  size_t iv_len = EVP_MAX_IV_LENGTH;
  unsigned char key[EVP_MAX_KEY_LENGTH];
  unsigned char iv[EVP_MAX_IV_LENGTH];

  *ciphertext_len = 0;

  if (RAND_bytes(iv, iv_len) != 1) {
    return 0;
  }

  if (RAND_pseudo_bytes(key, key_len) != 1) {
    return 0;
  }

  unsigned char salt[SALT_SIZE];
  if (RAND_bytes(salt, SALT_SIZE) != 1) {
    return 0;
  }

  printf("Salt: ");
  print_hex(salt, SALT_SIZE);

  const EVP_CIPHER* cipher = EVP_aes_256_cbc();
  const EVP_MD* md = EVP_sha256();
  const int iterations = 1000;
  int ciphertext_len_local;
  int plaintext_len_local;

  EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();

  if (EVP_BytesToKey(cipher, md, salt,
                     (unsigned char*) password, strlen(password),
                     iterations, key, iv) != 1) {
    return 0;
  }

  if (EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv) != 1) {
    return 0;
  }

  plaintext_len_local = plaintext_len;

  if (EVP_EncryptUpdate(ctx, *ciphertext, &ciphertext_len_local, plaintext, plaintext_len_local) != 1) {
    return 0;
  }

  *ciphertext_len = ciphertext_len_local;

  printf("Ciphertext: ");
  print_hex(*ciphertext, *ciphertext_len);

  if (EVP_EncryptFinal_ex(ctx, *ciphertext + *ciphertext_len, &ciphertext_len_local) != 1) {
    return 0;
  }

  *ciphertext_len += ciphertext_len_local;

  if (ctx) {
    EVP_CIPHER_CTX_free(ctx);
  }

  return 1;
}

int main() {
  const unsigned char plaintext[] = "This is a secret message!";
  const char* password = "mypassword";
  unsigned char* ciphertext = malloc(1024);
  size_t ciphertext_len = 0;

  if (encrypt_data(plaintext, sizeof(plaintext), password, &ciphertext, &ciphertext_len) != 1) {
    printf("Encryption failed!\n");
    free(ciphertext);
    return EXIT_FAILURE;
  }

  free(ciphertext);
  return EXIT_SUCCESS;
}