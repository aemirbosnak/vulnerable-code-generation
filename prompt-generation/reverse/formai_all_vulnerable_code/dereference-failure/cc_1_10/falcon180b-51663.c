//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

void generate_key(char* key) {
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LENGTH] = '\0';
}

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_index = 0;
    char encrypted_message[message_length];

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = message[i] ^ key[key_index];
            key_index = (key_index + 1) % KEY_LENGTH;
        } else {
            encrypted_message[i] = message[i];
        }
    }

    strcpy(message, encrypted_message);
}

void decrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_index = 0;
    char decrypted_message[message_length];

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            decrypted_message[i] = message[i] ^ key[key_index];
            key_index = (key_index + 1) % KEY_LENGTH;
        } else {
            decrypted_message[i] = message[i];
        }
    }

    strcpy(message, decrypted_message);
}

int main() {
    char message[1000];
    char key[KEY_LENGTH + 1];

    printf("Enter message to encrypt/decrypt: ");
    fgets(message, 1000, stdin);

    generate_key(key);

    printf("Encrypted message: ");
    encrypt(message, key);
    printf("%s\n", message);

    printf("Decrypted message: ");
    decrypt(message, key);
    printf("%s\n", message);

    return 0;
}