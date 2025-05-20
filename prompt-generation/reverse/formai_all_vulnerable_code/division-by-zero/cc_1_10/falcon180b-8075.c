//Falcon-180B DATASET v1.0 Category: Encryption ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_length] = '\0';
}

void encrypt_message(char *message, char *key, char *encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int encrypted_message_length = message_length + 1;
    encrypted_message[encrypted_message_length - 1] = '\0';

    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = toupper(c);
            int k = (int)key[i % key_length] - 65;
            c = (char)((c - 65 + k) % 26 + 65);
        }
        encrypted_message[i] = c;
    }
}

void decrypt_message(char *encrypted_message, char *key, char *decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int decrypted_message_length = encrypted_message_length + 1;
    decrypted_message[decrypted_message_length - 1] = '\0';

    for (int i = 0; i < encrypted_message_length; i++) {
        char c = encrypted_message[i];
        if (isalpha(c)) {
            c = toupper(c);
            int k = (int)key[i % key_length] - 65;
            c = (char)((c - 65 - k + 26) % 26 + 65);
        }
        decrypted_message[i] = c;
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter a key to encrypt the message: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    generate_key(key, strlen(key));

    encrypt_message(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt_message(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}