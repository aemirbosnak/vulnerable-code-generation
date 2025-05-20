//Falcon-180B DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 16
#define MAX_TEXT_SIZE 1000

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        char c = rand() % 26 + 'a';
        key[i] = toupper(c);
    }
}

void encrypt(char* text, char* key, char* encrypted_text) {
    int text_size = strlen(text);
    int key_size = strlen(key);

    for (int i = 0; i < text_size; i++) {
        char c = toupper(text[i]);
        int k = (int) key[i % key_size];
        int index = (c - 'A' + k) % 26;
        encrypted_text[i] = index + 'A';
    }
}

void decrypt(char* encrypted_text, char* key, char* decrypted_text) {
    int encrypted_size = strlen(encrypted_text);
    int key_size = strlen(key);

    for (int i = 0; i < encrypted_size; i++) {
        char c = encrypted_text[i];
        int k = (int) key[i % key_size];
        int index = (c - 'A' - k + 26) % 26;
        decrypted_text[i] = index + 'A';
    }
}

int main() {
    char text[MAX_TEXT_SIZE];
    char key[MAX_KEY_SIZE];
    char encrypted_text[MAX_TEXT_SIZE];
    char decrypted_text[MAX_TEXT_SIZE];

    printf("Enter the text to be encrypted: ");
    fgets(text, MAX_TEXT_SIZE, stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the key: ");
    fgets(key, MAX_KEY_SIZE, stdin);
    key[strcspn(key, "\n")] = '\0';

    generate_key(key, strlen(key));

    encrypt(text, key, encrypted_text);

    printf("Encrypted text: %s\n", encrypted_text);

    decrypt(encrypted_text, key, decrypted_text);

    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}