//Falcon-180B DATASET v1.0 Category: Encryption ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_PLAINTEXT_LENGTH 200
#define MAX_CIPHERTEXT_LENGTH (MAX_PLAINTEXT_LENGTH + 1)
#define ALPHABET_LENGTH 26
#define RANDOM_KEY_LENGTH 26

void generate_random_key(char *key) {
    for (int i = 0; i < RANDOM_KEY_LENGTH; i++) {
        key[i] = 'A' + rand() % ALPHABET_LENGTH;
    }
    key[RANDOM_KEY_LENGTH] = '\0';
}

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j;
    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[j++] = key[(int) plaintext[i] - 65];
        } else {
            ciphertext[j++] = plaintext[i];
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j;
    for (i = 0, j = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[j++] = (char) (key[ciphertext[i] - 65] + 65);
        } else {
            plaintext[j++] = ciphertext[i];
        }
    }
    plaintext[j] = '\0';
}

int main() {
    char plaintext[MAX_PLAINTEXT_LENGTH + 1];
    char ciphertext[MAX_CIPHERTEXT_LENGTH + 1];
    char key[MAX_KEY_LENGTH + 1];

    printf("Enter the plaintext to encrypt (maximum 200 characters): ");
    fgets(plaintext, MAX_PLAINTEXT_LENGTH, stdin);

    generate_random_key(key);

    printf("Random key generated: %s\n", key);

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    printf("Enter the key to decrypt: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}