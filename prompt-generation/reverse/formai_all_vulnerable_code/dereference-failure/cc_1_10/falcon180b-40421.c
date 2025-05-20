//Falcon-180B DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8
#define ROUNDS 10

void encrypt(char* message, char* key, char* encrypted_message);
void decrypt(char* encrypted_message, char* key, char* decrypted_message);

int main() {
    char message[] = "Hello World!";
    char key[] = "MySecretKey123";
    char encrypted_message[sizeof(message)];
    char decrypted_message[sizeof(message)];

    encrypt(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}

void encrypt(char* message, char* key, char* encrypted_message) {
    int message_size = strlen(message);
    int key_size = strlen(key);
    int rounds = ROUNDS;
    int i, j;

    char key_expanded[KEY_SIZE];
    for (i = 0; i < key_size; i++) {
        key_expanded[i] = key[i];
    }

    for (i = key_size; i < KEY_SIZE; i++) {
        key_expanded[i] = (char) (i % 256);
    }

    char state[KEY_SIZE];
    memcpy(state, key_expanded, KEY_SIZE);

    int index = 0;
    for (i = 0; i < message_size; i += BLOCK_SIZE) {
        char block[BLOCK_SIZE];
        memcpy(block, message + i, BLOCK_SIZE);

        for (j = 0; j < BLOCK_SIZE; j++) {
            block[j] ^= state[index++ % KEY_SIZE];
        }

        memcpy(encrypted_message + i, block, BLOCK_SIZE);
    }
}

void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int message_size = strlen(encrypted_message);
    int key_size = strlen(key);
    int rounds = ROUNDS;
    int i, j;

    char key_expanded[KEY_SIZE];
    for (i = 0; i < key_size; i++) {
        key_expanded[i] = key[i];
    }

    for (i = key_size; i < KEY_SIZE; i++) {
        key_expanded[i] = (char) (i % 256);
    }

    char state[KEY_SIZE];
    memcpy(state, key_expanded, KEY_SIZE);

    int index = 0;
    for (i = 0; i < message_size; i += BLOCK_SIZE) {
        char block[BLOCK_SIZE];
        memcpy(block, encrypted_message + i, BLOCK_SIZE);

        for (j = 0; j < BLOCK_SIZE; j++) {
            block[j] ^= state[index++ % KEY_SIZE];
        }

        memcpy(decrypted_message + i, block, BLOCK_SIZE);
    }
}