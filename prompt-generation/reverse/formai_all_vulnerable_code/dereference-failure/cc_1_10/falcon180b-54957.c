//Falcon-180B DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void encrypt(char *key, char *plain_text, char *cipher_text) {
    int key_index = 0;
    int i = 0;
    char buffer[BLOCK_SIZE];
    for (i = 0; i < strlen(plain_text); i++) {
        if (i % BLOCK_SIZE == 0) {
            key_index = 0;
        }
        buffer[i % BLOCK_SIZE] = plain_text[i] ^ key[key_index];
        key_index++;
        if (key_index == KEY_SIZE) {
            key_index = 0;
        }
    }
    strcpy(cipher_text, buffer);
}

void decrypt(char *key, char *cipher_text, char *plain_text) {
    int key_index = 0;
    int i = 0;
    char buffer[BLOCK_SIZE];
    for (i = 0; i < strlen(cipher_text); i++) {
        if (i % BLOCK_SIZE == 0) {
            key_index = 0;
        }
        buffer[i % BLOCK_SIZE] = cipher_text[i] ^ key[key_index];
        key_index++;
        if (key_index == KEY_SIZE) {
            key_index = 0;
        }
    }
    strcpy(plain_text, buffer);
}

int main() {
    char key[KEY_SIZE] = "secretkey123";
    char plain_text[100] = "Hello, world! ";
    char cipher_text[100];
    char decrypted_text[100];

    encrypt(key, plain_text, cipher_text);
    printf("Encrypted text: %s\n", cipher_text);

    decrypt(key, cipher_text, decrypted_text);
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}