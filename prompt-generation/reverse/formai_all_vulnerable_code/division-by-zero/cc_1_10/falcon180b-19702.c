//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 1000
#define MAX_TEXT_LENGTH 1000000

void generate_key(char key[], int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt(char text[], char key[]) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = (text[i] - 'A' + (int) key[i % strlen(key)]) % 26 + 'A';
            } else {
                text[i] = (text[i] - 'a' + (int) key[i % strlen(key)]) % 26 + 'a';
            }
        }
    }
}

void decrypt(char text[], char key[]) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = (text[i] - (int) key[i % strlen(key)] + 26) % 26 + 'A';
            } else {
                text[i] = (text[i] - (int) key[i % strlen(key)] + 26) % 26 + 'a';
            }
        }
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter the text to be encrypted: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    printf("Enter the key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(text, key);

    printf("Encrypted text: %s\n", text);

    decrypt(text, key);

    printf("Decrypted text: %s\n", text);

    return 0;
}