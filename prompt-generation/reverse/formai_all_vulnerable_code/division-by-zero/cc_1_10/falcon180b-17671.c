//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

void generate_key(char *key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }
}

void encrypt_message(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 65 + (key[j] - 65)) % 26 + 65;
            j = (j + 1) % strlen(key);
        }
    }
}

void decrypt_message(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 65 - (key[j] - 65)) % 26 + 65;
            j = (j + 1) % strlen(key);
        }
    }
}

int main() {
    char key[MAX_KEY_LENGTH + 1];
    char message[MAX_MESSAGE_LENGTH + 1];

    printf("Enter a key: ");
    fgets(key, MAX_KEY_LENGTH + 1, stdin);
    generate_key(key);

    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH + 1, stdin);

    encrypt_message(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt_message(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}