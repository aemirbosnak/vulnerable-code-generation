//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

void handleErrors() {
    fprintf(stderr, "An error occurred!\n");
    exit(EXIT_FAILURE);
}

void printData(const char *label, const unsigned char *data, size_t len) {
    printf("%s: ", label);
    for (size_t i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

void generateRandomKey(unsigned char *key, size_t length) {
    if (!RAND_bytes(key, length)) {
        handleErrors();
    }
}

void encrypt(const unsigned char *plaintext, size_t plaintext_len, 
             const unsigned char *key, unsigned char *ciphertext) {
    AES_KEY encryptKey;
    if (AES_set_encrypt_key(key, 128, &encryptKey)) {
        handleErrors();
    }
    
    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0, AES_BLOCK_SIZE);  // Initialization vector

    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &encryptKey, iv, AES_ENCRYPT);
}

void decrypt(const unsigned char *ciphertext, size_t ciphertext_len, 
             const unsigned char *key, unsigned char *plaintext) {
    AES_KEY decryptKey;
    if (AES_set_decrypt_key(key, 128, &decryptKey)) {
        handleErrors();
    }
    
    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0, AES_BLOCK_SIZE);  // Same IV as used in encryption

    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &decryptKey, iv, AES_DECRYPT);
}

void padData(unsigned char *data, size_t *data_len) {
    size_t pad_len = AES_BLOCK_SIZE - (*data_len % AES_BLOCK_SIZE);
    for (size_t i = 0; i < pad_len; i++) {
        data[*data_len + i] = pad_len;
    }
    *data_len += pad_len;
}

void unpadData(unsigned char *data, size_t *data_len) {
    size_t pad_len = data[*data_len - 1];
    *data_len -= pad_len;
}

int main() {
    printf("Welcome to the Enthusiastic AES Encryptor!\n");

    unsigned char key[16];  // AES-128 key size
    generateRandomKey(key, sizeof(key));

    const char *message = "Hello, world! This is a secure message!";
    size_t plaintext_len = strlen(message);
    unsigned char *ciphertext = malloc(plaintext_len + AES_BLOCK_SIZE);
    unsigned char *decryptedtext = malloc(plaintext_len + AES_BLOCK_SIZE);

    printf("Original Message: %s\n", message);

    padData((unsigned char *)message, &plaintext_len);
    encrypt((unsigned char *)message, plaintext_len, key, ciphertext);
    
    printData("Ciphertext", ciphertext, plaintext_len);
    printf("Encryption Completed Successfully!\n");

    decrypt(ciphertext, plaintext_len, key, decryptedtext);
    unpadData(decryptedtext, &plaintext_len);
    
    printf("Decrypted Message: %s\n", decryptedtext);
    printf("Decryption Completed Successfully!\n");

    free(ciphertext);
    free(decryptedtext);

    return 0;
}