//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LEN 16

void encrypt(char *message, char *key) {
    int len = strlen(message);
    char *result = malloc(len + 1);
    int key_index = 0;

    for (int i = 0; i < len; i++) {
        char c = tolower(message[i]);
        char k = key[key_index % KEY_LEN];

        if (isalpha(c)) {
            if (isupper(c)) {
                c = c + 'a' - 'A';
            }

            c = (c + k - 'a') % 26 + 'a';
        }

        result[i] = c;
        key_index++;
    }

    result[len] = '\0';
    printf("Encrypted message: %s\n", result);
}

void decrypt(char *message, char *key) {
    int len = strlen(message);
    char *result = malloc(len + 1);
    int key_index = 0;

    for (int i = 0; i < len; i++) {
        char c = message[i];
        char k = key[key_index % KEY_LEN];

        if (isalpha(c)) {
            if (isupper(c)) {
                c = c + 'A' - 'a';
            }

            c = (c - k + 26) % 26 + 'a';
        }

        result[i] = c;
        key_index++;
    }

    result[len] = '\0';
    printf("Decrypted message: %s\n", result);
}

int main() {
    char *message = "Hello, world! ";
    char *key = "secretkey123456789";

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}