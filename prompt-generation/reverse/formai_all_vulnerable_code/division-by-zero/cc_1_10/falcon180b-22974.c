//Falcon-180B DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1000
#define ALPHABET_LENGTH 26

void generate_key(char key[], int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = 'a' + (rand() % ALPHABET_LENGTH);
    }
}

void encrypt(char message[], char key[], char encrypted_message[]) {
    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = (message[i] + key[i % strlen(key)]) % ALPHABET_LENGTH + 'a';
    }
    encrypted_message[strlen(message)] = '\0';
}

void decrypt(char encrypted_message[], char key[], char decrypted_message[]) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = ((encrypted_message[i] - key[i % strlen(key)]) % ALPHABET_LENGTH + 26) % ALPHABET_LENGTH + 'a';
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter a key to encrypt the message with: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    printf("Enter the encrypted message to decrypt: ");
    fgets(encrypted_message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter the key used to encrypt the message: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}