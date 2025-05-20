//Falcon-180B DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 256

// Function prototypes
void generate_key(char *key, int length);
void encrypt(char *plaintext, char *key, char *ciphertext);
void decrypt(char *ciphertext, char *key, char *plaintext);

int main() {
    char plaintext[1000];
    char key[MAX_KEY_LENGTH+1];
    char ciphertext[1000];

    printf("Enter plaintext message: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter encryption key: ");
    fgets(key, sizeof(key), stdin);

    printf("Plaintext message:\n%s\n", plaintext);
    printf("Encryption key:\n%s\n", key);

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext:\n%s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted message:\n%s\n", plaintext);

    return 0;
}

// Function to generate a random encryption key
void generate_key(char *key, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i, j;

    for (i = 0; i < length; i++) {
        j = rand() % sizeof(charset);
        key[i] = charset[j];
    }

    key[length] = '\0';
}

// Function to encrypt plaintext using the key
void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j, k, n;

    n = strlen(plaintext);
    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(plaintext[i])) {
            plaintext[i] = toupper(plaintext[i]);
            ciphertext[j++] = plaintext[i];
        }
    }

    k = 0;
    for (i = 0; i < n; i++) {
        if (isalpha(plaintext[i])) {
            plaintext[i] = toupper(plaintext[i]) ^ key[k];
            ciphertext[j++] = plaintext[i];
        }
        k = (k + 1) % strlen(key);
    }

    ciphertext[j] = '\0';
}

// Function to decrypt ciphertext using the key
void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j, k, n;

    n = strlen(ciphertext);
    for (i = 0, j = 0; i < n; i++) {
        if (isalpha(ciphertext[i])) {
            ciphertext[i] = toupper(ciphertext[i]);
            plaintext[j++] = ciphertext[i];
        }
    }

    k = 0;
    for (i = 0; i < n; i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[i] = toupper(ciphertext[i]) ^ key[k];
            ciphertext[j++] = plaintext[i];
        }
        k = (k + 1) % strlen(key);
    }

    plaintext[j] = '\0';
}