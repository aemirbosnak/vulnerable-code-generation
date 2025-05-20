//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024 

typedef struct {
    unsigned char *data;
    size_t len;
} byte_array_t;

void print_byte_array(byte_array_t *ba) {
    printf("0x");
    for(int i = 0; i < ba->len; i++) {
        printf("%02x", ba->data[i]);
    }
    printf("\n");
}

void xor_byte_array(byte_array_t *ba1, byte_array_t *ba2, byte_array_t *result) {
    if(ba1->len != ba2->len) {
        fprintf(stderr, "Error: Cannot XOR byte arrays of different lengths\n");
        return;
    }

    for(int i = 0; i < ba1->len; i++) {
        result->data[i] = ba1->data[i] ^ ba2->data[i];
    }
}

void hashlib_sha256(byte_array_t *input, byte_array_t *output) {
    // implementation of SHA-256 hashing algorithm
    // ...
}

void generate_key_and_IV(char *password, byte_array_t *key, byte_array_t *IV) {
    byte_array_t password_hash;
    password_hash.len = 32;
    password_hash.data = malloc(32);

    hashlib_sha256(password, &password_hash);

    // key and IV generation based on password hash
    // ...

    free(password_hash.data);
}

void encrypt_CBC(byte_array_t *plaintext, byte_array_t *ciphertext, byte_array_t *key, byte_array_t *IV) {
    byte_array_t block, prev_cipher_block, xor_res;
    block.data = malloc(16);
    block.len = 16;
    prev_cipher_block.data = malloc(16);
    prev_cipher_block.len = 16;
    xor_res.data = malloc(16);
    xor_res.len = 16;

    memcpy(prev_cipher_block.data, IV->data, 16);

    for(int i = 0; i < plaintext->len; i += 16) {
        memcpy(block.data, plaintext->data + i, 16);
        xor_byte_array(&block, &prev_cipher_block, &xor_res);
        // encryption of XORed block and key
        // ...
        memcpy(prev_cipher_block.data, ciphertext->data + i, 16);
    }

    free(block.data);
    free(prev_cipher_block.data);
    free(xor_res.data);
}

void decrypt_CBC(byte_array_t *ciphertext, byte_array_t *plaintext, byte_array_t *key, byte_array_t *IV) {
    byte_array_t block, prev_cipher_block, xor_res;
    block.data = malloc(16);
    block.len = 16;
    prev_cipher_block.data = malloc(16);
    prev_cipher_block.len = 16;
    xor_res.data = malloc(16);
    xor_res.len = 16;

    memcpy(prev_cipher_block.data, IV->data, 16);

    for(int i = 0; i < ciphertext->len; i += 16) {
        memcpy(block.data, ciphertext->data + i, 16);
        // decryption of block and key
        // ...
        xor_byte_array(&block, &prev_cipher_block, &xor_res);
        memcpy(plaintext->data + i, xor_res.data, 16);
        memcpy(prev_cipher_block.data, block.data, 16);
    }

    free(block.data);
    free(prev_cipher_block.data);
    free(xor_res.data);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Error: Usage: %s [plaintext file]\n", argv[0]);
        return 1;
    }

    char *password = "my_secure_password";
    byte_array_t key, IV, plaintext, ciphertext;
    key.len = 16; // AES-128
    key.data = malloc(16);
    IV.len = 16;
    IV.data = malloc(16);

    generate_key_and_IV(password, &key, &IV);

    plaintext.data = malloc(BUFF_SIZE);
    plaintext.len = fread(plaintext.data, 1, BUFF_SIZE, stdin);

    ciphertext.data = malloc(plaintext.len);
    ciphertext.len = plaintext.len;

    encrypt_CBC(&plaintext, &ciphertext, &key, &IV);

    printf("Ciphertext:\n");
    print_byte_array(&ciphertext);

    byte_array_t decrypted_text;
    decrypted_text.data = malloc(ciphertext.len); 
    decrypted_text.len = ciphertext.len;

    decrypt_CBC(&ciphertext, &decrypted_text, &key, &IV);

    printf("Decrypted text:\n");
    print_byte_array(&decrypted_text);

    free(key.data);
    free(IV.data);
    free(plaintext.data);
    free(ciphertext.data);
    free(decrypted_text.data);

    return 0;
}