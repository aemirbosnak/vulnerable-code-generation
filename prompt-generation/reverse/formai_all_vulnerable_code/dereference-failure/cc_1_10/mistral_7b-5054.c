//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define KEY_SIZE 25
#define BLOCK_SIZE 16

char key[KEY_SIZE] = "Ym9vYmFyMjJjZmMxMzRlMjJjNjJj"; // Secret Key
char iv[BLOCK_SIZE] = "1234567890123456"; // Initialization Vector

void xor_key(char* data, int len) {
    for(int i = 0; i < len; i++) {
        data[i] ^= key[i % KEY_SIZE];
    }
}

void shift_left(char* data, int len) {
    char temp = data[0];
    for(int i = 0; i < len-1; i++) {
        data[i] = data[i+1];
    }
    data[len-1] = temp;
}

void encrypt_block(char* data, int len) {
    xor_key(data, len);
    shift_left(data, len);
}

void print_hex(char* data, int len) {
    for(int i = 0; i < len; i++) {
        printf("%.2X ", data[i]);
    }
    printf("\n");
}

void encrypt(char* plaintext, int len) {
    char ciphertext[len];
    for(int i = 0; i < len; i += BLOCK_SIZE) {
        encrypt_block(&plaintext[i], BLOCK_SIZE);
        memcpy(&ciphertext[i], &plaintext[i], BLOCK_SIZE);
        encrypt_block(&plaintext[i], BLOCK_SIZE);
        for(int j = 0; j < BLOCK_SIZE; j++) {
            ciphertext[i+j] ^= iv[j];
        }
    }
    print_hex(ciphertext, len);
}

int main() {
    char plaintext[100] = "The quick brown fox jumps over the lazy dog";
    int len = strlen(plaintext);

    printf("Plaintext: ");
    print_hex(plaintext, len);

    printf("\nEncrypting...\n");
    encrypt(plaintext, len);

    return 0;
}