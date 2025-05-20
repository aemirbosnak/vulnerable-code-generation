//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16
#define SALT_SIZE 16

typedef struct {
    int block_size;
    int key_size;
    int salt_size;
} EncryptionParameters;

void generate_key(char* key, char* salt, int key_size, int salt_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = 'a' + rand() % 26;
        salt[i] = 'a' + rand() % 26;
    }
    key[key_size] = '\0';
    salt[salt_size] = '\0';
}

void encrypt(char* plaintext, char* ciphertext, char* key, char* salt, int key_size, int salt_size, EncryptionParameters params) {
    int block_count = strlen(plaintext) / params.block_size;
    int block_size_offset = (BLOCK_SIZE - params.block_size) % params.block_size;
    int salt_count = strlen(salt) / params.salt_size;
    int salt_size_offset = (SALT_SIZE - params.salt_size) % params.salt_size;

    for (int i = 0; i < block_count; i++) {
        int block_start = i * params.block_size;
        int block_end = (i + 1) * params.block_size;
        int salt_start = i * salt_count;
        int salt_end = (i + 1) * salt_count;

        char* block = (char*) malloc(params.block_size + 1);
        char* salt = (char*) malloc(params.salt_size + 1);

        memcpy(block, plaintext + block_start, params.block_size);
        memcpy(salt, salt + salt_start, params.salt_size);

        int j = 0;
        for (int k = 0; k < params.key_size; k++) {
            int index = (j + salt[k]) % (BLOCK_SIZE + salt_size_offset);
            block[j] = (block[j] + 1) % 26 + 'a';
            salt[j] = (salt[j] + 1) % 26 + 'a';
            j++;
        }

        block[params.block_size] = '\0';
        salt[params.salt_size] = '\0';

        ciphertext = (char*) realloc(ciphertext, (i + 1) * (BLOCK_SIZE + 1));
        memcpy(ciphertext + i * (BLOCK_SIZE + 1), block, params.block_size + 1);
    }
}

int main() {
    EncryptionParameters params = {BLOCK_SIZE, KEY_SIZE, SALT_SIZE};
    char key[KEY_SIZE + 1];
    char salt[SALT_SIZE + 1];
    char plaintext[100];
    char ciphertext[100];

    generate_key(key, salt, KEY_SIZE, SALT_SIZE);

    printf("Key: %s\n", key);
    printf("Salt: %s\n", salt);

    printf("Plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    encrypt(plaintext, ciphertext, key, salt, KEY_SIZE, SALT_SIZE, params);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}