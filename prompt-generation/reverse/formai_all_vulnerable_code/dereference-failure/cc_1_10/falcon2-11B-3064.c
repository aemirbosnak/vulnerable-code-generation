//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16

void encrypt(char *input, char *output, char *key) {
    int i, j;
    for (i = 0; i < strlen(input); i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            char temp = input[i] + key[j];
            if (temp >= 'a' && temp <= 'z') {
                output[i * BLOCK_SIZE + j] = temp - 'a' + 'A';
            } else if (temp >= 'A' && temp <= 'Z') {
                output[i * BLOCK_SIZE + j] = temp - 'A' + 'a';
            } else {
                output[i * BLOCK_SIZE + j] = temp;
            }
        }
    }
}

void decrypt(char *input, char *output, char *key) {
    int i, j;
    for (i = 0; i < strlen(input); i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            char temp = input[i] - key[j];
            if (temp >= 'a' && temp <= 'z') {
                output[i * BLOCK_SIZE + j] = temp - 'A' + 'a';
            } else if (temp >= 'A' && temp <= 'Z') {
                output[i * BLOCK_SIZE + j] = temp - 'a' + 'A';
            } else {
                output[i * BLOCK_SIZE + j] = temp;
            }
        }
    }
}

int main() {
    char input[] = "Hello, World!";
    char output[strlen(input) + 1];
    char key[] = "encryption";

    encrypt(input, output, key);
    printf("Encrypted: %s\n", output);

    decrypt(output, input, key);
    printf("Decrypted: %s\n", input);

    return 0;
}