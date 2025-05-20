//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_length] = '\0';
}

void encrypt_message(char *message, char *key, int key_length, char *encrypted_message) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = 'A' + ((message[i] - 'A' + key[i % key_length] - 'A') % 26);
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[strlen(message)] = '\0';
}

void decrypt_message(char *encrypted_message, char *key, int key_length, char *decrypted_message) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = 'A' + ((encrypted_message[i] - 'A' - key[i % key_length] + 26) % 26);
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter a key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    generate_key(key, strlen(key));

    encrypt_message(message, key, strlen(key), encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt_message(encrypted_message, key, strlen(key), decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}