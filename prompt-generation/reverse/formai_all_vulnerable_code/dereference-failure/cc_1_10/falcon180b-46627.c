//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "Cyberpunk2020"

void encrypt(char* message, int length) {
    int i = 0, j = 0, n = 0;
    char buffer[1024];

    while (i < length) {
        if (isalpha(message[i])) {
            buffer[j++] = toupper(message[i++]);
        } else {
            buffer[j++] = message[i++];
        }

        if (j == 1024) {
            for (n = 0; n < j; n++) {
                message[i++] = buffer[n];
            }
            j = 0;
        }
    }

    for (i = 0; i < length; i++) {
        message[i] = message[i] ^ KEY[i % strlen(KEY)];
    }
}

void decrypt(char* message, int length) {
    int i = 0, j = 0, n = 0;
    char buffer[1024];

    while (i < length) {
        if (isalpha(message[i])) {
            buffer[j++] = message[i++];
        } else {
            buffer[j++] = tolower(message[i++]);
        }

        if (j == 1024) {
            for (n = 0; n < j; n++) {
                message[i++] = buffer[n];
            }
            j = 0;
        }
    }

    for (i = 0; i < length; i++) {
        message[i] = message[i] ^ KEY[i % strlen(KEY)];
    }
}

void main() {
    char* message = "Hello, world!";
    int length = strlen(message);

    encrypt(message, length);
    printf("Encrypted message: %s\n", message);

    decrypt(message, length);
    printf("Decrypted message: %s\n", message);
}