//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, char *key) {
    int i, j;
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    char *ciphertext = malloc(sizeof(char) * (plaintext_len + 1));

    for (i = 0, j = 0; i < plaintext_len; ++i, ++j) {
        if (j >= key_len) j = 0;
        ciphertext[i] = (plaintext[i] + key[j]) % 26 + 'A';
    }

    ciphertext[plaintext_len] = '\0';
    printf("Ciphertext: %s\n", ciphertext);

    free(ciphertext);
}

void decrypt(char *ciphertext, char *key) {
    int i, j;
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);
    char *plaintext = malloc(sizeof(char) * (ciphertext_len + 1));

    for (i = 0, j = 0; i < ciphertext_len; ++i, ++j) {
        if (j >= key_len) j = 0;
        plaintext[i] = (ciphertext[i] - key[j] + 26) % 26 + 'A';
    }

    plaintext[ciphertext_len] = '\0';
    printf("Plaintext: %s\n", plaintext);

    free(plaintext);
}

int main() {
    char plaintext[] = "HELLO";
    char key[] = "SECRET";

    printf("Original message: %s\n", plaintext);

    encrypt(plaintext, key);

    char ciphertext[] = "VSUMI";
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key);

    return 0;
}