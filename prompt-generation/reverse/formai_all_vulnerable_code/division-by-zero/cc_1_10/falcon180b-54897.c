//Falcon-180B DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 10
#define MAX_TEXT_LENGTH 1000

char encrypt(char c, char key) {
    if (isalpha(c)) {
        if (isupper(c)) {
            return (((c - 'A') + key) % 26) + 'A';
        } else {
            return (((c - 'a') + key) % 26) + 'a';
        }
    } else {
        return c;
    }
}

void encrypt_text(char *text, char *key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            text[j++] = encrypt(text[i], key[i % strlen(key)]);
        } else {
            text[j++] = text[i];
        }
    }
    text[j] = '\0';
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];
    int text_length, key_length;

    printf("Enter the text to be encrypted: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    text_length = strlen(text);

    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key_length = strlen(key);

    if (key_length > text_length) {
        printf("Error: Key is too long.\n");
        return 1;
    }

    encrypt_text(text, key);

    printf("Encrypted text: %s\n", text);

    return 0;
}