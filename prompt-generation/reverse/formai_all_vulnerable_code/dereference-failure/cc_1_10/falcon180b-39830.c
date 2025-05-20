//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int plaintext_len = strlen(plaintext);
    int ciphertext_len = plaintext_len + 1;
    char* plaintext_ptr = plaintext;
    char* ciphertext_ptr = ciphertext;

    while (plaintext_len > 0) {
        int block_len = (plaintext_len > BLOCK_SIZE)? BLOCK_SIZE : plaintext_len;
        int i;
        for (i = 0; i < block_len; i++) {
            ciphertext_ptr[i] = plaintext_ptr[i] ^ key[i % KEY_SIZE];
        }
        plaintext_ptr += block_len;
        ciphertext_ptr += block_len;
        plaintext_len -= block_len;
    }
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int ciphertext_len = strlen(ciphertext);
    int plaintext_len = ciphertext_len - 1;
    char* ciphertext_ptr = ciphertext;
    char* plaintext_ptr = plaintext;

    while (ciphertext_len > 0) {
        int block_len = (ciphertext_len > BLOCK_SIZE)? BLOCK_SIZE : ciphertext_len;
        int i;
        for (i = 0; i < block_len; i++) {
            plaintext_ptr[i] = ciphertext_ptr[i] ^ key[i % KEY_SIZE];
        }
        ciphertext_ptr += block_len;
        plaintext_ptr += block_len;
        ciphertext_len -= block_len;
    }
}

int main() {
    char plaintext[] = "Hello, world!";
    char key[KEY_SIZE];
    generate_key(key);
    char ciphertext[strlen(plaintext) + 1];
    encrypt(plaintext, key, ciphertext);
    char decrypted_text[strlen(plaintext) + 1];
    decrypt(ciphertext, key, decrypted_text);
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted text: %s\n", decrypted_text);
    return 0;
}