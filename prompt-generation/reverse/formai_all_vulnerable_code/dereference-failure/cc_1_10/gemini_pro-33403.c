//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/pem.h>
#include <openssl/evp.h>

EVP_PKEY *generate_private_key() {
  EVP_PKEY_CTX *pkey_ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_EC, NULL);
  if (!EVP_PKEY_keygen_init(pkey_ctx)) {
    return NULL;
  }
  EVP_PKEY *pkey = NULL;
  if (!EVP_PKEY_keygen(pkey_ctx, &pkey)) {
    return NULL;
  }
  EVP_PKEY_CTX_free(pkey_ctx);
  return pkey;
}

EVP_PKEY *load_private_key(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }
  EVP_PKEY *pkey = PEM_read_PrivateKey(fp, NULL, NULL, NULL);
  fclose(fp);
  return pkey;
}

EVP_PKEY *load_public_key(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }
  EVP_PKEY *pkey = PEM_read_PUBKEY(fp, NULL, NULL, NULL);
  fclose(fp);
  return pkey;
}

int encrypt(EVP_PKEY *pkey, const unsigned char *plaintext, size_t plaintext_len,
            unsigned char **ciphertext, size_t *ciphertext_len) {
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, NULL, NULL)) {
    return 0;
  }
  if (!EVP_CIPHER_CTX_set_key_length(ctx, EVP_CIPHER_key_length(EVP_aes_256_cbc()))) {
    return 0;
  }
  if (!EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, 12, NULL)) {
    return 0;
  }
  if (!EVP_EncryptInit_ex(ctx, NULL, NULL, pkey, NULL)) {
    return 0;
  }
  *ciphertext_len = plaintext_len + EVP_CIPHER_CTX_block_size(ctx);
  *ciphertext = malloc(*ciphertext_len);
  if (*ciphertext == NULL) {
    return 0;
  }
  int ciphertext_out_len = 0;
  if (!EVP_EncryptUpdate(ctx, *ciphertext, &ciphertext_out_len, plaintext, plaintext_len)) {
    return 0;
  }
  if (!EVP_EncryptFinal_ex(ctx, *ciphertext + ciphertext_out_len, &ciphertext_out_len)) {
    return 0;
  }
  *ciphertext_len = ciphertext_out_len;
  EVP_CIPHER_CTX_free(ctx);
  return 1;
}

int decrypt(EVP_PKEY *pkey, const unsigned char *ciphertext, size_t ciphertext_len,
            unsigned char **plaintext, size_t *plaintext_len) {
  EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
  if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, NULL, NULL)) {
    return 0;
  }
  if (!EVP_CIPHER_CTX_set_key_length(ctx, EVP_CIPHER_key_length(EVP_aes_256_cbc()))) {
    return 0;
  }
  if (!EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, 12, NULL)) {
    return 0;
  }
  if (!EVP_DecryptInit_ex(ctx, NULL, NULL, pkey, NULL)) {
    return 0;
  }
  *plaintext_len = ciphertext_len - EVP_CIPHER_CTX_block_size(ctx);
  *plaintext = malloc(*plaintext_len);
  if (*plaintext == NULL) {
    return 0;
  }
  int plaintext_out_len = 0;
  if (!EVP_DecryptUpdate(ctx, *plaintext, &plaintext_out_len, ciphertext, ciphertext_len)) {
    return 0;
  }
  if (!EVP_DecryptFinal_ex(ctx, *plaintext + plaintext_out_len, &plaintext_out_len)) {
    return 0;
  }
  *plaintext_len = plaintext_out_len;
  EVP_CIPHER_CTX_free(ctx);
  return 1;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    printf("Usage: %s <private_key> <public_key> <plaintext>\n", argv[0]);
    return 1;
  }

  EVP_PKEY *privkey = load_private_key(argv[1]);
  if (privkey == NULL) {
    printf("Error loading private key\n");
    return 1;
  }

  EVP_PKEY *pubkey = load_public_key(argv[2]);
  if (pubkey == NULL) {
    printf("Error loading public key\n");
    return 1;
  }

  FILE *fp = fopen(argv[3], "r");
  if (fp == NULL) {
    printf("Error opening plaintext file\n");
    return 1;
  }

  fseek(fp, 0, SEEK_END);
  size_t plaintext_len = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  unsigned char *plaintext = malloc(plaintext_len);
  if (plaintext == NULL) {
    printf("Error allocating memory for plaintext\n");
    return 1;
  }

  if (fread(plaintext, 1, plaintext_len, fp) != plaintext_len) {
    printf("Error reading plaintext file\n");
    return 1;
  }

  fclose(fp);

  unsigned char *ciphertext = NULL;
  size_t ciphertext_len = 0;
  if (!encrypt(pubkey, plaintext, plaintext_len, &ciphertext, &ciphertext_len)) {
    printf("Error encrypting plaintext\n");
    return 1;
  }

  unsigned char *decrypted_plaintext = NULL;
  size_t decrypted_plaintext_len = 0;
  if (!decrypt(privkey, ciphertext, ciphertext_len, &decrypted_plaintext, &decrypted_plaintext_len)) {
    printf("Error decrypting ciphertext\n");
    return 1;
  }

  if (memcmp(plaintext, decrypted_plaintext, decrypted_plaintext_len) != 0) {
    printf("Decrypted plaintext does not match original plaintext\n");
    return 1;
  }

  printf("Plaintext decrypted successfully\n");

  EVP_PKEY_free(privkey);
  EVP_PKEY_free(pubkey);
  free(plaintext);
  free(ciphertext);
  free(decrypted_plaintext);

  return 0;
}