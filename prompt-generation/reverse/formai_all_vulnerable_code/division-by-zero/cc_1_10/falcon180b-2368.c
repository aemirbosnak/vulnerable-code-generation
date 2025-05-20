//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 1000
#define MAX_TEXT_LENGTH 1000000

void encrypt(char *text, char *key);
void decrypt(char *text, char *key);

int main() {
    char text[MAX_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter the text to be encrypted: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    printf("Enter the key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(text, key);

    printf("Encrypted Text: %s\n", text);

    decrypt(text, key);

    printf("Decrypted Text: %s\n", text);

    return 0;
}

void encrypt(char *text, char *key) {
    int i, j, len;
    char ch;

    len = strlen(text);

    for (i = 0, j = 0; i < len; i++) {
        ch = tolower(text[i]);

        if (isalpha(ch)) {
            if (isalpha(key[j])) {
                text[i] = (ch + key[j] - 'a') % 26 + 'a';
            } else {
                text[i] = (ch + 'a' - key[j]) % 26 + 'a';
            }
        } else {
            text[i] = ch;
        }

        j = (j + 1) % strlen(key);
    }
}

void decrypt(char *text, char *key) {
    int i, j, len;
    char ch;

    len = strlen(text);

    for (i = 0, j = 0; i < len; i++) {
        ch = tolower(text[i]);

        if (isalpha(ch)) {
            if (isalpha(key[j])) {
                text[i] = (ch - key[j] + 26) % 26 + 'a';
            } else {
                text[i] = (ch - 'a' + key[j]) % 26 + 'a';
            }
        } else {
            text[i] = ch;
        }

        j = (j + 1) % strlen(key);
    }
}