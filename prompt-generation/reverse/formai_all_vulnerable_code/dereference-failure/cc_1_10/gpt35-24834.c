//FormAI DATASET v1.0 Category: Modern Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int key_len;
} EncryptionKey;

void encrypt(char *, EncryptionKey);
void decrypt(char *, EncryptionKey);

int main() {
    char message[256];
    EncryptionKey key;

    printf("Enter message to encrypt: ");
    fgets(message, 256, stdin);
    printf("Enter encryption key: ");
    scanf("%m[^\n]", &key.key);
    key.key_len = strlen(key.key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    free(key.key);
    return 0;
}

void encrypt(char *message, EncryptionKey key) {
    int message_len = strlen(message);
    int key_index = 0;

    for(int i = 0; i < message_len; i++) {
        message[i] = message[i] + key.key[key_index];
        key_index = (key_index + 1) % key.key_len;
    }
}

void decrypt(char *message, EncryptionKey key) {
    int message_len = strlen(message);
    int key_index = 0;

    for(int i = 0; i < message_len; i++) {
        message[i] = message[i] - key.key[key_index];
        key_index = (key_index + 1) % key.key_len;
    }
}