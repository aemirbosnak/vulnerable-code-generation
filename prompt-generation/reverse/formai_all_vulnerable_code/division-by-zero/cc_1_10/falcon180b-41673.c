//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 1024
#define MAX_TEXT_LENGTH 10240

void encrypt(char *key, char *text);
void decrypt(char *key, char *text);

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];

    printf("Enter the key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    printf("Enter the text to encrypt: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    encrypt(key, text);

    printf("Encrypted text: %s\n", text);

    printf("Enter the encrypted text to decrypt: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    decrypt(key, text);

    printf("Decrypted text: %s\n", text);

    return 0;
}

void encrypt(char *key, char *text) {
    int i, j, k;
    int key_length = strlen(key);

    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            text[i] = toupper(text[i]);
            j = (j + key[i % key_length] - 65) % 26 + 65;
            text[i] = j;
        } else {
            text[i] = text[i];
        }
    }
}

void decrypt(char *key, char *text) {
    int i, j, k;
    int key_length = strlen(key);

    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            text[i] = toupper(text[i]);
            j = (j - key[i % key_length] - 65 + 26) % 26 + 65;
            text[i] = j;
        } else {
            text[i] = text[i];
        }
    }
}