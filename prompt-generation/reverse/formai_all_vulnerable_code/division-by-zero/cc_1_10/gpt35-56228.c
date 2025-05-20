//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define ALPHABET_SIZE 26
#define KEY_SIZE 256

void encrypt(char *message, char *key, char *encrypted_message) {
    int message_len = strlen(message);
    int key_len = strlen(key);

    for (int i = 0; i < message_len; i++) {
        char letter = message[i];
        if (isalpha(letter)) {
            int shift = tolower(key[i % key_len]) - 'a';
            if (isupper(letter)) {
                letter = 'A' + (letter - 'A' + shift) % ALPHABET_SIZE;
            } else {
                letter = 'a' + (letter - 'a' + shift) % ALPHABET_SIZE;
            }
        }
        encrypted_message[i] = letter;
    }
    encrypted_message[message_len] = '\0';
}

void decrypt(char *encrypted_message, char *key, char *message) {
    int encrypted_message_len = strlen(encrypted_message);
    int key_len = strlen(key);

    for (int i = 0; i < encrypted_message_len; i++) {
        char letter = encrypted_message[i];
        if (isalpha(letter)) {
            int shift = tolower(key[i % key_len]) - 'a';
            if (isupper(letter)) {
                letter = 'A' + (letter - 'A' - shift + ALPHABET_SIZE) % ALPHABET_SIZE;
            } else {
                letter = 'a' + (letter - 'a' - shift + ALPHABET_SIZE) % ALPHABET_SIZE;
            }
        }
        message[i] = letter;
    }
    message[encrypted_message_len] = '\0';
}

int main() {
    char message[KEY_SIZE];
    char key[KEY_SIZE];
    char encrypted_message[KEY_SIZE];
    char decrypted_message[KEY_SIZE];

    printf("Enter the message to encrypt: ");
    fgets(message, KEY_SIZE, stdin);
    printf("Enter the encryption key: ");
    fgets(key, KEY_SIZE, stdin);

    // Remove trailing newline characters
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    encrypt(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}