//Falcon-180B DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char *key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[length] = '\0';
}

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    char encrypted_message[message_length + 1];
    encrypted_message[message_length] = '\0';

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            char letter = toupper(message[i]);
            int key_index = letter - 'A' + (int)key[i % strlen(key)];

            if (key_index > 25) {
                key_index -= 26;
            }

            encrypted_message[i] = key_index + 'A';
        } else {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int message_length = strlen(encrypted_message);
    char decrypted_message[message_length + 1];
    decrypted_message[message_length] = '\0';

    for (int i = 0; i < message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            char letter = encrypted_message[i];
            int key_index = letter - 'A' - (int)key[i % strlen(key)];

            if (key_index < 0) {
                key_index += 26;
            }

            decrypted_message[i] = key_index + 'A';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter a key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    generate_key(key, strlen(key));

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}