//Falcon-180B DATASET v1.0 Category: Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define KEY_LENGTH 16

void generate_key(char* key) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LENGTH] = '\0';
}

void encrypt(char* message, char* key) {
    int i, j;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 'a' + (key[i % KEY_LENGTH] - 'a')) % 26 + 'a';
        }
    }
}

void decrypt(char* message, char* key) {
    int i, j;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 'a' - (key[i % KEY_LENGTH] - 'a') + 26) % 26 + 'a';
        }
    }
}

int main() {
    char message[MAX_LENGTH];
    char key[KEY_LENGTH];

    printf("Enter message to encrypt/decrypt: ");
    fgets(message, MAX_LENGTH, stdin);

    generate_key(key);

    printf("Encrypted message: ");
    encrypt(message, key);
    printf("%s\n", message);

    printf("Decrypted message: ");
    decrypt(message, key);
    printf("%s\n", message);

    return 0;
}