//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 16
#define MAX_MESSAGE_SIZE 1000

// Function to generate a random key
void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

// Function to encrypt the message using the key
void encrypt_message(char *message, char *key, char *ciphertext) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            char letter = tolower(message[i]);
            int key_index = letter - 'a';

            if (key_index < 0) {
                key_index += 26;
            }

            if (key_index >= key_length) {
                key_index -= key_length;
            }

            ciphertext[i] = toupper(key[key_index]);
        } else {
            ciphertext[i] = message[i];
        }
    }

    ciphertext[message_length] = '\0';
}

// Function to decrypt the message using the key
void decrypt_message(char *ciphertext, char *key, char *message) {
    int ciphertext_length = strlen(ciphertext);
    int key_length = strlen(key);

    for (int i = 0; i < ciphertext_length; i++) {
        if (isalpha(ciphertext[i])) {
            char letter = toupper(ciphertext[i]);
            int key_index = letter - 'A';

            if (key_index < 0) {
                key_index += 26;
            }

            if (key_index >= key_length) {
                key_index -= key_length;
            }

            message[i] = tolower(key[key_index]);
        } else {
            message[i] = ciphertext[i];
        }
    }

    message[ciphertext_length] = '\0';
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    char ciphertext[MAX_MESSAGE_SIZE];

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    generate_key(key, MAX_KEY_SIZE);

    encrypt_message(message, key, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    decrypt_message(ciphertext, key, message);

    printf("Decrypted message: %s\n", message);

    return 0;
}