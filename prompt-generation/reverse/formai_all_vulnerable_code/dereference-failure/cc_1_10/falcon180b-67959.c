//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 256

void generate_key(char *key, int key_size) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~!@#$%^&*()_+{}:\"|\\;',.<>/?`~";
    int i, j;

    for (i = 0; i < key_size; i++) {
        do {
            j = rand() % strlen(charset);
        } while (key[i] == charset[j]);

        key[i] = charset[j];
    }
}

void encrypt(char *message, char *key, char *ciphertext) {
    int i, j;

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            ciphertext[i] = 'A' + ((message[i] - 'A' + key[i % strlen(key)]) % 26);
        } else {
            ciphertext[i] = message[i];
        }
    }
}

void decrypt(char *ciphertext, char *key, char *message) {
    int i, j;

    for (i = 0; ciphertext[i]!= '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            message[i] = 'A' + ((ciphertext[i] - 'A' - key[i % strlen(key)]) % 26 + 26) % 26;
        } else {
            message[i] = ciphertext[i];
        }
    }
}

void test_encrypt_decrypt() {
    char message[] = "The quick brown fox jumps over the lazy dog";
    char key[] = "secretkey123";
    char ciphertext[strlen(message)];
    char decrypted_message[strlen(message)];

    printf("Original message: %s\n", message);

    encrypt(message, key, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    decrypt(ciphertext, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    test_encrypt_decrypt();

    return 0;
}