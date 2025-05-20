//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 100
#define MAX_PLAIN_TEXT_SIZE 1000
#define MAX_CIPHER_TEXT_SIZE 1500

char *generate_key(int key_size) {
    char *key = malloc(key_size * sizeof(char));
    int i;
    for (i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    return key;
}

void encrypt(char *plain_text, char *key, char *cipher_text) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(plain_text); i++) {
        if (isalpha(plain_text[i])) {
            cipher_text[j++] = (char) ((int) plain_text[i] + (int) key[i % strlen(key)] - 65);
        } else {
            cipher_text[j++] = plain_text[i];
        }
    }
    cipher_text[j] = '\0';
}

void decrypt(char *cipher_text, char *key, char *plain_text) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(cipher_text); i++) {
        if (isalpha(cipher_text[i])) {
            plain_text[j++] = (char) ((int) cipher_text[i] - (int) key[i % strlen(key)] + 65);
        } else {
            plain_text[j++] = cipher_text[i];
        }
    }
    plain_text[j] = '\0';
}

int main() {
    char *key = generate_key(10);
    char plain_text[MAX_PLAIN_TEXT_SIZE], cipher_text[MAX_CIPHER_TEXT_SIZE];
    printf("Enter plain text: ");
    scanf("%s", plain_text);
    encrypt(plain_text, key, cipher_text);
    printf("Encrypted text: %s\n", cipher_text);
    decrypt(cipher_text, key, plain_text);
    printf("Decrypted text: %s\n", plain_text);
    return 0;
}