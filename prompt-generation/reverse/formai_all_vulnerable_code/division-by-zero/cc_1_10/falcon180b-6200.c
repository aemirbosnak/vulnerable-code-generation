//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_BLOCK_SIZE 16

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    int mode;
} cipher_t;

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(cipher_t *cipher, char *input, char *output) {
    for (int i = 0; i < strlen(input); i++) {
        char c = toupper(input[i]);
        char k = toupper(cipher->key[i % cipher->key_size]);
        int shift = (k - 'A') % 26;
        if (isalpha(c)) {
            if (isupper(c)) {
                output[i] = (c + shift - 'A') % 26 + 'A';
            } else {
                output[i] = (c + shift - 'a') % 26 + 'a';
            }
        } else {
            output[i] = c;
        }
    }
    output[strlen(input)] = '\0';
}

void decrypt(cipher_t *cipher, char *input, char *output) {
    for (int i = 0; i < strlen(input); i++) {
        char c = toupper(input[i]);
        char k = toupper(cipher->key[i % cipher->key_size]);
        int shift = (k - 'A') % 26;
        if (isalpha(c)) {
            if (isupper(c)) {
                output[i] = (c - shift + 26) % 26 + 'A';
            } else {
                output[i] = (c - shift + 26) % 26 + 'a';
            }
        } else {
            output[i] = c;
        }
    }
    output[strlen(input)] = '\0';
}

int main() {
    cipher_t cipher;
    generate_key(cipher.key, 16);
    char input[] = "Hello, World!";
    char output[MAX_BLOCK_SIZE];
    cipher.mode = 0;
    encrypt(&cipher, input, output);
    printf("Encrypted message: %s\n", output);
    cipher.mode = 1;
    decrypt(&cipher, output, output);
    printf("Decrypted message: %s\n", output);
    return 0;
}