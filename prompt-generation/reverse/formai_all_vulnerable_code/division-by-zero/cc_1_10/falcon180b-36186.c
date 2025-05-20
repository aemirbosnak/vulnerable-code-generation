//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 100
#define MAX_ENCRYPTED_LENGTH (MAX_TEXT_LENGTH + 1)

void encrypt(char* text, char* key, char* encrypted) {
    int i, j;
    for (i = 0, j = 0; i < strlen(text); i++) {
        encrypted[j++] = (text[i] + key[i % strlen(key)]) % 26 + 'a';
    }
    encrypted[j] = '\0';
}

void decrypt(char* encrypted, char* key, char* text) {
    int i, j;
    for (i = 0, j = 0; i < strlen(encrypted); i++) {
        text[j++] = (encrypted[i] - key[i % strlen(key)]) % 26 + 'a';
    }
    text[j] = '\0';
}

void generate_key(char* key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        key[i] = 'a' + rand() % 26;
    }
    key[length] = '\0';
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted[MAX_ENCRYPTED_LENGTH];

    printf("Enter text to encrypt: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    generate_key(key, strlen(key));

    printf("Encrypted text: %s\n", text);
    encrypt(text, key, encrypted);
    printf("Encrypted text: %s\n", encrypted);

    printf("Decrypted text: ");
    decrypt(encrypted, key, text);
    printf("%s\n", text);

    return 0;
}