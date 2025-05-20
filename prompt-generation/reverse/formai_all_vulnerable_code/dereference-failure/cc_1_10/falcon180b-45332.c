//Falcon-180B DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 1024
#define MAX_TEXT_SIZE 1000000

char* generate_key(int key_size) {
    char* key = (char*) malloc(key_size + 1);
    if (!key) {
        printf("Error: Cannot allocate memory for key.\n");
        exit(1);
    }

    srand(time(0));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 94 + 33;
    }
    key[key_size] = '\0';

    return key;
}

void encrypt(char* text, char* key) {
    int text_size = strlen(text);
    int key_size = strlen(key);

    for (int i = 0; i < text_size; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            ch = (ch - 'a' + (int) key[i % key_size]) % 26 + 'a';
        }
        text[i] = ch;
    }
}

void decrypt(char* text, char* key) {
    int text_size = strlen(text);
    int key_size = strlen(key);

    for (int i = 0; i < text_size; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            ch = (ch - 'a' - (int) key[i % key_size] + 26) % 26 + 'a';
        }
        text[i] = ch;
    }
}

int main() {
    char* text = (char*) malloc(MAX_TEXT_SIZE + 1);
    char* key = generate_key(MAX_KEY_SIZE);
    char* encrypted_text = (char*) malloc(MAX_TEXT_SIZE + 1);
    char* decrypted_text = (char*) malloc(MAX_TEXT_SIZE + 1);

    printf("Enter text to encrypt: ");
    scanf("%s", text);

    encrypt(text, key);
    printf("Encrypted text: %s\n", text);

    strcpy(encrypted_text, text);

    decrypt(encrypted_text, key);
    printf("Decrypted text: %s\n", encrypted_text);

    free(text);
    free(key);
    free(encrypted_text);
    free(decrypted_text);

    return 0;
}