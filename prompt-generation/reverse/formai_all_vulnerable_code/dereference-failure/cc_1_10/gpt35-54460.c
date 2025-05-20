//FormAI DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Configurable parameters */
#define KEY "mysecretkey"
#define BLOCK_SIZE 16

/* Function to initialize the key */
void initialize_key(unsigned char *key) {
    int i;
    for (i = 0; i < strlen(KEY); i++) {
        key[i] = KEY[i];
    }
}

/* Function to perform XOR operation */ 
void perform_xor(unsigned char *input, unsigned char *output, unsigned char *key) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        output[i] = input[i] ^ key[i];
    }
}

/* Function to perform encryption */
void encrypt(unsigned char *input, unsigned char *output) {
    unsigned char key[BLOCK_SIZE];
    initialize_key(key);
    int i, j = 0;
    for (i = 0; i < strlen(input); i += BLOCK_SIZE) {
        unsigned char block[BLOCK_SIZE];
        memcpy(block, &input[i], BLOCK_SIZE);
        perform_xor(block, &output[i], key);
        /* Rotate the key */
        unsigned char temp = key[0];
        for (j = 1; j < BLOCK_SIZE; j++) {
            key[j - 1] = key[j];
        }
        key[BLOCK_SIZE - 1] = temp;
    }
}

/* Function to perform decryption */
void decrypt(unsigned char *input, unsigned char *output) {
    unsigned char key[BLOCK_SIZE];
    initialize_key(key);
    int i, j = 0;
    for (i = 0; i < strlen(input); i += BLOCK_SIZE) {
        unsigned char block[BLOCK_SIZE];
        memcpy(block, &input[i], BLOCK_SIZE);
        perform_xor(block, &output[i], key);
        /* Rotate the key */
        unsigned char temp = key[0];
        for (j = 1; j < BLOCK_SIZE; j++) {
            key[j - 1] = key[j];
        }
        key[BLOCK_SIZE - 1] = temp;
    }
}

/* Main function */
int main() {
    unsigned char input[] = "This is a secret message";
    int input_size = strlen(input);
    unsigned char encrypted[input_size];
    encrypt(input, encrypted);
    printf("Encrypted message: %s\n", encrypted);
    unsigned char decrypted[input_size];
    decrypt(encrypted, decrypted);
    printf("Decrypted message: %s\n", decrypted);
    return 0;
}