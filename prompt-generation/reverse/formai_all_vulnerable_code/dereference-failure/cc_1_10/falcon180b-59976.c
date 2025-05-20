//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: secure
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
    int ciphertext_len = plaintext_len + KEY_SIZE;

    char* combined_text = malloc(ciphertext_len + 1);
    strcpy(combined_text, plaintext);
    strcpy(combined_text + plaintext_len, key);

    char* result = malloc(ciphertext_len + 1);
    int j = 0;
    for (int i = 0; i < plaintext_len; i++) {
        result[j++] = combined_text[i] ^ key[i % KEY_SIZE];
    }

    strcpy(ciphertext, result);
    free(combined_text);
    free(result);
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int ciphertext_len = strlen(ciphertext);
    int plaintext_len = ciphertext_len - KEY_SIZE;

    char* combined_text = malloc(ciphertext_len + 1);
    strcpy(combined_text, ciphertext);
    strcpy(combined_text + ciphertext_len, key);

    char* result = malloc(plaintext_len + 1);
    int j = 0;
    for (int i = 0; i < ciphertext_len; i++) {
        result[j++] = combined_text[i] ^ key[i % KEY_SIZE];
    }

    strcpy(plaintext, result);
    free(combined_text);
    free(result);
}

int main() {
    char* plaintext = "Hello, world!";
    char* key = "mysecretkey12345";
    char* ciphertext;
    char* decrypted_text;

    generate_key(key);
    encrypt(plaintext, key, ciphertext);
    decrypt(ciphertext, key, decrypted_text);

    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted text: %s\n", decrypted_text);

    free(ciphertext);
    free(decrypted_text);
    return 0;
}