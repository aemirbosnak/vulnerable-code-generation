//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 10
#define MAX_MESSAGE_LENGTH 100

void generate_key(char* key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

void encrypt(char* message, char* key, char* result) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int result_length = message_length + 1;
    result[result_length - 1] = '\0';

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            result[i] = (message[i] - 'a' + key[i % key_length] - 'a') % 26 + 'a';
        } else {
            result[i] = message[i];
        }
    }
}

void decrypt(char* message, char* key, char* result) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int result_length = message_length + 1;
    result[result_length - 1] = '\0';

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            result[i] = (message[i] - 'a' - key[i % key_length] + 26) % 26 + 'a';
        } else {
            result[i] = message[i];
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    generate_key(key, MAX_KEY_LENGTH);

    char encrypted_message[MAX_MESSAGE_LENGTH];
    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    char decrypted_message[MAX_MESSAGE_LENGTH];
    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}