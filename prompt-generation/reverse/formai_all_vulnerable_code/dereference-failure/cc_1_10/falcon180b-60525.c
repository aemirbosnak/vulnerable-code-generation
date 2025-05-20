//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_SIZE 10
#define MAX_PLAINTEXT_SIZE 100
#define MAX_CIPHERTEXT_SIZE (MAX_PLAINTEXT_SIZE + 1)

int generate_key(char *key, int key_size);
void encrypt(char *plaintext, char *key, char *ciphertext);
void decrypt(char *ciphertext, char *key, char *plaintext);

int main() {
    char plaintext[MAX_PLAINTEXT_SIZE] = "This is a secret message.";
    char key[MAX_KEY_SIZE] = "mysecretkey";
    char ciphertext[MAX_CIPHERTEXT_SIZE];

    printf("Plaintext: %s\n", plaintext);

    generate_key(key, strlen(key));

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted message: %s\n", plaintext);

    return 0;
}

int generate_key(char *key, int key_size) {
    if (key_size > MAX_KEY_SIZE) {
        printf("Error: Key size too large.\n");
        return -1;
    }

    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }

    return 0;
}

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; i < plaintext_len; i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[i] = (char) (tolower(plaintext[i]) + (int) key[j] - 97);
            j = (j + 1) % key_len;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[plaintext_len] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; i < ciphertext_len; i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[i] = (char) ((int) ciphertext[i] - (int) key[j] + 97);
            j = (j + 1) % key_len;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }

    plaintext[ciphertext_len] = '\0';
}