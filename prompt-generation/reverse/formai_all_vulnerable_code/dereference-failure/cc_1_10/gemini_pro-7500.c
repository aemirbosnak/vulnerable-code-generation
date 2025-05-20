//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "helloworld"
#define IV "12345678"

void encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *iv) {
    int i, j, k;
    unsigned char temp;

    for (i = 0; i < strlen(plaintext); i++) {
        k = i % strlen(key);
        temp = plaintext[i];
        plaintext[i] = plaintext[i] ^ key[k];
        key[k] = temp;
    }

    for (i = 0; i < strlen(plaintext); i++) {
        j = i % strlen(iv);
        temp = plaintext[i];
        plaintext[i] = plaintext[i] ^ iv[j];
        iv[j] = temp;
    }
}

void decrypt(unsigned char *ciphertext, unsigned char *key, unsigned char *iv) {
    int i, j, k;
    unsigned char temp;

    for (i = strlen(ciphertext) - 1; i >= 0; i--) {
        j = i % strlen(iv);
        temp = ciphertext[i];
        ciphertext[i] = ciphertext[i] ^ iv[j];
        iv[j] = temp;
    }

    for (i = strlen(ciphertext) - 1; i >= 0; i--) {
        k = i % strlen(key);
        temp = ciphertext[i];
        ciphertext[i] = ciphertext[i] ^ key[k];
        key[k] = temp;
    }
}

int main() {
    unsigned char plaintext[] = "Hello world!";
    unsigned char ciphertext[strlen(plaintext)];

    encrypt(plaintext, KEY, IV);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, KEY, IV);

    printf("Plaintext: %s\n", plaintext);

    return 0;
}