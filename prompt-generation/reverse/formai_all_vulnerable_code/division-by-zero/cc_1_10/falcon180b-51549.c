//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 100

void generate_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_length] = '\0';
}

void encrypt_message(char *message, char *key, char *encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] ^ key[i % key_length];
    }
    encrypted_message[message_length] = '\0';
}

void decrypt_message(char *encrypted_message, char *key, char *decrypted_message) {
    int message_length = strlen(encrypted_message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % key_length];
    }
    decrypted_message[message_length] = '\0';
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    generate_key(key, strlen(key));

    printf("Encrypted message: ");
    encrypt_message(message, key, encrypted_message);
    printf("%s\n", encrypted_message);

    printf("Enter the encrypted message to decrypt: ");
    fgets(encrypted_message, MAX_MESSAGE_LENGTH, stdin);

    printf("Decrypted message: ");
    decrypt_message(encrypted_message, key, decrypted_message);
    printf("%s\n", decrypted_message);

    return 0;
}