//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

void generate_key(char key[], int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % SIZE + 'a';
    }
}

void encrypt(char plaintext[], char key[], int key_size, char ciphertext[]) {
    int plaintext_len = strlen(plaintext);
    int ciphertext_len = plaintext_len;

    for (int i = 0; i < plaintext_len; i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[i] = plaintext[i] + key[i % key_size];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
}

void decrypt(char ciphertext[], char key[], int key_size, char plaintext[]) {
    int ciphertext_len = strlen(ciphertext);
    int plaintext_len = ciphertext_len;

    for (int i = 0; i < ciphertext_len; i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[i] = ciphertext[i] - key[i % key_size];
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
}

int main() {
    char plaintext[1000];
    char ciphertext[1000];
    char key[100];

    printf("Enter plaintext: ");
    fgets(plaintext, 1000, stdin);

    printf("Enter key: ");
    fgets(key, 100, stdin);

    int key_size = strlen(key);

    encrypt(plaintext, key, key_size, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    printf("Enter key for decryption: ");
    fgets(key, 100, stdin);

    decrypt(ciphertext, key, strlen(key), plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}