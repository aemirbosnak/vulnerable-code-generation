//Falcon-180B DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_MESSAGE_SIZE 1000

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_size] = '\0';
}

void encrypt(char *message, char *key) {
    int message_size = strlen(message);
    int key_size = strlen(key);

    for (int i = 0; i < message_size; i++) {
        if (isalpha(message[i])) {
            char base = isupper(message[i])? 'A' : 'a';
            message[i] = key[(int)message[i] - base + (int)key[0] - base] % 26 + base;
        }
    }
}

void decrypt(char *message, char *key) {
    int message_size = strlen(message);
    int key_size = strlen(key);

    for (int i = 0; i < message_size; i++) {
        if (isalpha(message[i])) {
            char base = isupper(message[i])? 'A' : 'a';
            message[i] = (char)((int)message[i] - (int)key[0] + 26) % 26 + base;
        }
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE], key[MAX_KEY_SIZE];

    generate_key(key, rand() % MAX_KEY_SIZE + 1);

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    printf("Enter the key used for encryption: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}