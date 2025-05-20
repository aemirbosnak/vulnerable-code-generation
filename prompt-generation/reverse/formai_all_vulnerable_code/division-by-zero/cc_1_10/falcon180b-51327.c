//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

void encrypt(char *message, char *key, char *result) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    for (int i = 0; i < message_length; i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            c = (c - 'A' + key_length - 1) % key_length + 'A';
        }
        result[i] = c;
    }
    result[message_length] = '\0';
}

void decrypt(char *ciphertext, char *key, char *result) {
    int ciphertext_length = strlen(ciphertext);
    int key_length = strlen(key);
    int message_length = ciphertext_length;
    for (int i = 0; i < ciphertext_length; i++) {
        char c = toupper(ciphertext[i]);
        if (isalpha(c)) {
            c = (c - 'A' + key_length - 1) % key_length + 'A';
        }
        result[i] = c;
    }
    result[message_length] = '\0';
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char ciphertext[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter a key to encrypt the message: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = '\0';

    encrypt(message, key, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    decrypt(ciphertext, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}