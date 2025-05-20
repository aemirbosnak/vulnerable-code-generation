//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int key_len = strlen(key);
    int plaintext_len = strlen(plaintext);
    int ciphertext_len = plaintext_len + key_len - 1;

    char *cipher = (char *)malloc(sizeof(char) * ciphertext_len);

    for (int i = 0; i < ciphertext_len; i++) {
        cipher[i] = (char)(((plaintext[i] - 'a' + key_len) % 26) + 'a');
    }

    printf("Ciphertext: %s\n", cipher);
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int key_len = strlen(key);
    int ciphertext_len = strlen(ciphertext);
    int plaintext_len = ciphertext_len - key_len + 1;

    char *plain = (char *)malloc(sizeof(char) * plaintext_len);

    for (int i = 0; i < plaintext_len; i++) {
        plain[i] = (char)(((ciphertext[i] - 'a' - key_len) % 26) + 'a');
    }

    printf("Plaintext: %s\n", plain);
}

int main() {
    char plaintext[] = "HELLO WORLD";
    char key[] = "KEY";
    char ciphertext[MAX_LENGTH];
    char plaintext2[MAX_LENGTH];

    encrypt(plaintext, key, ciphertext);
    decrypt(ciphertext, key, plaintext2);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted plaintext: %s\n", plaintext2);

    free(ciphertext);
    free(plaintext2);

    return 0;
}