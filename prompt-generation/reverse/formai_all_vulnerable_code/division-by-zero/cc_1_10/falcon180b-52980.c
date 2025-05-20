//Falcon-180B DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char *key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        char c = rand() % 26 + 'a';
        key[i] = c;
    }
    key[length] = '\0';
}

void encrypt(char *message, char *key, int key_length, char *encrypted_message) {
    for (int i = 0; i < strlen(message); i++) {
        char c = tolower(message[i]);
        int k = (int) key[i % key_length];
        if (c >= 'a' && c <= 'z') {
            encrypted_message[i] = (char) (((int) c - 97 + k) % 26 + 97);
        } else {
            encrypted_message[i] = c;
        }
    }
    encrypted_message[strlen(message)] = '\0';
}

void decrypt(char *encrypted_message, char *key, int key_length, char *decrypted_message) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        char c = tolower(encrypted_message[i]);
        int k = (int) key[i % key_length];
        if (c >= 'a' && c <= 'z') {
            decrypted_message[i] = (char) (((int) c - 97 - k + 26) % 26 + 97);
        } else {
            decrypted_message[i] = c;
        }
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

    printf("Enter a key to encrypt with: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    generate_key(key, strlen(key));

    encrypt(message, key, strlen(key), encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, strlen(key), decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}