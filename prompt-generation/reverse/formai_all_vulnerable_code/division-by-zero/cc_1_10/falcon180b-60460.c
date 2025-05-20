//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void generate_random_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

void encrypt_message(char *message, char *key) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = 'A' + ((int)message[i] - 'A' + (int)key[i % strlen(key)]) % 26;
            } else {
                message[i] = 'a' + ((int)message[i] - 'a' + (int)key[i % strlen(key)]) % 26;
            }
        }
    }
}

void decrypt_message(char *message, char *key) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = 'A' + ((int)message[i] - 'A' - (int)key[i % strlen(key)]) % 26;
            } else {
                message[i] = 'a' + ((int)message[i] - 'a' - (int)key[i % strlen(key)]) % 26;
            }
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("Enter a key to encrypt the message with: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    srand(time(NULL));
    generate_random_key(key, strlen(key));

    encrypt_message(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt_message(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}