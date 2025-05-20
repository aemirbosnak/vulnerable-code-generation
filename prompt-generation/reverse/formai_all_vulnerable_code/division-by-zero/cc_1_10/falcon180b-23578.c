//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1024
#define MAX_CIPHER_SIZE (MAX_MESSAGE_SIZE + 1)

void generate_key(char *key) {
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_SIZE] = '\0';
}

void encrypt(char *key, char *message, char *cipher) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int j = 0;

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            int index = tolower(message[i]) - 'a';
            int shift = tolower(key[j % key_length]) - 'a';

            cipher[i] = (index + shift) % 26 + 'a';

            j++;
        } else {
            cipher[i] = message[i];
        }
    }

    cipher[message_length] = '\0';
}

void decrypt(char *key, char *cipher, char *message) {
    int cipher_length = strlen(cipher);
    int key_length = strlen(key);
    int j = 0;

    for (int i = 0; i < cipher_length; i++) {
        if (isalpha(cipher[i])) {
            int index = tolower(cipher[i]) - 'a';
            int shift = tolower(key[j % key_length]) - 'a';

            message[i] = (index - shift + 26) % 26 + 'a';

            j++;
        } else {
            message[i] = cipher[i];
        }
    }

    message[cipher_length] = '\0';
}

int main() {
    char key[MAX_KEY_SIZE];
    char message[MAX_MESSAGE_SIZE];
    char cipher[MAX_CIPHER_SIZE];

    generate_key(key);

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    encrypt(key, message, cipher);

    printf("Encrypted message: %s\n", cipher);

    printf("Enter the encrypted message to decrypt: ");
    fgets(cipher, MAX_CIPHER_SIZE, stdin);

    decrypt(key, cipher, message);

    printf("Decrypted message: %s\n", message);

    return 0;
}