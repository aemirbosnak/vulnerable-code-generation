//FormAI DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_SIZE 16
#define BUFFER_SIZE 1024

typedef struct {
    char* key;
    int key_length;
} EncryptionKey;

char* generate_key(int length) {
    char* key = malloc(length + 1);
    int i;

    srand(time(NULL));

    for (i = 0; i < length; i++) {
        key[i] = rand() % 256;
    }

    key[length] = '\0';

    return key;
}

EncryptionKey* create_encryption_key(int length) {
    EncryptionKey* key = malloc(sizeof(EncryptionKey));
    key->key = generate_key(length);
    key->key_length = length;

    return key;
}

void destroy_encryption_key(EncryptionKey* key) {
    free(key->key);
    free(key);
}

void encrypt(char* buffer, int length, EncryptionKey* key) {
    int i;

    for (i = 0; i < length; i++) {
        buffer[i] ^= key->key[i % key->key_length];
    }
}

void decrypt(char* buffer, int length, EncryptionKey* key) {
    encrypt(buffer, length, key);
}

void print_hex(char* buffer, int length) {
    int i;

    for (i = 0; i < length; i++) {
        printf("%02X ", (unsigned char) buffer[i]);
    }

    printf("\n");
}

void print_key(EncryptionKey* key) {
    printf("Key: ");
    print_hex(key->key, key->key_length);
    printf("Key Length: %d\n", key->key_length);
}

void print_buffer(char* buffer, int length) {
    printf("Buffer: ");
    print_hex(buffer, length);
    printf("\n");
}

int main() {
    char buffer[BUFFER_SIZE] = {0};
    char* message = "Hello, world!";
    EncryptionKey* key = create_encryption_key(KEY_SIZE);

    printf("Original Message: %s\n", message);

    strncpy(buffer, message, strlen(message));
    encrypt(buffer, strlen(buffer), key);

    printf("Encrypted Message: ");
    print_buffer(buffer, strlen(buffer));
    
    memset(buffer, 0, BUFFER_SIZE);
    strncpy(buffer, message, strlen(message));
    decrypt(buffer, strlen(buffer), key);

    printf("Decrypted Message: %s\n", buffer);

    destroy_encryption_key(key);

    return 0;
}