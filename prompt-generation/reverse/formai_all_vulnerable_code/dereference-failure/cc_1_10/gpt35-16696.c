//FormAI DATASET v1.0 Category: Encryption ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_LEN 26

/* Function to encrypt the given plaintext using the Caesar Cipher */
char *caesar_encrypt(char *plaintext, int key) {
    int n = strlen(plaintext);
    char *ciphertext = (char*) malloc(n * sizeof(char));
    int i;

    for (i = 0; i < n; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = (plaintext[i] - 'a' + key) % ALPHABET_LEN + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = (plaintext[i] - 'A' + key) % ALPHABET_LEN + 'A';
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    return ciphertext;
}

/* Function to decrypt the given ciphertext using the Caesar Cipher */
char *caesar_decrypt(char *ciphertext, int key) {
    int n = strlen(ciphertext);
    char *plaintext = (char*) malloc(n * sizeof(char));
    int i;

    for (i = 0; i < n; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = (ciphertext[i] - 'a' - key + ALPHABET_LEN) % ALPHABET_LEN + 'a';
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = (ciphertext[i] - 'A' - key + ALPHABET_LEN) % ALPHABET_LEN + 'A';
        } else {
            plaintext[i] = ciphertext[i];
        }
    }

    return plaintext;
}

int main() {
    char plaintext[100], *ciphertext, *decrypted;
    int key;

    printf("Enter the plaintext: ");
    scanf("%[^\n]%*c", plaintext);

    printf("Enter the key: ");
    scanf("%d", &key);

    ciphertext = caesar_encrypt(plaintext, key);
    printf("Encrypted ciphertext: %s\n", ciphertext);

    decrypted = caesar_decrypt(ciphertext, key);
    printf("Decrypted plaintext: %s\n", decrypted);

    return 0;
}