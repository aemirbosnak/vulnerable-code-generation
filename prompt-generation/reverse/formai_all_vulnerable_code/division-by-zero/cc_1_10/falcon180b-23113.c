//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 64
#define MAX_INPUT_SIZE 1024
#define MAX_OUTPUT_SIZE 1024

void generate_key(char *key, int key_size) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < key_size; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
}

void encrypt(char *key, int key_size, char *input, char *output) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % key_size];
    }
}

void decrypt(char *key, int key_size, char *input, char *output) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % key_size];
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_OUTPUT_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter the message to encrypt: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    generate_key(key, strlen(key));

    encrypt(key, strlen(key), input, output);

    printf("Encrypted message: %s\n", output);

    decrypt(key, strlen(key), output, input);

    printf("Decrypted message: %s\n", input);

    return 0;
}