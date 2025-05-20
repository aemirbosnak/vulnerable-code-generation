//FormAI DATASET v1.0 Category: Modern Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LEN 16

void encrypt(char *plaintext, char *key, char *ciphertext);
void decrypt(char *ciphertext, char *key, char *plaintext);

int main(void) {
    char plaintext[128];
    char key[KEY_LEN+1];
    char ciphertext[128];
    char decrypted_plaintext[128];

    printf("Enter plaintext: ");
    fgets(plaintext, 128, stdin);

    printf("Enter key (16 characters): ");
    fgets(key, KEY_LEN+1, stdin);

    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, decrypted_plaintext);
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    return 0;
}

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < plaintext_len; i++, j++) {
        if (j == key_len)
            j = 0;

        ciphertext[i] = (plaintext[i] + key[j]) % 128;
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < ciphertext_len; i++, j++) {
        if (j == key_len)
            j = 0;

        plaintext[i] = (ciphertext[i] - key[j] + 128) % 128;
    }
    plaintext[i] = '\0';
}