//Falcon-180B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_MESSAGE_SIZE 1024

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char* message, char* key, int key_size) {
    for (int i = 0; i < strlen(message); i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            int index = tolower(key[i % key_size]) - 'a';
            if (index >= 0 && index < 26) {
                c = (c - 'a' + index + 26) % 26 + 'a';
            }
        }
        message[i] = c;
    }
}

void decrypt(char* message, char* key, int key_size) {
    for (int i = 0; i < strlen(message); i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            int index = tolower(key[i % key_size]) - 'a';
            if (index >= 0 && index < 26) {
                c = (c - 'a' - index + 26) % 26 + 'a';
            }
        }
        message[i] = c;
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    printf("Enter a key to encrypt the message: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    int key_size = strlen(key);
    if (key_size > MAX_KEY_SIZE) {
        printf("Key is too long!\n");
        return 1;
    }

    generate_key(key, key_size);

    encrypt(message, key, key_size);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key, key_size);

    printf("Decrypted message: %s\n", message);

    return 0;
}