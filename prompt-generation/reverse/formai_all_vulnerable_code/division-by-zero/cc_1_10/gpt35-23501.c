//FormAI DATASET v1.0 Category: Encryption ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024
#define MAX_OUTPUT_SIZE 2048

void encrypt(char *input, char *key, char *output);
void decrypt(char *input, char *key, char *output);

int main() {
    char input[MAX_INPUT_SIZE];
    char key[MAX_INPUT_SIZE];

    printf("Enter the input string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // remove trailing newline character from input

    printf("Enter the key: ");
    fgets(key, MAX_INPUT_SIZE, stdin);
    key[strcspn(key, "\n")] = 0; // remove trailing newline character from key

    char output[MAX_OUTPUT_SIZE];
    encrypt(input, key, output);

    printf("Encrypted message: %s\n", output);

    char decrypted[MAX_OUTPUT_SIZE];
    decrypt(output, key, decrypted);

    printf("Decrypted message: %s\n", decrypted);

    return 0;
}

void encrypt(char *input, char *key, char *output) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % strlen(key)];
    }
    output[i] = '\0';
}

void decrypt(char *input, char *key, char *output) {
    int i;
    for (i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % strlen(key)];
    }
    output[i] = '\0';
}