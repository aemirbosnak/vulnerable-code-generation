//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16
#define MAX_MESSAGE_SIZE 1024

void encrypt_message(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;

    if (key_length > MAX_KEY_SIZE) {
        printf("Error: Key is too long.\n");
        exit(1);
    }

    for (i = 0; i < message_length; i++) {
        char ch = message[i];
        if (isalpha(ch)) {
            ch = (ch + key[i % key_length]) % 26;
            if (isupper(ch)) {
                ch += 'A';
            } else {
                ch += 'a';
            }
        }
        message[i] = ch;
    }
}

void decrypt_message(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;

    if (key_length > MAX_KEY_SIZE) {
        printf("Error: Key is too long.\n");
        exit(1);
    }

    for (i = 0; i < message_length; i++) {
        char ch = message[i];
        if (isalpha(ch)) {
            ch = (ch - key[i % key_length] + 26) % 26;
            if (isupper(ch)) {
                ch -= 'A';
            } else {
                ch -= 'a';
            }
        }
        message[i] = ch;
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    int message_length, key_length;

    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    message_length = strlen(message);

    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_SIZE, stdin);
    key_length = strlen(key);

    encrypt_message(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt_message(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}