//Falcon-180B DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_KEYS 26

void generate_key(char *key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }
}

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[j] = (plaintext[i] + key[i % strlen(key)]) % 26 + 'A';
            j++;
        } else {
            ciphertext[j] = plaintext[i];
            j++;
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[j] = (ciphertext[i] - key[i % strlen(key)]) % 26 + 'a';
            j++;
        } else {
            plaintext[j] = ciphertext[i];
            j++;
        }
    }
    plaintext[j] = '\0';
}

int main() {
    char plaintext[100], ciphertext[100], key[NUM_KEYS];
    printf("Enter the plaintext message: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter the encryption key: ");
    fgets(key, sizeof(key), stdin);
    generate_key(key);
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);
    printf("Enter the decryption key: ");
    fgets(key, sizeof(key), stdin);
    generate_key(key);
    decrypt(ciphertext, key, plaintext);
    printf("Decrypted message: %s\n", plaintext);
    return 0;
}