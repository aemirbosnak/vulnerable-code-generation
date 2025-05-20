//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_INPUT_LENGTH 1000

void encrypt(char *input, char *key) {
    int i, j;
    char encrypted_input[MAX_INPUT_LENGTH];

    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            encrypted_input[j++] = ((input[i] + key[i % strlen(key)]) % 26) + 'A';
        } else {
            encrypted_input[j++] = input[i];
        }
    }

    encrypted_input[j] = '\0';
    printf("Encrypted Input: %s\n", encrypted_input);
}

void decrypt(char *input, char *key) {
    int i, j;
    char decrypted_input[MAX_INPUT_LENGTH];

    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            decrypted_input[j++] = ((input[i] - key[i % strlen(key)]) % 26) + 'A';
        } else {
            decrypted_input[j++] = input[i];
        }
    }

    decrypted_input[j] = '\0';
    printf("Decrypted Input: %s\n", decrypted_input);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter Input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    printf("Enter Key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);

    encrypt(input, key);
    decrypt(input, key);

    return 0;
}