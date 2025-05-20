//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <openssl/aes.h>

#define AES_KEY_LENGTH 128
#define BLOCK_SIZE 16

typedef struct {
    unsigned char *input;
    unsigned char *output;
    int length;
    unsigned char *key;
} ThreadData;

void *encrypt(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    AES_KEY encryptKey;

    // Set the encryption key
    if (AES_set_encrypt_key(data->key, AES_KEY_LENGTH, &encryptKey) < 0) {
        fprintf(stderr, "Failed to set encryption key.\n");
        pthread_exit(NULL);
    }

    // Encrypt the input data in blocks
    for (int i = 0; i < data->length; i += BLOCK_SIZE) {
        AES_encrypt(data->input + i, data->output + i, &encryptKey);
    }

    pthread_exit(NULL);
}

void *decrypt(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    AES_KEY decryptKey;

    // Set the decryption key
    if (AES_set_decrypt_key(data->key, AES_KEY_LENGTH, &decryptKey) < 0) {
        fprintf(stderr, "Failed to set decryption key.\n");
        pthread_exit(NULL);
    }

    // Decrypt the input data in blocks
    for (int i = 0; i < data->length; i += BLOCK_SIZE) {
        AES_decrypt(data->input + i, data->output + i, &decryptKey);
    }

    pthread_exit(NULL);
}

void print_hex(unsigned char *buf, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02x", buf[i]);
    }
    printf("\n");
}

int main() {
    const char *keyString = "mysecretkey12345"; // Must be 16 bytes for AES-128
    unsigned char *data = (unsigned char *)"This is a test input of 32 bytes!"; // Example input
    int length = strlen((char *)data);
    unsigned char *encrypted = (unsigned char *)malloc(length);
    unsigned char *decrypted = (unsigned char *)malloc(length);
    unsigned char key[AES_KEY_LENGTH / 8];

    // Prepare the key
    memcpy(key, keyString, AES_KEY_LENGTH / 8);

    // Create thread data structures
    ThreadData encryptData;
    encryptData.input = data;
    encryptData.output = encrypted;
    encryptData.length = length;
    encryptData.key = key;

    ThreadData decryptData;
    decryptData.input = encrypted;
    decryptData.output = decrypted;
    decryptData.length = length;
    decryptData.key = key;

    pthread_t encryptThread, decryptThread;

    // Start encryption thread
    if (pthread_create(&encryptThread, NULL, encrypt, (void *)&encryptData) != 0) {
        fprintf(stderr, "Error creating encryption thread.\n");
        return 1;
    }

    // Wait for encryption to complete
    pthread_join(encryptThread, NULL);
    printf("Encrypted Output: ");
    print_hex(encrypted, length);

    // Start decryption thread
    if (pthread_create(&decryptThread, NULL, decrypt, (void *)&decryptData) != 0) {
        fprintf(stderr, "Error creating decryption thread.\n");
        return 1;
    }

    // Wait for decryption to complete
    pthread_join(decryptThread, NULL);
    printf("Decrypted Output: %s\n", decrypted);

    // Clean up
    free(encrypted);
    free(decrypted);

    return 0;
}