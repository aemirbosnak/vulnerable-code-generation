//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

char *key = "secretkey";
char *message = "Hello, World!";
char *result;

void encrypt(char *input) {
    int length = strlen(input);
    result = (char *)malloc(length + 1);
    int i = 0;
    for (i = 0; i < length; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                result[i] = (char)(((int)input[i] - 65 + (int)key[i % SIZE] - 65) % 26 + 65);
            } else {
                result[i] = (char)(((int)input[i] - 97 + (int)key[i % SIZE] - 97) % 26 + 97);
            }
        } else {
            result[i] = input[i];
        }
    }
    result[i] = '\0';
}

void decrypt(char *input) {
    int length = strlen(input);
    result = (char *)malloc(length + 1);
    int i = 0;
    for (i = 0; i < length; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                result[i] = (char)(((int)input[i] - 65 - (int)key[i % SIZE] - 65 + 26) % 26 + 65);
            } else {
                result[i] = (char)(((int)input[i] - 97 - (int)key[i % SIZE] - 97 + 26) % 26 + 97);
            }
        } else {
            result[i] = input[i];
        }
    }
    result[i] = '\0';
}

int main() {
    encrypt(message);
    printf("Encrypted message: %s\n", result);
    decrypt(result);
    printf("Decrypted message: %s\n", result);
    return 0;
}