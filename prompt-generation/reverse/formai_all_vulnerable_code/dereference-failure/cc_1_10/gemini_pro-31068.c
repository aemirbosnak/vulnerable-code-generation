//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/rand.h>
#include <openssl/aes.h>

typedef unsigned char byte;

typedef struct {
    byte key[AES_BLOCK_SIZE];
    byte iv[AES_BLOCK_SIZE];
} aes_key_iv_pair;

aes_key_iv_pair generate_aes_key_iv_pair() {
    aes_key_iv_pair key_iv_pair;
    RAND_bytes(key_iv_pair.key, AES_BLOCK_SIZE);
    RAND_bytes(key_iv_pair.iv, AES_BLOCK_SIZE);
    return key_iv_pair;
}

void encrypt_aes_256_cbc(byte *plaintext, size_t plaintext_len,
                         byte *key, byte *iv, byte *ciphertext) {
    AES_KEY enc_key;
    AES_set_encrypt_key(key, 256, &enc_key);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &enc_key, iv, AES_ENCRYPT);
}

void decrypt_aes_256_cbc(byte *ciphertext, size_t ciphertext_len,
                         byte *key, byte *iv, byte *plaintext) {
    AES_KEY dec_key;
    AES_set_decrypt_key(key, 256, &dec_key);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &dec_key, iv, AES_DECRYPT);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s plaintext ciphertext\n", argv[0]);
        return 1;
    }
    FILE *plaintext_file = fopen(argv[1], "rb");
    if (plaintext_file == NULL) {
        perror("Error opening plaintext file");
        return 1;
    }
    FILE *ciphertext_file = fopen(argv[2], "wb");
    if (ciphertext_file == NULL) {
        perror("Error opening ciphertext file");
        return 1;
    }
    fseek(plaintext_file, 0, SEEK_END);
    size_t plaintext_len = ftell(plaintext_file);
    rewind(plaintext_file);
    byte *plaintext = malloc(plaintext_len);
    fread(plaintext, 1, plaintext_len, plaintext_file);
    fclose(plaintext_file);
    aes_key_iv_pair key_iv_pair = generate_aes_key_iv_pair();
    byte *ciphertext = malloc(plaintext_len + AES_BLOCK_SIZE);
    encrypt_aes_256_cbc(plaintext, plaintext_len, key_iv_pair.key, key_iv_pair.iv, ciphertext);
    fwrite(ciphertext, 1, plaintext_len + AES_BLOCK_SIZE, ciphertext_file);
    fclose(ciphertext_file);
    free(plaintext);
    free(ciphertext);
    return 0;
}