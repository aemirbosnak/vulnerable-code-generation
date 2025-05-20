//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 256
#define KEY 5  // The key for the Caesar cipher

void encrypt(char *plaintext, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        char c = plaintext[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            ciphertext[i] = (c - base + KEY) % 26 + base;
        } else {
            ciphertext[i] = c;  // Non-alphabet characters remain the same
        }
    }
    ciphertext[i] = '\0';  // Null-terminate the string
}

void decrypt(char *ciphertext, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; ++i) {
        char c = ciphertext[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            plaintext[i] = (c - base - KEY + 26) % 26 + base; // Add 26 to handle negative cases
        } else {
            plaintext[i] = c;  // Non-alphabet characters remain the same
        }
    }
    plaintext[i] = '\0';  // Null-terminate the string
}

void print_usage() {
    printf("Usage: \n");
    printf("  ./cipher <encrypt/decrypt> <text>\n");
    printf("Example: \n");
    printf("  ./cipher encrypt \"Hello World!\"\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    char *operation = argv[1];
    char *input = argv[2];
    char output[MAX];

    if (strcmp(operation, "encrypt") == 0) {
        encrypt(input, output);
        printf("Encrypted: %s\n", output);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt(input, output);
        printf("Decrypted: %s\n", output);
    } else {
        print_usage();
        return 1;
    }

    return 0;
}