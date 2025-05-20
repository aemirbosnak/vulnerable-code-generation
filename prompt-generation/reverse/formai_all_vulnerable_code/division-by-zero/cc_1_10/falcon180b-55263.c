//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: standalone
#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 1000

void generate_key(char *key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt(char *text, char *key) {
    int text_length = strlen(text);
    int key_length = strlen(key);
    char encrypted_text[MAX_TEXT_LENGTH];

    for (int i = 0; i < text_length; i++) {
        if (isalpha(text[i])) {
            encrypted_text[i] = (text[i] + key[i % key_length] - 'a' + 26) % 26 + 'a';
        } else {
            encrypted_text[i] = text[i];
        }
    }

    encrypted_text[text_length] = '\0';

    printf("Encrypted text: %s\n", encrypted_text);
}

void decrypt(char *text, char *key) {
    int text_length = strlen(text);
    int key_length = strlen(key);
    char decrypted_text[MAX_TEXT_LENGTH];

    for (int i = 0; i < text_length; i++) {
        if (isalpha(text[i])) {
            decrypted_text[i] = (text[i] - key[i % key_length] + 'a' - 26 + 26) % 26 + 'a';
        } else {
            decrypted_text[i] = text[i];
        }
    }

    decrypted_text[text_length] = '\0';

    printf("Decrypted text: %s\n", decrypted_text);
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter text to encrypt/decrypt: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    printf("Enter encryption/decryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    generate_key(key, strlen(key));

    printf("Key: %s\n", key);

    encrypt(text, key);
    decrypt(text, key);

    return 0;
}