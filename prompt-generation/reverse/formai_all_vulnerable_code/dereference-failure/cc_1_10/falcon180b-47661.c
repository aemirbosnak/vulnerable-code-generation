//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define KEY_LENGTH 16

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LENGTH] = '\0';
}

void encrypt(char *message, char *key, char *ciphertext) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                ciphertext[j++] = (key[i % KEY_LENGTH] + message[i] - 'A' - 1) % 26 + 'A';
            } else {
                ciphertext[j++] = (key[i % KEY_LENGTH] + message[i] - 'a' - 1) % 26 + 'a';
            }
        } else {
            ciphertext[j++] = message[i];
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char *ciphertext, char *key, char *message) {
    int i, j;
    for (i = 0, j = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                message[j++] = (ciphertext[i] - key[i % KEY_LENGTH] + 26) % 26 + 'A';
            } else {
                message[j++] = (ciphertext[i] - key[i % KEY_LENGTH] + 26) % 26 + 'a';
            }
        } else {
            message[j++] = ciphertext[i];
        }
    }
    message[j] = '\0';
}

int main() {
    char message[MAX_LENGTH];
    char key[KEY_LENGTH];
    char ciphertext[MAX_LENGTH];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    generate_key(key);

    encrypt(message, key, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    decrypt(ciphertext, key, message);

    printf("Decrypted message: %s\n", message);

    return 0;
}