//Falcon-180B DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 1000

void encrypt(char* text, char* key, char* result) {
    int i, j, n, m;
    char temp[MAX_TEXT_LENGTH];

    n = strlen(text);
    m = strlen(key);

    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(text[i])) {
            temp[j++] = toupper(text[i]) + key[i % m] - 'A' - 1;
        } else {
            temp[j++] = text[i];
        }
    }

    strcpy(result, temp);
}

void decrypt(char* text, char* key, char* result) {
    int i, j, n, m;
    char temp[MAX_TEXT_LENGTH];

    n = strlen(text);
    m = strlen(key);

    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(text[i])) {
            temp[j++] = (text[i] - key[i % m] + 'A' - 1) % 26 + 'a';
        } else {
            temp[j++] = text[i];
        }
    }

    strcpy(result, temp);
}

int main() {
    char text[MAX_TEXT_LENGTH], key[MAX_KEY_LENGTH], result[MAX_TEXT_LENGTH];

    printf("Enter the text to encrypt/decrypt: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    printf("Enter the key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(text, key, result);
    printf("Encrypted text: %s\n", result);

    decrypt(result, key, result);
    printf("Decrypted text: %s\n", result);

    return 0;
}