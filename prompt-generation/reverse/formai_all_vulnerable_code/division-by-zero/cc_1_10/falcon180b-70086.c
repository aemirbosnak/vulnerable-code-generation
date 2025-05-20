//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16
#define MAX_BLOCK_SIZE 32

typedef struct {
    unsigned char key[MAX_KEY_SIZE];
    unsigned int key_size;
} encryption_key;

void generate_random_key(encryption_key *key) {
    for (int i = 0; i < key->key_size; i++) {
        key->key[i] = rand() % 256;
    }
}

void encrypt_data(const encryption_key *key, unsigned char *data, int data_size) {
    for (int i = 0; i < data_size; i++) {
        data[i] ^= key->key[i % key->key_size];
    }
}

void decrypt_data(const encryption_key *key, unsigned char *data, int data_size) {
    for (int i = 0; i < data_size; i++) {
        data[i] ^= key->key[i % key->key_size];
    }
}

int main() {
    encryption_key key;
    generate_random_key(&key);

    unsigned char data[] = "Hello, world!";
    int data_size = strlen((char *)data);

    encrypt_data(&key, (unsigned char *)data, data_size);

    printf("Encrypted data: ");
    for (int i = 0; i < data_size; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");

    decrypt_data(&key, (unsigned char *)data, data_size);

    printf("Decrypted data: %s\n", data);

    return 0;
}