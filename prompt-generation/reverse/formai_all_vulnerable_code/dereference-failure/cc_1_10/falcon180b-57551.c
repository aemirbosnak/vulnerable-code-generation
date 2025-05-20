//Falcon-180B DATASET v1.0 Category: Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define KEY_CHARACTER_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789! @#$%^&*()_-+=[]{}|;:,.<>?/~`"

void generate_key(char* key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = KEY_CHARACTER_SET[rand() % strlen(KEY_CHARACTER_SET)];
    }
    key[key_length] = '\0';
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int plaintext_length = strlen(plaintext);
    int key_length = strlen(key);
    int ciphertext_length = plaintext_length + key_length;

    for (int i = 0; i < plaintext_length; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_length];
    }

    for (int i = plaintext_length; i < ciphertext_length; i++) {
        ciphertext[i] = key[i - plaintext_length % key_length];
    }

    ciphertext[ciphertext_length - 1] = '\0';
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int ciphertext_length = strlen(ciphertext);
    int key_length = strlen(key);
    int plaintext_length = ciphertext_length - key_length;

    for (int i = 0; i < plaintext_length; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_length];
    }

    for (int i = plaintext_length; i < ciphertext_length; i++) {
        plaintext[i] = key[i - plaintext_length % key_length];
    }

    plaintext[plaintext_length - 1] = '\0';
}

int main() {
    char plaintext[1000];
    char key[MAX_KEY_LENGTH];
    char ciphertext[1000];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key: ");
    generate_key(key, strlen(plaintext));

    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}