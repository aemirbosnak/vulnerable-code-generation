//Falcon-180B DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;
    char encrypted_message[MAX_MESSAGE_LENGTH];

    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: Key is too long.\n");
        exit(1);
    }

    for (i = 0, j = 0; i < message_length; i++) {
        encrypted_message[j++] = message[i] ^ key[i % key_length];
    }
    encrypted_message[message_length] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int i, j;
    char decrypted_message[MAX_MESSAGE_LENGTH];

    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: Key is too long.\n");
        exit(1);
    }

    for (i = 0, j = 0; i < encrypted_message_length; i++) {
        decrypted_message[j++] = encrypted_message[i] ^ key[i % key_length];
    }
    decrypted_message[encrypted_message_length] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}