//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: scientific
#include <stdio.h>
#include <string.h>

#define AES_BLOCK_SIZE 16
#define AES_KEY_SIZE 32

void encrypt(char* plaintext, char* key, char* ciphertext) {
    char* iv = "0000000000000000";
    char* cipher = malloc(AES_BLOCK_SIZE + AES_KEY_SIZE + strlen(plaintext) + 1);
    char* state[4] = {0};
    char* subkey = malloc(AES_KEY_SIZE);

    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        state[0][i] = plaintext[i];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < AES_BLOCK_SIZE; j++) {
            state[i][j] = state[i - 1][j];
        }
        state[i][0] ^= state[i - 1][0] ^ key[i * AES_BLOCK_SIZE];
    }

    for (int i = 0; i < strlen(plaintext); i++) {
        state[0][0] ^= plaintext[i];
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < AES_BLOCK_SIZE; k++) {
                state[j + 1][k] = state[j][k];
            }
            state[j + 1][AES_BLOCK_SIZE - 1] ^= state[j][AES_BLOCK_SIZE - 1] ^ key[j * AES_BLOCK_SIZE];
        }
    }

    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        cipher[i] = state[3][i];
    }

    for (int i = AES_BLOCK_SIZE; i < AES_BLOCK_SIZE + AES_KEY_SIZE; i++) {
        cipher[i] = iv[i - AES_BLOCK_SIZE];
    }

    for (int i = AES_BLOCK_SIZE + AES_KEY_SIZE; i < AES_BLOCK_SIZE + AES_KEY_SIZE + strlen(plaintext); i++) {
        cipher[i] = plaintext[i - AES_BLOCK_SIZE - AES_KEY_SIZE];
    }

    cipher[AES_BLOCK_SIZE + AES_KEY_SIZE + strlen(plaintext)] = '\0';

    printf("Ciphertext: %s\n", cipher);

    free(cipher);
    free(state);
    free(subkey);
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    char* iv = "0000000000000000";
    char* plain = malloc(strlen(ciphertext) - AES_KEY_SIZE + 1);
    char* state[4] = {0};
    char* subkey = malloc(AES_KEY_SIZE);

    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        state[0][i] = ciphertext[i];
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < AES_BLOCK_SIZE; j++) {
            state[i][j] = state[i - 1][j];
        }
        state[i][0] ^= state[i - 1][0] ^ key[i * AES_BLOCK_SIZE];
    }

    for (int i = 0; i < strlen(ciphertext) - AES_KEY_SIZE; i++) {
        state[0][0] ^= ciphertext[i];
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < AES_BLOCK_SIZE; k++) {
                state[j + 1][k] = state[j][k];
            }
            state[j + 1][AES_BLOCK_SIZE - 1] ^= state[j][AES_BLOCK_SIZE - 1] ^ key[j * AES_BLOCK_SIZE];
        }
    }

    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        plain[i] = state[3][i];
    }

    for (int i = AES_BLOCK_SIZE; i < AES_BLOCK_SIZE + AES_KEY_SIZE; i++) {
        plain[i] = iv[i - AES_BLOCK_SIZE];
    }

    for (int i = AES_BLOCK_SIZE + AES_KEY_SIZE; i < AES_BLOCK_SIZE + AES_KEY_SIZE + strlen(ciphertext); i++) {
        plain[i] = ciphertext[i - AES_BLOCK_SIZE - AES_KEY_SIZE];
    }

    plain[strlen(ciphertext) - AES_KEY_SIZE] = '\0';

    printf("Plaintext: %s\n", plain);

    free(plain);
    free(state);
    free(subkey);
}

int main() {
    char plaintext[] = "Hello, World!";
    char key[] = "0123456789abcdef";
    char ciphertext[strlen(plaintext) + 1];

    encrypt(plaintext, key, ciphertext);
    decrypt(ciphertext, key, plaintext);

    return 0;
}