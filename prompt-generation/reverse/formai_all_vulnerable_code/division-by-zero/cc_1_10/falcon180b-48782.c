//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 100

void encrypt_message(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - 'a' + key[j]) % 26 + 'a';
            message[i] = c;
            j = (j + 1) % key_length;
        }
    }
}

void decrypt_message(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c - 'a' - key[j]) % 26 + 'a';
            message[i] = c;
            j = (j + 1) % key_length;
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter a key to use for encryption: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt_message(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt_message(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}