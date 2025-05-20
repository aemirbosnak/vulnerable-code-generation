//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_LENGTH 25
#define BLOCK_SIZE 8
#define ALPHABET_SIZE 26
#define SECRET_KEY "mysecretkey123!"

typedef struct {
    char key[KEY_LENGTH];
    char iv[BLOCK_SIZE];
} encryption_params;

void set_params(encryption_params *params) {
    strcpy(params->key, SECRET_KEY);
    for (int i = 0; i < BLOCK_SIZE; i++) {
        params->iv[i] = (char)rand() % 256;
    }
}

void encrypt_char(char *plaintext, char *ciphertext, char key, char iv) {
    int index = (islower(*plaintext) ? *plaintext - 97 : *plaintext - 65);
    *ciphertext = (char)((index + (index << 2) + key + iv) % ALPHABET_SIZE + 65);
}

void encrypt_block(char *plaintext, char *ciphertext, encryption_params params) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        encrypt_char(plaintext + i, ciphertext + i, params.key[i % KEY_LENGTH], params.iv[i]);
    }
}

int main() {
    srand(time(NULL));
    encryption_params params;
    set_params(&params);

    char user_input[100];
    printf("Enter text to encrypt: ");
    scanf("%s", user_input);

    int len = strlen(user_input);
    char ciphertext[len];
    memset(ciphertext, 0, len);

    int blocks = len / BLOCK_SIZE + (len % BLOCK_SIZE != 0);
    for (int i = 0; i < blocks; i++) {
        int block_len = i < blocks - 1 ? BLOCK_SIZE : len % BLOCK_SIZE;
        encrypt_block(user_input + i * BLOCK_SIZE, ciphertext + i * BLOCK_SIZE, params);
    }

    printf("Encrypted text: ");
    for (int i = 0; i < len; i++) {
        putchar(ciphertext[i]);
    }
    printf("\n");

    return 0;
}