//Falcon-180B DATASET v1.0 Category: Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;

    for (i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
        }
    }

    for (i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            int letter_index = tolower(message[i]) - 'a';
            int key_index = tolower(key[i % key_length]) - 'a';

            message[i] = (char) (((letter_index - key_index + 26) % 26) + 'a');
        }
    }
}

void decrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;

    for (i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
        }
    }

    for (i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            int letter_index = tolower(message[i]) - 'a';
            int key_index = tolower(key[i % key_length]) - 'a';

            message[i] = (char) (((letter_index - key_index - 26 + 26) % 26) + 'a');
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter a key to encrypt the message: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    printf("Enter the encrypted message to decrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter the key used to encrypt the message: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}