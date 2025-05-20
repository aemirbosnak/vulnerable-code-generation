//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 1024

void generate_key(char* key, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charset_length = strlen(charset);

    for (int i = 0; i < length; i++) {
        key[i] = charset[rand() % charset_length];
    }
}

void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        char message_char = tolower(message[i]);
        char key_char = key[i % key_length];
        int message_index = message_char - 'a';
        int key_index = tolower(key_char) - 'a';

        encrypted_message[i] = (char)((message_index + key_index) % 26 + 'a');
    }
}

void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);

    for (int i = 0; i < encrypted_message_length; i++) {
        char encrypted_message_char = encrypted_message[i];
        char key_char = key[i % key_length];
        int encrypted_message_index = encrypted_message_char - 'a';
        int key_index = tolower(key_char) - 'a';

        decrypted_message[i] = (char)((encrypted_message_index - key_index + 26) % 26 + 'a');
    }
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    generate_key(key, strlen(key));

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}