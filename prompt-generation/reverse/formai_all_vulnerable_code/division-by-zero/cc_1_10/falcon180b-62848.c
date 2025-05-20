//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void encrypt(char* message, char* key) {
    int i, j, key_length = strlen(key);
    char encrypted[MAX_LENGTH];

    for (i = 0; message[i]!= '\0'; i++) {
        encrypted[i] = message[i];
    }

    for (i = 0; i < strlen(encrypted); i++) {
        encrypted[i] = toupper(encrypted[i]) + key[i % key_length];
    }

    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char* message, char* key) {
    int i, j, key_length = strlen(key);
    char decrypted[MAX_LENGTH];

    for (i = 0; message[i]!= '\0'; i++) {
        decrypted[i] = message[i];
    }

    for (i = 0; i < strlen(decrypted); i++) {
        decrypted[i] = decrypted[i] - key[i % key_length];
    }

    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[MAX_LENGTH], key[MAX_LENGTH];

    printf("Enter message: ");
    fgets(message, MAX_LENGTH, stdin);

    printf("Enter key: ");
    fgets(key, MAX_LENGTH, stdin);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}