//Falcon-180B DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 1024

void generate_random_key(char* key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

void encrypt_message(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[MAX_MESSAGE_LENGTH];

    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] + key[i % key_length];
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt_message(char* encrypted_message, char* key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    char decrypted_message[MAX_MESSAGE_LENGTH];

    for (int i = 0; i < encrypted_message_length; i++) {
        decrypted_message[i] = encrypted_message[i] - key[i % key_length];
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    generate_random_key(key, MAX_KEY_LENGTH);

    encrypt_message(message, key);
    decrypt_message(message, key);

    return 0;
}