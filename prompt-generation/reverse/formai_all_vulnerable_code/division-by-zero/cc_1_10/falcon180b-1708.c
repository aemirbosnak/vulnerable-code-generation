//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_STRING_SIZE 1024

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char *message, char *key, int key_size, char *cipher_text) {
    int message_size = strlen(message);
    int key_index = 0;
    int cipher_index = 0;

    for (int i = 0; i < message_size; i++) {
        char c = toupper(message[i]);
        int ascii_value = (int)c;

        if (isalpha(c)) {
            cipher_text[cipher_index++] = (char)((ascii_value + key[key_index]) % 26 + 65);
        } else {
            cipher_text[cipher_index++] = c;
        }

        key_index = (key_index + 1) % key_size;
    }
}

void decrypt(char *cipher_text, char *key, int key_size, char *message) {
    int cipher_size = strlen(cipher_text);
    int key_index = 0;
    int message_index = 0;

    for (int i = 0; i < cipher_size; i++) {
        char c = cipher_text[i];
        int ascii_value = (int)c;

        if (isalpha(c)) {
            char decrypted_c = (char)((ascii_value - key[key_index] + 26) % 26 + 65);
            message[message_index++] = decrypted_c;
        } else {
            message[message_index++] = c;
        }

        key_index = (key_index + 1) % key_size;
    }
}

int main() {
    char message[MAX_STRING_SIZE];
    char key[MAX_KEY_SIZE];
    char cipher_text[MAX_STRING_SIZE];

    printf("Enter a message: ");
    fgets(message, MAX_STRING_SIZE, stdin);

    printf("Enter a key (up to %d characters): ", MAX_KEY_SIZE - 1);
    fgets(key, MAX_KEY_SIZE, stdin);

    generate_key(key, strlen(key));

    encrypt(message, key, strlen(key), cipher_text);

    printf("Encrypted message: %s\n", cipher_text);

    decrypt(cipher_text, key, strlen(key), message);

    printf("Decrypted message: %s\n", message);

    return 0;
}