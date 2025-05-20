//Falcon-180B DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char* encrypted_message = malloc(message_length + 1);
    int i, j;

    for (i = 0, j = 0; i < message_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }

        if (isalpha(message[i])) {
            encrypted_message[i] = (tolower(message[i]) + key[j] - 97) % 26 + 97;
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
    char* decrypted_message = malloc(encrypted_message_length + 1);
    int i, j;

    for (i = 0, j = 0; i < encrypted_message_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }

        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = (encrypted_message[i] - key[j] - 97 + 26) % 26 + 97;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    decrypted_message[encrypted_message_length] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char* message = "Hello, world!";
    char* key = "secretkey";

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}