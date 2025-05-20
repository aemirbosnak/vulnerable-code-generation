//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

void encrypt(char* message, char* key) {
    int i, j;
    char* result = malloc(strlen(message) + 1);

    for (i = 0; message[i]!= '\0'; i++) {
        char c = message[i];

        if (isalpha(c)) {
            c = (c - 'A' + key[0] - 1) % SIZE + 'A';
        } else if (isdigit(c)) {
            c = (c - '0' + key[0] - 1) % 10 + '0';
        }

        result[i] = c;
    }

    printf("Encrypted message: %s\n", result);
}

void decrypt(char* message, char* key) {
    int i, j;
    char* result = malloc(strlen(message) + 1);

    for (i = 0; message[i]!= '\0'; i++) {
        char c = message[i];

        if (isalpha(c)) {
            c = (c - 'A' + key[0] - 1) % SIZE + 'A';
        } else if (isdigit(c)) {
            c = (c - '0' + key[0] - 1) % 10 + '0';
        }

        result[i] = c;
    }

    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[] = "Hello, World!";
    char key[] = "Alan Turing";

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}