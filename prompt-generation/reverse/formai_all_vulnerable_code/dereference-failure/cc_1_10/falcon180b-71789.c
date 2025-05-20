//Falcon-180B DATASET v1.0 Category: Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 32
#define MAX_TEXT_SIZE 1024

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(char *text, char *key) {
    int text_len = strlen(text);
    int key_len = strlen(key);

    for (int i = 0; i < text_len; i++) {
        if (isalpha(text[i])) {
            text[i] = (text[i] - 'a' + key[i % key_len] - 'a') % 26 + 'a';
        }
    }
}

void decrypt(char *text, char *key) {
    int text_len = strlen(text);
    int key_len = strlen(key);

    for (int i = 0; i < text_len; i++) {
        if (isalpha(text[i])) {
            text[i] = (text[i] - 'a' + 'a' - key[i % key_len]) % 26 + 'a';
        }
    }
}

int main() {
    char text[MAX_TEXT_SIZE] = "Hello, world!";
    char key[MAX_KEY_SIZE] = "";

    generate_key(key, MAX_KEY_SIZE);

    printf("Plain text: %s\n", text);
    encrypt(text, key);
    printf("Encrypted text: %s\n", text);
    decrypt(text, key);
    printf("Decrypted text: %s\n", text);

    return 0;
}