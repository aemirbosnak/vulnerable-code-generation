//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <openssl/aes.h>

#define BLOCK_SIZE 16

int main() {
    uint8_t key[32] = {0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, 0x9A, 0xBC, 0xDE, 0xF0};
    uint8_t iv[BLOCK_SIZE] = {0x00};
    char* data = "Hello World! This is a test string.";
    size_t len = strlen(data) + 1; // add 1 for null terminator
    uint8_t* ciphertext = calloc(len + BLOCK_SIZE, sizeof(uint8_t)); // allocate extra space for padding
    uint8_t* decryptedtext = calloc(len + BLOCK_SIZE, sizeof(uint8_t)); // allocate extra space for padding

    // set up AES context
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 256, &aes_key);

    // generate random IV (for production use only)
    srand(time(NULL));
    for (int i = 0; i < BLOCK_SIZE; i++) {
        iv[i] = rand() % 256;
    }

    // encrypt data
    int ciphertext_len = 0;
    AES_cbc_encrypt(data, ciphertext, len, &aes_key, iv, AES_ENCRYPT);

    // print encrypted data
    printf("*** Encrypted data: ***\n");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", iv[i]);
    }
    for (int i = 0; i < len + BLOCK_SIZE; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    // set up AES context for decryption
    memset(&aes_key, 0, sizeof(aes_key));
    AES_set_decrypt_key(key, 256, &aes_key);

    // decrypt data
    int decryptedtext_len = 0;
    AES_cbc_encrypt(ciphertext, decryptedtext, len + BLOCK_SIZE, &aes_key, iv, AES_DECRYPT);

    // print decrypted data
    printf("*** Decrypted data: ***\n");
    printf("%s\n", decryptedtext);

    // free memory
    free(ciphertext);
    free(decryptedtext);

    return 0;
}