//Falcon-180B DATASET v1.0 Category: Encryption ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char* key, int length) {
    const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        key[i] = alphanum[rand() % strlen(alphanum)];
    }
    key[length] = '\0';
}

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[message_length + 1];

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (message[i] + key[i % key_length] - 'A' + 26) % 26 + 'A';
        } else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[message_length] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* encrypted_message, char* key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    char decrypted_message[encrypted_message_length + 1];

    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = (encrypted_message[i] - key[i % key_length] - 'A' + 26) % 26 + 'A';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    decrypted_message[encrypted_message_length] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter a key to encrypt and decrypt the message: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    generate_key(key, strlen(key));

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}