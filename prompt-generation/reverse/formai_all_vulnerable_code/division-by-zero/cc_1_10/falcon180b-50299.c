//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 128

void generate_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_length] = '\0';
}

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[MAX_MESSAGE_LENGTH];
    int encrypted_message_length = 0;

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            char c = toupper(message[i]);
            int k = (int)key[i % key_length] - 65;
            int e = (c - 65 + k) % 26;
            encrypted_message[encrypted_message_length++] = e + 65;
        } else {
            encrypted_message[encrypted_message_length++] = message[i];
        }
    }
    encrypted_message[encrypted_message_length] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int decrypted_message_length = 0;

    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            char c = encrypted_message[i];
            int k = (int)key[i % key_length] - 65;
            int e = (c - 65 - k + 26) % 26;
            decrypted_message[decrypted_message_length++] = e + 65;
        } else {
            decrypted_message[decrypted_message_length++] = encrypted_message[i];
        }
    }
    decrypted_message[decrypted_message_length] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter a key to encrypt the message: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = '\0';

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}