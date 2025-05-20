//FormAI DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int key_index = 0;
    for (int i = 0; i < message_length; i++) {
        if (key[key_index] == '\0') {
            key_index = 0;
        }
        message[i] = message[i] ^ key[key_index];
        key_index++;
    }
}

void decrypt(char* message, char* key) {
    encrypt(message, key);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <encrypt/decrypt> <message> <key>\n", argv[0]);
        return 1;
    }

    char* operation = argv[1];
    char* message = argv[2];
    char* key = argv[3];

    if (strcmp(operation, "encrypt") != 0 && strcmp(operation, "decrypt") != 0) {
        printf("Invalid operation: %s\n", operation);
        return 1;
    }

    if (strlen(message) > MAX_LENGTH || strlen(key) > MAX_LENGTH) {
        printf("Message or key is too long\n");
        return 1;
    }

    if (strcmp(operation, "encrypt") == 0) {
        encrypt(message, key);
        printf("Encrypted message: %s\n", message);
    }

    if (strcmp(operation, "decrypt") == 0) {
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}